#include "GiftTime.h"
#include "Player.h"
#include "Monster.h"
#include <iostream>



bool GiftTime::collision(GiftTime& otherobj)
{
	return true;
}
bool GiftTime::collision(Wall& otherobj)
{
	return true;
}
bool GiftTime::collision(Player& otherobj)
{

	is_eating = true;
	return(otherobj.collision(*this));
}
bool GiftTime::collision(Object& otherobj)
{
	return(otherobj.collision(*this));
}








bool GiftTime::collision(Coins& otherobj)
{
	return true;
}

bool GiftTime::collision(Ladder& otherobj)
{
	return true;
}
bool GiftTime::collision(Pole& otherobj)
{
	return true;
}

bool GiftTime::collision(Monster& otherobj)
{
	return true;
}

bool GiftTime::collision(GiftMonster& otherobj)
{
	return true;
}

bool GiftTime::collision(GiftTime& otherobj)
{
	return true;
}

bool GiftTime::collision(GiftLive& otherobj)
{
	return true;
}

bool GiftTime::collision(GiftTime& otherobj)
{
	return true;
}

bool GiftTime::collision(GiftPoints& otherobj)
{
	return true;
}

char GiftTime::getType()
{
	return '+';
}




GiftTime::~GiftTime()
{
}

