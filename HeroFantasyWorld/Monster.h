#pragma once
#include "Map.h"
class Monster
{
public:
	Monster();
	~Monster();
	int monsterHP;
	int monsterAtkDamage;
	int monsterPositionX;
	int monsterPositionY;
	int MaxMonsterNumber = 10;
	int monsterID;
	void setMonsterHP();
	void setMonsterPosition(int x , int y, Map &m);
	void setMonsterID(int monID);
	
};

