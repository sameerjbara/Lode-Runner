#include "Ladder.h"

#include <iostream>


Ladder::~Ladder()
{

}
bool Ladder::collision(Wall& otherobj)
{
	return true;
}

bool Ladder::collision(Player& otherobj)
{
	return true;
}

bool Ladder::collision(Object& otherobj)
{
	return true;
}

bool Ladder::collision(Coins& otherobj)
{
	return true;
}

bool Ladder::collision(Ladder& otherobj)
{
	return true;
}

bool Ladder::collision(Pole& otherobj)
{
	return true;
}

bool Ladder::collision(Monster& otherobj)
{
	return true;
}

bool Ladder::collision(GiftMonster& otherobj)
{
	return true;
}

bool Ladder::collision(GiftTime& otherobj)
{
	return true;
}

bool Ladder::collision(GiftLive& otherobj)
{
	return true;
}

bool Ladder::collision(GiftPoints& otherobj)
{
	return true;
}


char Ladder::getType()
{
	return 'H';
}
