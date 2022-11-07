#pragma once
#include "shapes.h"

class text : public shapes
{
	private:
	std::string theText;

	public:	
	text(int x, int y, std::string texty) : shapes(x, y)
	{
		this->theText = texty;
		this->initializePixel();
	}

	
	void initializePixel() override
	{
		int i = theText.size();
		for(char letter: theText)
		{
			addPixel(0, i, letter);
			i--;
		}
		
	}




};
