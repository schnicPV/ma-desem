#ifndef BUTTONMANAGER_H
#define BUTTONMANAGER_H

class ButtonManager
{
public:
	int state;
	ButtonManager();
	void checkButtonState();
	void testMe();
	
private:
	void pressed();
	void released();
};

#endif // BUTTONMANAGER_H
