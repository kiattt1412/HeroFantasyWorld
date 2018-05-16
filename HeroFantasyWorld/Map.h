#pragma once
class Map
{
public:
	Map();
	~Map();
	void printMap();	
	int worldWidth = 32, worldHeight = 32;
	int mapGrid[32][32] = { 0 };
};

