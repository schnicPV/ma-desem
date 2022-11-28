#pragma once
#include <stdint.h>
#include <cstring>
#include <new>
#include <assert.h>

/**
 * @ingroup pool
 * @brief Template to generate a class that can store objects of another class either inside a dynamically allocated
 * 		  memory region or inside a given memory block.
 *
 * It implements a simple reference count system that lets the objects be easily shared. Note that the reference count
 * is manually handled.
 */
template <typename T>
class ObjectPool
{
public:
	/**
	 * @brief Creates a new object pool with the given number of objects preallocated either at the given
	 * 		  memory region (the memory region pointer will be incremented by the size needed to store all
	 * 		  data) or if the pointer to the memory pointer is NULL, the template class uses malloc to
	 * 		  allocate memory for his content.
	 *
	 * @param numberOfObjectsToPreallocate 	The number of objects to hold.
	 * @param memory 						Pointer to the memory pointer or NULL if the template should use
	 * 										malloc (new) to allocate memory.
	 */
	explicit ObjectPool( size_t numberOfObjectsToPreallocate , uint8_t * * memory = NULL )
	{
		// If the objects should be placed into a given memory region.
		if ( memory )
		{
			// Create the object pool.
			_objectPool = new( static_cast<void *>( *memory ) ) T[numberOfObjectsToPreallocate];
			*memory += numberOfObjectsToPreallocate * sizeof( T );

			// Create the reference count variables.
			_referenceCounts = new( static_cast<void *>( *memory ) ) uint8_t[numberOfObjectsToPreallocate];
			*memory += numberOfObjectsToPreallocate;

			// Remember that we should not delete the memory afterwards.
			_dynamicMemoryUsed = false;
		}

		// Use systems malloc()/new() functions to allocate memory.
		else
		{
			// Create the object pool.
			_objectPool = new T[numberOfObjectsToPreallocate];

			// Create the reference count variables.
			_referenceCounts = new uint8_t[numberOfObjectsToPreallocate];

			// Remember that we should delete the memory afterwards.s
			_dynamicMemoryUsed = true;
		}

		// Initialize the reference count and total free objects variables on success.
		assert( _objectPool && _referenceCounts );
		if ( _objectPool && _referenceCounts )
		{
			 memset( _referenceCounts , 0 , numberOfObjectsToPreallocate );
			 _objectCount = numberOfObjectsToPreallocate;
			 _availableObjectCount = numberOfObjectsToPreallocate;
		}

		// Something went wrong, so we can not offer any object.
		else
		{
			if ( _objectPool ) delete[] _objectPool;
			if ( _referenceCounts ) delete[] _referenceCounts;
			_dynamicMemoryUsed = false;
			_objectCount = 0;
			_availableObjectCount = 0;
		}
	}

	/**
	 * @brief Releases the resources used by this pool in the case the memory was allocated dynamically.
	 */
	virtual ~ObjectPool()
	{
		// We have to release memory if it was allocated using new().
		if ( _dynamicMemoryUsed )
		{
			if ( _objectPool ) delete[] _objectPool;
			if ( _referenceCounts ) delete[] _referenceCounts;
		}
	}

	/**
	 * @brief Returns the total number of objects that this pool contains.
	 *
	 * @return Number of objects in pool.
	 */
	size_t objectCount() const
	{
		return _objectCount;
	}

	/**
	 * @brief Returns the number of objects actually available.
	 *
	 * @return Number of available objects in pool.
	 */
	size_t availableObjectCount() const
	{
		return _availableObjectCount;
	}

	/**
	 * @brief Tries to allocate a new object from the pool and returns a pointer to that object.
	 *
	 * If no more objects are left inside the pool, the method returns a NULL pointer.
	 *
	 * @return Pointer to an object or NULL in the case that there are no more objects left inside the pool.
	 */
	T * allocate()
	{
		// Do we have objects left?
		if ( _availableObjectCount )
		{
			// Search first available object and return it.
			for ( unsigned int i = 0 ; i < _objectCount ; ++i )
			{
				if ( _referenceCounts[i] == 0 )
				{
					_referenceCounts[i] = 1;
					_availableObjectCount--;
					return &_objectPool[i];
				}
			}
		}

		// We did not found any unused frame anymore, return NULL pointer.
		assert( false );
		return NULL;
	}

	/**
	 * @brief Increments the reference count variable for the given object.
	 *
	 * @param object Pointer to the object for which the reference count should incremented.
	 */
	void retain( T * object )
	{
		// Calculate index from pointer value.
		int index = ( reinterpret_cast<uint8_t *>( object ) -
					  reinterpret_cast<uint8_t *>( _objectPool ) ) / sizeof( T );

		// If index is reasonable, increment the reference count for that object.
		if ( index >= 0 && index < static_cast<int>( _objectCount ) )
		{
			_referenceCounts[index] += 1;

			// Ensure that we do not have more references as we can count.
			assert( _referenceCounts[index] < 255 );
		}
	}

	/**
	 * @brief Decrements the reference count variable for the given object and gives it back to the pool if the reference
	 *  	  count reaches 0.
	 *
	 * @param object Pointer to the object for which the reference count should decremented.
	 */
	void release( T * object )
	{
		// Calculate index from pointer value.
		int index = ( reinterpret_cast<uint8_t *>( object ) -
				      reinterpret_cast<uint8_t *>( _objectPool ) ) / sizeof( T );

		// If index is reasonable, decrement the reference count for that object.
		if ( index >= 0 && index < static_cast<int>( _objectCount ) )
		{
			_referenceCounts[index] -= 1;

			// If the last released the object, increment the number of available objects.
			if ( !_referenceCounts[index] ) _availableObjectCount++;
		}
	}

private:
	T * _objectPool;				// Pointer to the object pool.
	uint8_t * _referenceCounts;		// Pointer to the reference count array.
	size_t _objectCount;			// Number of total objects.
	size_t _availableObjectCount;	// Number of objects actually available.
	bool _dynamicMemoryUsed;		// Were the arrays made with new()?
};
