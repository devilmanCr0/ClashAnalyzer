#include "screen.h"


screen::screen()
{
   //std::cout <<"CreatedScree" <<std::endl;
   initialize();
}

screen::~screen()
{
   //maybe more cleanup later
   endwin();
}


void screen::initialize()
{
       // std::cout <<" hello loser"<<std::endl;
	noecho();
   	clear();
   	getmaxyx(stdscr, this->dimensionY, this->dimensionX);
	curs_set(0);

   	keypad(stdscr, TRUE);

   	mousemask( BUTTON1_PRESSED, NULL);


       // std::cout <<"exiting" <<std::endl;	
}



bool screen::recieveMouse()
{
	int mouseUpdate = getch();
	
	if(mouseUpdate == KEY_MOUSE)
	{	
		if(getmouse(&this->event) == OK)
		{
		 	if(event.bstate & BUTTON1_PRESSED)
			{
				//Wanted to do {{event.y, event.x}}i
				return true;
			}
		
		}
	}
	return false;
}

int screen::getEventX()
{
	return event.x;
}

int screen::getEventY()
{
	return event.y;
}

void screen::addShape(shapes* shaper)
{
	shapeDraw.push_back(shaper);
}

void screen::addTroop(troops* trooper)
{
	troopDraw.push_back(trooper);
}


void screen::addDefenses(defenses* defense)
{
	defensesDraw.push_back(defense);
}

void screen::cleanShapes()
{
	shapeDraw.clear();
}

void screen::cleanTroops()
{
	troopDraw.clear();
}

void screen::cleanDefenses()
{
	defensesDraw.clear();
}

void screen::cleanAll()
{
	cleanTroops();
	cleanDefenses();
}

void screen::removeShapes(int callerTag)
{

}

void screen::removeDefense(int callerTag)
{

}


void screen::removeTrooper(int callerTag)
{
        //i=mydeque.begin()
	//i++
	//if *i->id == callerTag
	//mydeque.erase(i)

}

int screen::getDimensionX()
{
	return dimensionX;
}

int screen::getDimensionY()
{
	return dimensionY;
}



void screen::clean()
{
	clear();

}


void screen::draw(int someType)
{
	switch(someType)
	{
		case 1:
			for(shapes* shape: shapeDraw)
			{
				
				for(int i = 0; i < shape->getSize(); i++)
				{
					//std::cout << shape->getRelativeX(i) << " " << shape->getRelativeY(i);
					mvaddch(shape->getRelativeX(i),shape->getRelativeY(i), shape->getChar(i));	
					refresh();
				}
				
			}

		break;



	}

}
