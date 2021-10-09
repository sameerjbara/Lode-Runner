#include "Coins.h"

#include <iostream>



Coins::~Coins()
{

}
bool Coins::collision(Wall& otherobj)
{
	return true;
}

bool Coins::collision(Player& otherobj)
{
	is_eating = true;
	return(otherobj.collision(*this));
}

bool Coins::collision(Object& otherobj)
{
	return(otherobj.collision(*this));
}

bool Coins::collision(Coins& otherobj)
{
	return true;
}

bool Coins::collision(Ladder& otherobj)
{
	return true;
}

bool Coins::collision(Pole& otherobj)
{
	return true;
}

bool Coins::collision(Monster& otherobj)
{
	return true;
}

bool Coins::collision(GiftMonster& otherobj)
{
	return true;
}

bool Coins::collision(GiftTime& otherobj)
{
	return true;
}

bool Coins::collision(GiftLive& otherobj)
{
	return true;
}

bool Coins::collision(GiftPoints& otherobj)
{
	return true;
}



char Coins::getType()
{
	return '*';
}
