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
	//MAINSCREENINIT FOR NCURSES
	initscr();
	
        mainScreen = new screen();

	//needs to be slightly adjusted yes
	this->mDIMENSIONX+=mainScreen->getDimensionX()/2;
	this->mDIMENSIONY+=mainScreen->getDimensionY()/2;
  	
	while(1)
	{
		update();
		//storing MODE need
		//analyze mode in the distant future	





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
		
		createMenu();
	}
	//see if they complain here
	mainScreen->draw(MENU);

	if(getInput())
	{
		modes = static_cast<MODE>(findButton());

		mainScreen->cleanShapes();
		buttons.clear();
		bswitch = true;		
	}
	
	
}

int interface::findButton()
{
	for(button BU: buttons)
	{
			std::cout << " THE BUTTON COORDS AS " << BU.x << " " <<  BU.y << " " << BU.w <<  " "<< BU.h << std::endl;
			std::cout << " THE MOUSE COORDS AREEEEEEE " << mouseControl[0] << " " << mouseControl[1] << std::endl;
			

			if(mouseControl[0] <= BU.x && mouseControl[1] <= BU.y && mouseControl[0] >= BU.w && mouseControl[1] >= BU.h) 
			{


				if(BU.MO == "BUILD")
				{
					return BUILD;
				}
				else if(BU.MO == "SIMULATE")
				{	
					return SIMULATE;
				} 
				
			}

	}
	return MENU;
}


void interface::updateBUILD()
{
	//std::cout << "IT WORKED" <<std::endl;
	
	/*
		use getyx() to keep track of where the mouse is
		we'll be using hotkeys to 
		1) spawn the defense
		2) perhaps implement a tick rate
		3) use the mouse coords of the cursor to 
		update where the defense's position is
		--check the comment below on further implementation on how these objects will interact
		
		4) click on where we will place the dammn thing
		5) attach the entity with the latest mouse coord


	*/




		//mainScreen.draw(2);
		//mainScreen.draw(1);

}

void interface::updateSIMULATE()
{
	/*
	We'll have a time sync initialized here
	We'll decide what troops should be added
	for now I think we should stick with simple
	hotkeys and we'll be adding one kind of troop 
	lol
	
	We're going to enter a while loop when the simulation actually starts (enabled by hotkey for now)
	have the option to pause and stop the simulation



	this needs to follow a tick format
		
		this mode will allow to add troops (should be during and before the simulation)
		
		psuedo code for the tick updator

		MS_PER_TICK = 1000 / 60  // the time one game-tick represents	
		PROCESSED_TIME = currentTimeInMs();     

		while game is running
	       		 drawFrame()
			while (PROCESSED_TIME + MS_PER_TICK) < currentTimeInMs()
			updateentities(tick) <-- this will be handled by mainscreen
						 will add an updateTick function
						 to go through all troops and defenses in deque
					
			PROCESSED_TIME += MS_PER_TICK
		

	*/


}

void interface::createMenu()
{
	shapes* thesquare = new square(mDIMENSIONX, mDIMENSIONY, mHEIGHT, mLENGTH);
	mainScreen->addShape(thesquare);

	int buttonX;
	int buttonY;
	int buttonW = 23;
	int buttonH = 2;

	//DO NOTE: draw mechanism draws everything backwards, yikies
	
	for(int i = 0; i < labels.size(); i++)
	{
		buttonX = mDIMENSIONX - 8;
		buttonY = mDIMENSIONY - 17 + (i*4);
		

		button bbCoord = button{ buttonX, buttonY, buttonX-buttonW, buttonY-buttonH, labels.at(i)};


		shapes* buttonT = new square(buttonX, buttonY, buttonH, buttonW);
		shapes* labelT = new text(buttonX+2, buttonY+1, labels.at(i));

		buttons.push_back(bbCoord);
		mainScreen->addShape(buttonT);
		mainScreen->addShape(labelT);

	}
}




bool interface::getInput()
{
	if(mainScreen->recieveMouse())
	{
		mouseControl[0]=mainScreen->getEventX();
		mouseControl[1]=mainScreen->getEventY();
		return true;
	}
	return false;
}
