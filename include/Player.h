#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <memory>
#include"DynamicObject.h"
#include "Data.h"



class Player :public DynamicObject
{
public:

	Player();
	Player(const sf::Texture& texture,
		const sf::Vector2f& pos,
		const float size,
		const int& life,
		const int& score,
		const int& diamonds,
		int& level);

	virtual ~Player();

	virtual Vector2f setDirection(sf::Vector2f& direction,
		float time,int dir);


	virtual char getType();
	int getLife()const;
	int getScore()const;
	int getPoints()const;
	Vector2f getDirection()const;
	


	void decreaseLife();
	void setLife(int currentlife);
	void setPoints(int currentDiamonds);
	void AddScore(int score);
	void inishialScore();
	void addLevel();
	int getTimer()const;
	void setTimer(int newTime);

	bool getDeleteRight()const;
	void setdeleteRight(bool new1);

	bool getDeleteLeft()const;
	void setdeleteLeft(bool new1);

	bool getAddMonster()const;
	void setAddMonster(bool new1);
	

	virtual bool collision(Wall& otherobj);
	virtual bool collision(Player& otherobj);
	virtual bool collision(Object& otherobj);
	virtual bool collision(Coins& otherobj);
	virtual bool collision(Ladder& otherobj);
	virtual bool collision(Pole& otherobj);
	virtual bool collision(Monster& otherobj);
	virtual bool collision(GiftMonster& otherobj) ;
	virtual bool collision(GiftTime& otherobj) ;
	virtual bool collision(GiftLive& otherobj) ;
	virtual bool collision(GiftPoints& otherobj) ;



private:
	
	int m_life;
	int m_score;
	int m_PointsCounter;
	int m_level = 1;
	Vector2f m_inishialPositions;
	sf::Sound m_sound;
	int m_timer;
	bool deleteRight;
	bool deleteLeft;
	bool addMonster;
	
};


























