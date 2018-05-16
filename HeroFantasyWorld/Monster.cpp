#include<iostream>
#include "Monster.h"
#include <stdlib.h>
#include <time.h>
#include "Map.h"
#include <memory>

using namespace std;


Monster::Monster()
{
	monsterHP = rand() % 5 + 3;	
	monsterAtkDamage = 3;
}


Monster::~Monster()
{
}

void Monster::setMonsterHP()
{


}

void Monster::setMonsterPosition(int x , int y, Map &m)
{
	monsterPositionX = x;
	monsterPositionY = y;
	m.mapGrid[monsterPositionY][monsterPositionX] = 2;
}

void Monster::setMonsterID(int monID)
{
	monsterID = monID;
}