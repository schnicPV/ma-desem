#ifndef FACTORY_H
#define FACTORY_H

class Button;
class ButtonManager;
class Blinker;
class TestBench;

class Factory
{
public:
	void initialize();
	~Factory();
	void buildApplication();
	ButtonManager * buttonManager();
	Button * button();
	static Blinker * blinker();
	static TestBench * testBench();
private:
	Button * pButton;
	ButtonManager * pManager;
};

#endif // FACTORY_H
