#pragma once
#include "Object.h"
const float m_movespeed = 1;
const float m_Monstermovespeed = m_movespeed / 2;

enum Direction
{
	UP, DOWN, RIGHT, LEFT, STOP         //directions
};

class DynamicObject : public Object
{
public:
	// ----------- c-tor  /  d-dor -------------
	DynamicObject();
	DynamicObject(const sf::Texture& texture,const sf::Vector2f& pos,float size);
	virtual ~DynamicObject();



	virtual void move1(sf::Vector2f direction, float time, int dir);
	virtual Vector2f setDirection(sf::Vector2f& direction, float time, int dir) = 0;


	 void keepInPlace();				
	

	bool isinBound();							



protected:
	sf::Vector2f m_direction;
	Vector2f m_initialPosition;


};