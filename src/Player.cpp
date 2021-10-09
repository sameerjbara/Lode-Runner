#include "Player.h"
#include <iostream>

using std::cout;
using std::endl;


Player::Player()

{

}
//-----------------------------------------
Player::~Player()
{
}
char Player::getType()
{
	return '@';
}
//-----------------------------------------
Player::Player(const sf::Texture& texture, const sf::Vector2f& pos, const  float size,  const int& life, const int& score, const int& points_amount,int& level)
	:DynamicObject(texture, pos, size), m_score(score), m_life(life), m_PointsCounter(points_amount)
{
	
	m_figure.setTexture(&texture);
	m_figure.setScale(0.8f, 0.8f);
	m_figure.setSize(sf::Vector2f(size, size));
	m_figure.setPosition(pos);
	m_inishialPositions = pos;
	m_level = level;
	deleteRight = false;
	deleteLeft = false;
	addMonster = false;
}
//-----------------------------------------
Vector2f Player::setDirection(sf::Vector2f& direction, float time,int dir)
{
	
	
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			if (dir == 1||dir==0)
			{
				m_figure.setScale(0.8f, 0.8f);
				m_figure.setRotation(0);
				return 	{ 0, -m_movespeed * time };
			}
			else
			{
				return { 0,0 };
			}

		}
	
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			if (dir == 2 || dir == 0)
			{
				m_figure.setScale(0.8f, 0.8f);
				m_figure.setRotation(0);
				return 	{ 0,m_movespeed * time };
			}
			else
			{
				return { 0,0 };

			}

		}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		m_figure.setScale(0.8f, 0.8f);
		m_figure.setRotation(0);
		return 	{ -m_movespeed * time, 0 };

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		m_figure.setScale(0.8f, 0.8f);
		m_figure.setRotation(0);
		return 	{ m_movespeed * time, 0 };

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
	{
		deleteRight = true;
		return { 0,0 };

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
	{
		deleteLeft = true;
		return { 0,0 };

	}

	return { 0,0 };
}

//-----------------------------------------
int Player::getLife() const
{
	return m_life;
}
//-----------------------------------------
int Player::getScore() const
{
	return m_score;
}
//-----------------------------------------
int Player::getPoints() const
{
	return m_PointsCounter;
}
//-----------------------------------------
sf::Vector2f Player::getDirection() const
{
	return m_direction;
}
//-----------------------------------------
void Player::decreaseLife()
{
	m_life--;

}
//-----------------------------------------
void Player::setLife(int currentlife)
{
	m_life = currentlife;
}
//-----------------------------------------
void Player::setPoints(int currPoints)
{
	m_PointsCounter = currPoints;
}
//-----------------------------------------
void Player::AddScore(int score)
{
	m_score += score;
}
//-----------------------------------------
void Player::inishialScore()
{
	m_score = 0;
}

void Player::addLevel()
{
	m_level++;
}

int Player::getTimer() const
{
	return m_timer;
}

void Player::setTimer(int newTime)
{
	m_timer = newTime;
}

bool Player::getDeleteRight() const
{
	return deleteRight;
}

void Player::setdeleteRight(bool new1)
{
	deleteRight = new1;
}
bool Player::getDeleteLeft() const
{
	return deleteLeft;
}

void Player::setdeleteLeft(bool new1)
{
	deleteLeft = new1;
}

bool Player::getAddMonster() const
{
	return addMonster;
}

void Player::setAddMonster(bool new1)
{
	addMonster = new1;
}

bool Player::collision(Wall& otherobj)
{
	
	keepInPlace();
	return true;
}

bool Player::collision(Player& otherobj)
{
	return true;
}

bool Player::collision(Object& otherobj)
{
	return(otherobj.collision(*this));
}
bool Player::collision(Coins& otherobj)
{
	
	m_sound.setBuffer(Data::dataObj().getPointstune());
	m_sound.play();
	AddScore(m_level * 2);
	m_PointsCounter++;
	return true;
}
bool Player::collision(Ladder& otherobj)
{
	
	return true;
}
bool Player::collision(Pole& otherobj)
{
	return true;
}

bool Player::collision(Monster& otherobj)
{

	m_sound.setBuffer(Data::dataObj().getMostertune());
	m_sound.play();
	m_life--;
	
	m_figure.setPosition(m_inishialPositions);

	return true;
}

bool Player::collision(GiftMonster& otherobj)
{
	setAddMonster(true);
	return true;
}
bool Player::collision(GiftTime& otherobj)
{
	setTimer(getTimer() + 10);
	return true;
}
bool Player::collision(GiftLive& otherobj)
{
	m_life++;
	return true;
}
bool Player::collision(GiftPoints& otherobj)
{
	m_PointsCounter++;
	return true;
}

