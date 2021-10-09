#include "GiftPoints.h"
#include "Player.h"
#include "Monster.h"
#include <iostream>



bool GiftPoints::collision(GiftPoints& otherobj)
{
	return true;
}
char GiftPoints::getType()
{
	
		return '+';
	
}
bool GiftPoints::collision(Wall& otherobj)
{
	return true;
}
bool GiftPoints::collision(Player& otherobj)
{
	is_eating = true;
	return(otherobj.collision(*this));
}
bool GiftPoints::collision(Object& otherobj)
{
	return(otherobj.collision(*this));
}








bool GiftPoints::collision(Coins& otherobj)
{
	return true;
}

bool GiftPoints::collision(Ladder& otherobj)
{
	return true;
}
bool GiftPoints::collision(Pole& otherobj)
{
	return true;
}

bool GiftPoints::collision(Monster& otherobj)
{
	return true;
}

bool GiftPoints::collision(GiftMonster& otherobj)
{
	return true;
}

bool GiftPoints::collision(GiftTime& otherobj)
{
	return true;
}

bool GiftPoints::collision(GiftLive& otherobj)
{
	return true;
}


GiftPoints::~GiftPoints()
{
}