#pragma once
#include <string>
#include "screen.h"

class interface
{
    private:
    enum MODE { MENU = 1, BUILD = 2, SIMULATE = 3 };
    MODE modes;
    int mouseControl[2];
    screen* mainScreen;
    
    void updateMENU();
    void updateBUILD();
    void updateSIMULATE();

    void update();
    void getInput();

   

    public:
    void start();
    interface();
    ~interface();
    

    /*
	switching between modes
	the menu --> drawMenu --> uses menuShapesClass to generate appropriate sized menus

	the sandbox(to build first( 	   --> yea..

	the raid (ya mega milk)

    */
   



};
