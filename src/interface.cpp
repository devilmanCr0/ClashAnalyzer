#include "interface.h"

interface::interface()
{
        this->modes = MENU;
	this->mouseControl[0] = 0;
	this->mouseControl[1] = 0;
}

interface::~interface()
{
	delete mainScreen;
	mainScreen = NULL;
}

void interface::start()
{
	initscr();
	
        mainScreen = new screen();	
  	
	while(1)
	{
		update();
		//storing MODE need
		





	}

}

void interface::update()
{
	switch(modes)
	{	
		case MENU:
			updateMENU();
		break;

		case BUILD:
			updateBUILD();
		break;

		case SIMULATE:
			updateSIMULATE();
		break;

		default:

		this->modes = MENU;

	}


	//calling getInput whenever
	//i think this will diverge to
	//MODES

}

void interface::updateMENU()
{
	static bool bswitch { true };
	if(bswitch)
	{
		bswitch = false;
		shapes* thesquare = new square(30/*mainScreen->getDimensionX()*/, 20, 10, 10);

		//thought it was x,y?

		mainScreen->addShape(thesquare);		
	}
	//see if they complain here
	mainScreen->draw(MENU);

	getInput();
	



	//mainScreen.draw(1);


}

void interface::updateBUILD()
{
		//mainScreen.draw(2);
		//mainScreen.draw(1);

}

void interface::updateSIMULATE()
{
		//mainScreen.draw(3);
		//mainScreen.draw(2);



}


void interface::getInput()
{
	if(mainScreen->recieveMouse())
	{
		mouseControl[0]=mainScreen->getEventX();
		mouseControl[0]=mainScreen->getEventY();
	}
}
