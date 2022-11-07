#pragma once
#include <ncurses.h>

#include<iostream>
#include<deque>
#include"troops.h"
#include"defenses.h"
#include"shapes.h"

#include"resources.h"

class screen
{
        private:
        MEVENT event;
	
        //How does this work lol
	std::deque<shapes*> shapeDraw;
	std::deque<troops*> troopDraw;
	std::deque<defenses*> defensesDraw;

        public:
	int dimensionX;
	int dimensionY;
        screen();
        ~screen();

        void initialize();

	bool recieveMouse();
	
	int getEventX();
	int getEventY();
	
	void addShape(shapes* shaper);
	void addTroop(troops* trooper);
	void addDefenses(defenses* defense);
	
	void cleanShapes();
	void cleanTroops();
	void cleanDefenses();
	void cleanAll();
	
	void removeShapes(int callerTage);
	void removeDefense(int callerTag);
	void removeTrooper(int callerTag);
	/*
	this requires some back checks,
	specifically using deque to erase specfic objects based off their unique ID's, like iv seen java do

	*/
	//main Draw
	/*
		lets keep main troops
		and defenses seperate
		from the drawing tab 
		so it has less things to 
		generally draw
	*/
	int getDimensionX();
	int getDimensionY();


	void clean();


	void draw(int someType);


	







};
