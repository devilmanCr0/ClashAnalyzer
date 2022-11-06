#pragma once
#include <vector>
#include <string>

class pixel
{
	protected:
	struct pixa
	{
		int x;
		int y;
		char drawingChar;
	};



	int relateCoords[2];
	std::string color;
	std::vector<pixa> coords;

	public:
	
	pixel(int x, int y)
	{
	   this->relateCoords[0] = x;
	   this->relateCoords[1] = y;
	   	
	}

	~pixel()
	{
		coords.clear();
	}
	
	
	int getSize()
	{
		return coords.size();
	}

	int getRelativeX(int i)
	{
		//removed absolute
		return relateCoords[1] - coords.at(i).x;
	}
	
	int getRelativeY(int i)
	{
		return relateCoords[0] - coords.at(i).y;

	}
	
	char getChar(int i)
	{
		
		return coords.at(i).drawingChar;
	}
	
	std::string getColor()
	{
		return color;
	}
protected:
	void addPixel(int x, int y, char symbol)
	{
		pixa newPixel = pixa{x, y, symbol};
		this->coords.push_back(newPixel);
	}

	

	virtual void initializePixel()
	{

	}

};
