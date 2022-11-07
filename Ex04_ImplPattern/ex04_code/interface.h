#ifndef INTERFACE_H
#define INTERFACE_H

enum BState
{
	PRESSED,
	RELEASED
};

class ToButton
{
public:
	virtual BState checkButtonState() = 0;
};

class ToButtonManager
{
public:
	virtual void pressed() = 0;
	virtual void released() = 0;
};

#endif // INTERFACE_H
