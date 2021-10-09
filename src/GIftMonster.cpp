#include "GiftMonster.h"
#include "Player.h"
#include "Monster.h"
#include <iostream>



bool GiftMonster::collision(GiftMonster& otherobj)
{
	return true;
}
bool GiftMonster::collision(Wall& otherobj)
{
	return true;
}
bool GiftMonster::collision(Player& otherobj)
{

	is_eating = true;
	return(otherobj.collision(*this));
}
bool GiftMonster::collision(Object& otherobj)
{
	return(otherobj.collision(*this));
}

bool GiftMonster::collision(Coins& otherobj)
{
	return true;
}

bool GiftMonster::collision(Ladder& otherobj)
{
	return true;
}
bool GiftMonster::collision(Pole& otherobj)
{
	return true;
}

bool GiftMonster::collision(Monster& otherobj)
{
	return true;
}


bool GiftMonster::collision(GiftTime& otherobj)
{
	return true;
}

bool GiftMonster::collision(GiftLive& otherobj)
{
	return true;
}



bool GiftMonster::collision(GiftPoints& otherobj)
{
	return true;
}

char GiftMonster::getType()
{
	return '+';
}


GiftMonster::~GiftMonster()
{
}
