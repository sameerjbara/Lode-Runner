#include "Wall.h"
#include "Player.h"
#include "Monster.h"
#include <iostream>

Wall::~Wall()
{

}

bool Wall::collision(Wall& otherobj)
{
	return true;
}
bool Wall::collision(Player& otherobj)
{
	
	return(otherobj.collision(*this));
}
bool Wall::collision(Object& otherobj)
{
	return(otherobj.collision(*this));
}








bool Wall::collision(Coins& otherobj)
{
	return true;
}

bool Wall::collision(Ladder& otherobj)
{
	return true;
}

bool Wall::collision(Pole& otherobj)
{
	return true;
}

bool Wall::collision(Monster& otherobj)
{
	return(otherobj.collision(*this));
}

bool Wall::collision(GiftMonster& otherobj)
{
	return true;
}

bool Wall::collision(GiftTime& otherobj)
{
	return true;
}

bool Wall::collision(GiftLive& otherobj)
{
	return true;
}

bool Wall::collision(GiftPoints& otherobj)
{
	return true;
}

char Wall::getType()
{
	return '#';
}
