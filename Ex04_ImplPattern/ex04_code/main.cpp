
#include "xf/xf.h"
#include "factory.h"

int main(int argc, char * argv[])
{
	XF_PREPARE;
	XF::init();

	Factory factory;

	factory.initialize();
	factory.buildApplication();

	XF::start();

	return 0;
}
