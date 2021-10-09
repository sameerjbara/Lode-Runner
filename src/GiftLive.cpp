#include "GiftLive.h"
#include "Player.h"
#include "Monster.h"
#include <iostream>




bool GiftLive::collision(Wall& otherobj)
{
	return true;
}

bool GiftLive::collision(Player& otherobj)
{

	is_eating = true;
	return(otherobj.collision(*this));
}
bool GiftLive::collision(Object& otherobj)
{
	return(otherobj.collision(*this));
}

bool GiftLive::collision(Coins& otherobj)
{
	return true;
}

bool GiftLive::collision(Ladder& otherobj)
{
	return true;
}
bool GiftLive::collision(Pole& otherobj)
{
	return true;
}

bool GiftLive::collision(Monster& otherobj)
{
	return true;

}

bool GiftLive::collision(GiftMonster& otherobj)
{
	return true;
}

bool GiftLive::collision(GiftTime& otherobj)
{
	return true;
}

bool GiftLive::collision(GiftLive& otherobj)
{
	return true;
}

bool GiftLive::collision(GiftPoints& otherobj)
{
	return true;
}

char GiftLive::getType()
{
	return '+';
}

GiftLive::~GiftLive()
{
}

