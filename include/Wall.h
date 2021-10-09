#pragma once
#include "StaticObject.h"

class Wall :public StaticObject
{
public:
	using StaticObject::StaticObject;

	virtual ~Wall();
	virtual bool collision(Wall& otherobj);
	virtual bool collision(Player& otherobj);
	virtual bool collision(Object& otherobj);
	virtual bool collision(Coins& otherobj);
	virtual bool collision(Ladder& otherobj);
	virtual bool collision(Pole& otherobj);
	virtual bool collision(Monster& otherobj);
	virtual bool collision(GiftMonster& otherobj);
	virtual bool collision(GiftTime& otherobj);
	virtual bool collision(GiftLive& otherobj);
	virtual bool collision(GiftPoints& otherobj);
	virtual char getType();



};