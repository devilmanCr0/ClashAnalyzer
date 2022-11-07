#pragma once
#include "shapes.h"

class square : public shapes
{
	private:
	int dimensionX;
	int dimensionY;

	

	public:
	square(int x, int y): shapes(x, y)
	{
		this->dimensionX = 0;
		this->dimensionY = 0;
		initializePixel();
	}

	square(int x, int y, int width, int height): shapes(x, y)
	{
		this->dimensionX = width;
		this->dimensionY = height;
		this->initializePixel();
	}


	void initializePixel() override
	{
		for(int i=0; i < dimensionY; i++)
		{
			for(int k = 0; k < dimensionX; k++)
			{
				if(i==0 || i == dimensionY-1)
				{
					addPixel(k, i, '|');	
				} 
				else if(k==0)
				{
					addPixel(k, i, '_');
				} 
				else if(k == dimensionX -1)
				{
					addPixel(k, i, '-');
				}

			}
		}

	}






};

