#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include "Hero.h"
#include "Map.h"
#include "Monster.h"
#include <crtdbg.h>
#include <memory>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <cstdlib>


#define _CRTDBG_MAP_ALLOC

using namespace std;



char userInput;
void InitGame();
void PrintInfo();
void gamePlay();
auto hero = std::make_shared<Hero>();
auto map = std::make_shared<Map>();
auto monster = std::make_shared<Monster>();
std::vector<std::shared_ptr<Monster>> monsterStore;
int playround = 1;


int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	InitGame();
	map->printMap();
	PrintInfo();
	gamePlay();
	//getchar();
	return 0;
}

void InitGame()
{
	int locationX, locationY;
	srand(time(NULL));
	hero->setHeroPosition(1,1,*map);

	for (int i = 0; i < monster->MaxMonsterNumber; i++)
	{
		auto mon = std::make_shared<Monster>();
		monsterStore.push_back(mon);
		
			monsterStore[i]->setMonsterID(i);


			bool finishPlacedMonster = false;
			while (!finishPlacedMonster)
			{
				locationX = rand() % 30 + 1;
				locationY = rand() % 30 + 1;

				if (map->mapGrid[locationY][locationX] == 0)
				{
					finishPlacedMonster = true;
				}
			}

			monsterStore[i]->setMonsterPosition(locationX, locationY, *map);
	}

}

void PrintInfo()
{
	cout << "Hero HP : " << hero->heroHP << endl;
	for (int i = 0; i < monster->MaxMonsterNumber; i++)
	{
		if (monsterStore[i] != NULL)
		{
			cout << "Monster " << i << " HP :" << monsterStore[i]->monsterHP << endl;
		}
	}
}

void gamePlay()
{
	if (playround > 1)
	{
		std::system("cls");
		map->printMap();
		PrintInfo();
	}
	while (true && hero->isAlive)
	{
		if (!hero->isFighting)
		{
			cin >> userInput;
			if (userInput == 'W' || userInput == 'A' || userInput == 'S' || userInput == 'D' ||
				userInput == 'w' || userInput == 'a' || userInput == 's' || userInput == 'd')
			{
				hero->heroMove(userInput, *map, monsterStore);
				std::system("cls");
				map->printMap();				
				PrintInfo();

			}
		}
		else if (hero->isFighting)
		{
			cin >> userInput;
			if (userInput == 'W' || userInput == 'A' || userInput == 'S' || userInput == 'D' ||
				userInput == 'w' || userInput == 'a' || userInput == 's' || userInput == 'd')
			{
				hero->isFighting = false;
				hero->heroMoveOut(userInput, *map, monsterStore);
				std::system("cls");
				map->printMap();
			}

			else if (userInput == 'k' || userInput == 'K')
			{
				hero->damageCal(monsterStore, *map);

				std::system("cls");
				map->printMap();
				PrintInfo();
			}
		}
	}
	if (!hero->isAlive)
	{
		hero->isAlive = true;
		hero.reset();
		playround++;
		hero = std::make_shared<Hero>();
		monster.reset();
		monster = std::make_shared<Monster>();
		map.reset();
		map = std::make_shared<Map>();
		monsterStore.clear();
		std::vector<std::shared_ptr<Monster>> monsterStore;
		InitGame();
		gamePlay();
	}
}
