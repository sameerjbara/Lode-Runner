#include "Pole.h"

#include <iostream>


Pole::~Pole()
{

}
bool Pole::collision(Wall& otherobj)
{
	return true;
}

bool Pole::collision(Player& otherobj)
{
	return true;
}

bool Pole::collision(Object& otherobj)
{
	return true;
}

bool Pole::collision(Coins& otherobj)
{
	return true;
}

bool Pole::collision(Ladder& otherobj)
{
	return true;
}

bool Pole::collision(Pole& otherobj)
{
	return true;
}

bool Pole::collision(Monster& otherobj)
{
	return true;
}

bool Pole::collision(GiftMonster& otherobj)
{
	return true;
}

bool Pole::collision(GiftTime& otherobj)
{
	return true;
}
bool Pole::collision(GiftLive& otherobj)
{
	return true;
}
bool Pole::collision(GiftPoints& otherobj)
{
	return true;
}
char Pole::getType()
{
	return '-';
}
