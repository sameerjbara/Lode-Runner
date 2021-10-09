#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "Player.h"
#include"StaticObject.h"
#include"Wall.h"
#include"GiftLive.h"
#include"GiftTime.h"
#include"GiftMonster.h"

#include"Pole.h"
#include"Coins.h"
#include "Ladder.h"
#include <Monster.h>
#include "Object.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "ToolBar.h"
#include "LineMonster.h"

using namespace sf;
using namespace std;

using sf::Texture;
using sf::Vector2f;
using sf::RectangleShape;
using sf::RenderWindow;
using sf::FloatRect;

enum charTofigure
{
	CharPlayer = '@',
	CharMONSTER = '%',
	CharWALL = '#',
	CharPoints = '*',
	charPRESENT = '+',
	charPole = '-',
	charLadder = 'H'
};



class Board
{

public:

	Board();//open file
	~Board();

	bool openFile(int level);       
	void clearObjects();                     
	bool loadMatrix();//load the matrix 
	void loadLevel();// load  level 
	void run();//the main function
	void moveChareters();
	void mine(int dir);

	FloatRect getGlobalbound()const;

	void draw();
	void drawBoard();
	void drawPlayer();
	void drawFigures();
	void drawMonsters();
	bool centered = false;
	void centerMonster(Vector2f pos,int index);

	void displayWindow();
	void clearWindow();
	void crateWindow();

	void handelColision();
	int checDir(Vector2f pos);
	Vector2f objFall(Vector2f pos);

	void deleteDigging();



private:
	//======= file =========
	std::fstream m_file;
	int m_col;
	int m_row;
	
	
	sf::RenderWindow m_window;
	sf::Clock m_clock;               
	float m_time;
	float m_time1;

	float m_levelTime;
	sf::Clock m_timer;   
	sf::Clock m_timer1;

	int timer;
	
	sf::RectangleShape m_boardFigure;

	
	std::vector<std::vector<char>>  m_matrix;
	std::unique_ptr <Player> m_player;                        //player
	//std::unique_ptr <Player> p1;                        //player
	std::vector<Vector2f> m_digging;
	std::vector<std::unique_ptr<Monster>> m_monsters;    //monsters
	std::vector<std::unique_ptr <StaticObject>> m_boardPtr;   //statics
	int m_monsterC;
	

	int m_PointsAmount;
	int m_level;
	int m_currentLife;
	int m_currentScore;
	sf::RectangleShape m_background;

	sf::Text m_scoreToolbar;
	std::ostringstream m_scoreString;
	Font m_font;
	sf::Text m_data;
	std::vector<std::unique_ptr<sf::Text>> m_data1;

	sf::Vector2f m_playerPos;
	Music m_music;

};
	


