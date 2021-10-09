#pragma once
#include <string>
#include <SFML/Graphics.hpp>




class Player;
class Monster;
class Wall;
class Pole;
class Ladder;
class Coins;
class Space;
class GiftMonster;
class GiftPoints;
class GiftTime;
class GiftLive;


enum PICTURE
{
	P_player, P_monster, P_present, P_wall, P_points, P_backround, P_pole, P_ladder
};
const int TILE_SIZE = 45;
const std::string FILE_NAME = "board.txt";

const int width = 1500;
const int height = 850;


using sf::Texture;
using sf::Vector2f;
using sf::RectangleShape;
using sf::RenderWindow;
using sf::FloatRect;


class Object
{
public:

	Object();
	Object(const Texture& texture,
		const Vector2f position,
		const float size);

	virtual ~Object();

	virtual Vector2f getPosition() const;
	virtual void setPosition1(Vector2f position);

	virtual Vector2f getSize()const;

	FloatRect getGlobalBound()const;

	virtual void draw(RenderWindow& window);

	virtual char getType() = 0;

	virtual bool collision(Player& otherobj) = 0;
	virtual bool collision(Wall& otherobj) = 0;
	virtual bool collision(Object& otherobj) = 0;
	virtual bool collision(Coins& otherobj) = 0;
	virtual bool collision(Ladder& otherobj)=0;
	virtual bool collision(Pole& otherobj)=0;
	virtual bool collision(GiftMonster& otherobj)=0;
	virtual bool collision(GiftTime& otherobj)=0;
	virtual bool collision(GiftLive& otherobj)=0;
	virtual bool collision(GiftPoints& otherobj)=0;



protected:
	sf::RectangleShape m_figure;
	Vector2f m_position;


};