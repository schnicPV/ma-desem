#ifndef BUTTON_INTERFACE_H
#define BUTTON_INTERFACE_H

enum BState
{
	PRESSED,
	RELEASED
};

class ToButton
{
public:
	virtual BState checkButtonState() = 0;

public:
	virtual ~ToButton() = default;

};

class ToButtonManager
{
public:
	virtual void pressed() = 0;
	virtual void released() = 0;

public:
	virtual ~ToButtonManager() = default;
};

#endif // BUTTON_INTERFACE_H
