#
#include "button.h"

Button::~Button()
{

}

void Button::initialize()
{
	state = RELEASED;
	pManager = nullptr;
}
void Button::initializeRelations()
{

}

void Button::setButtonManager(ToButtonManager * p)
{
	pManager = p;
}

BState Button::checkButtonState()
{
	return state;
}

void Button::testMe()
{
	if (state==PRESSED)
	{
		state = RELEASED;
		if (pManager)
		{
			pManager->released();
		}
	}
	else
	{
		state = PRESSED;
		if (pManager)
		{
			pManager->pressed();
		}
	}
}
