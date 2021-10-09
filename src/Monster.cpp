#include "Monster.h"
#include "Player.h"
#include <iostream>

Monster::Monster()
	:DynamicObject()
{
}

Monster::Monster(const sf::Texture& texture, const sf::Vector2f& pos, float size)
	:DynamicObject(texture, pos, size)
{
	
}

Monster::~Monster()
{
}
bool Monster::collision(Wall& otherobj)
{
	keepInPlace();
	return true;
}

bool Monster::collision(Player& otherobj)
{
	return(otherobj.collision(*this));
}

bool Monster::collision(Object& otherobj)
{
	return(otherobj.collision(*this));
}

bool Monster::collision(Coins& otherobj)
{
	return true;
}

bool Monster::collision(Ladder& otherobj)
{
	return true;
}

bool Monster::collision(Pole& otherobj)
{
	return true;
}

bool Monster::collision(Monster& otherobj)
{
	return true;
}

bool Monster::collision(GiftMonster& otherobj)
{
	return true;
}

bool Monster::collision(GiftTime& otherobj)
{
	return true;
}

bool Monster::collision(GiftLive& otherobj)
{
	return true;
}

bool Monster::collision(GiftPoints& otherobj)
{
	return true;
}


char Monster::getType()
{
	return '%';
}





