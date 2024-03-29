#pragma once
#include <string>
#include "screen.h"

class interface
{
    private:
    enum MODE { MENU = 1, BUILD = 2, SIMULATE = 3 };
    struct button { int x; int y; int w; int h; std::string MO; };
    MODE modes;
    int mouseControl[2];
    screen* mainScreen;
    
    void updateMENU();
    void updateBUILD();
    void updateSIMULATE();

    void update();
    bool getInput();

    int mDIMENSIONX = 17;
    int mDIMENSIONY = 5;
    int mLENGTH = 40;
    int mHEIGHT = 20;
    
 
    std::vector<std::string> labels = {"BUILD", "SIMULATE"};
    std::vector<button> buttons;

    void createMenu();
    int findButton();
    

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
