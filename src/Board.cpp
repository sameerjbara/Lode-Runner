#include "Board.h"
#include "Monster.h"
#include "Data.h"
#include <iostream>
#include "SmartMonster.h"
#include "RandMonster.h"
#include <time.h>



Board::Board()
	:m_monsterC(0), m_level(1), m_PointsAmount(0), m_levelTime(0), m_row(0), m_col(0), m_currentLife(3), m_currentScore(0),
	m_data("Score:            Lives:           Level:             time:           ", m_font, 40)
	
{
	
	m_font.loadFromFile("font.TTF");
	m_data.setFillColor(Color::Blue);
	m_data.setPosition(10, 10);
	
	
	m_boardFigure.setSize(sf::Vector2f(45, 45));
	m_boardFigure.setScale(0.8, 0.8);
	
	
	for (size_t i = 0; i < 4; i++) {
		m_data1.push_back(std::make_unique<Text>());
		m_data1[i]->setFont(m_font);
		m_data1[i]->setCharacterSize(40);
		m_data1[i]->setFillColor(Color::White);
		m_data1[i]->setPosition((float)(130 + i * 220), 10);
	}
	
	//Data::dataObj().loadresources();

	m_music.openFromFile("soundback.wav");
	m_music.setLoop(true);
	m_music.play();
	m_music.setVolume(10);

	openFile(1);
	

	
	
}
//---------------------------------------
bool Board::openFile(int level)
{
	if (level == 1) {

		m_file.open(FILE_NAME);
	}
	
	if (!m_file.is_open())
		return false;

	return true;
}
//---------------------------------------
void Board::crateWindow()
{

	m_window.create(sf::VideoMode(width, height), "Lode runner", sf::Style::Default);
	m_background.setTexture(&Data::dataObj().getBackround());
	m_background.setSize(sf::Vector2f(width, height));
}
//---------------------------------------
void Board::displayWindow()
{
	m_window.display();
}
//---------------------------------------
void Board::clearWindow()
{
	m_window.clear(sf::Color::White);
	m_window.draw(m_background);
}
//---------------------------------------
void Board::clearObjects()
{
	m_boardPtr.clear();
	m_monsters.clear();
}
//---------------------------------------
Board::~Board()
{
	m_file.close();
}
//---------------------------------------
void Board::run()
{
	clock_t t;
	int f;
	crateWindow();
	m_window.setFramerateLimit(250);
	m_time = m_clock.restart().asSeconds();
	int timer2;
	while (loadMatrix())
	{
		timer = m_timer.getElapsedTime().asSeconds();


		loadLevel();
		while (m_window.isOpen())
		{
			timer = m_timer.getElapsedTime().asSeconds();
			m_player->setTimer(timer);
			
			if (m_player->getTimer() >= 10)
			{
				m_player->setTimer(m_timer.restart().asSeconds());
				m_player->setPosition1(m_playerPos);
				m_player->decreaseLife();
			}
			
			m_data1[0]->setString(std::to_string(m_player->getScore()));
			m_data1[1]->setString(std::to_string(m_player->getLife()));
			m_data1[2]->setString(std::to_string(m_level));
			m_data1[3]->setString(std::to_string(m_player->getTimer()));

			
			draw();
			moveChareters();
			//m_timer1.restart().asSeconds();
			timer2 = m_timer1.getElapsedTime().asSeconds();
			
			if (timer2> 5)
			{
				m_timer1.restart().asSeconds();
				deleteDigging();
			//	timer2 = 0;
			}
			
			handelColision();
			
		


			if (m_player->getPoints()==m_PointsAmount )
			{

				m_player->AddScore(50);
				m_currentScore = m_player->getScore();
				m_level++;
				m_player->addLevel();
				m_PointsAmount = 0;
				if (m_level == 5)
				{
					
					m_window.clear(sf::Color::White);
					m_window.draw(m_background);
					m_window.display();
					m_music.setLoop(false);
					m_music.pause();
					ToolBar t1;
					t1.run();
					m_window.close();
				
				}
				else
				{


					break;
				}
			}

			if (m_player->getLife() <= 0)
			{

				clearObjects();
				while (m_window.isOpen())
				{
					m_window.clear(sf::Color::White);
					m_window.draw(m_background);
					m_window.display();
					m_music.setLoop(false);
					m_music.pause();

					ToolBar t1;
					t1.run();
					//	std::this_thread::sleep_for(5s);
					m_window.close();


				}
				exit(EXIT_SUCCESS);

			}
			


		}


	}
	//clearObjects();
}
//---------------------------------------
bool Board::loadMatrix()
{
	if (m_file.eof())
		return false;

	m_file >> m_row >> m_col;
	m_col++;
	m_row++;
	m_matrix.resize(m_row);
	for (size_t i = 0; i < m_row; i++)
	{
		m_matrix[i].resize(m_col);
	}

	char c = m_file.get();

	while (!m_file.eof())
	{
		for (size_t i = 0; i < m_row; i++)
		{
			for (size_t j = 0; j < m_col; j++)
			{
				m_matrix[i][j] = m_file.get();
				if (m_matrix[i][j] == '*')
				{
					m_PointsAmount++;
				}
			}
		}
		m_file.get();
		break;
	}

	return true;
}
//---------------------------------------
void Board::loadLevel()
{
	clearObjects();
	char c;
	int giftc = 0;

	for (int i = 0; i < m_row; i++)
	{
		for (int j = 0; j < m_col; j++)
		{
			c = charTofigure(m_matrix[i][j]);
			
			switch (c)
			{
			case CharPlayer:
				m_player = std::make_unique<Player>(Data::dataObj().getPlayerPic(),
					sf::Vector2f(j * TILE_SIZE, (i + 1) * TILE_SIZE), TILE_SIZE, m_currentLife, m_currentScore, 0, m_level);
				m_playerPos.x = i * TILE_SIZE;
					m_playerPos.y= j * TILE_SIZE ;
				break;

			case CharMONSTER://insert all kind of monser
			{
				
				if (m_monsterC == 0)
				{
				
					m_monsters.push_back(std::make_unique<SmartMonster>(Data::dataObj().getMonsterPic()
						, sf::Vector2f(j * TILE_SIZE, (i+1) * TILE_SIZE), TILE_SIZE, *m_player));
					m_monsterC++;

					break;
				}
			
				else if (m_monsterC == 1)
				{
				
					m_monsters.push_back(std::make_unique<RandMonster>(Data::dataObj().getMonsterPic()
						, sf::Vector2f(j * TILE_SIZE, (i + 1) * TILE_SIZE), TILE_SIZE));
					m_monsterC++;

					break;
				
				}
				
				else
				{
					m_monsters.push_back(std::make_unique<LineMonster>(Data::dataObj().getMonsterPic()
						, sf::Vector2f(j * TILE_SIZE, (i + 1) * TILE_SIZE), TILE_SIZE));
					m_monsterC=0;

					break;
				}
				
			}
			case CharWALL:
			{
				m_boardPtr.push_back(std::make_unique <Wall>(Data::dataObj().getWallPic()
					, sf::Vector2f(j * TILE_SIZE, (i + 1) * TILE_SIZE), TILE_SIZE));
				break;
			}

			case CharPoints:
			{
				m_boardPtr.push_back(std::make_unique < Coins > (Data::dataObj().getPointsPic()
					, sf::Vector2f(j * TILE_SIZE, (i + 1) * TILE_SIZE), TILE_SIZE));
				break;

			
			}
			case charPole:
				m_boardPtr.push_back(std::make_unique <Pole>(Data::dataObj().getPolePic()
					, sf::Vector2f(j * TILE_SIZE, (i + 1) * TILE_SIZE), TILE_SIZE));
				break;

			case charLadder:
				m_boardPtr.push_back(std::make_unique <Ladder>(Data::dataObj().getLadderPic()
					, sf::Vector2f(j * TILE_SIZE, (i + 1) * TILE_SIZE), TILE_SIZE));
				break;
			case charPRESENT:
				if (giftc == 0)
				{
					m_boardPtr.push_back(std::make_unique <GiftMonster>(Data::dataObj().getPresentPic()
						, sf::Vector2f(j * TILE_SIZE, (i + 1) * TILE_SIZE), TILE_SIZE));
					giftc++;
					break;
				}
				if (giftc == 1)
				{
					m_boardPtr.push_back(std::make_unique <GiftMonster>(Data::dataObj().getPresentPic()
						, sf::Vector2f(j * TILE_SIZE, (i + 1) * TILE_SIZE), TILE_SIZE));
					giftc++;
					break;
				}
				if (giftc == 2)
				{
					m_boardPtr.push_back(std::make_unique <GiftMonster>(Data::dataObj().getPresentPic()
						, sf::Vector2f(j * TILE_SIZE, (i + 1) * TILE_SIZE), TILE_SIZE));
					giftc++;
					break;
				}
				if (giftc == 3)
				{
					m_boardPtr.push_back(std::make_unique <GiftMonster>(Data::dataObj().getPresentPic()
						, sf::Vector2f(j * TILE_SIZE, (i + 1) * TILE_SIZE), TILE_SIZE));
					giftc = 0;
					break;
				}
			case ' '://delete space
				break;
			}

		}
	}
}
//---------------------------------------
void Board::draw()
{
	clearWindow();
	
	m_window.draw(m_data);
	m_window.draw(*m_data1[0]);
	m_window.draw(*m_data1[1]);
	m_window.draw(*m_data1[2]);
	m_window.draw(*m_data1[3]);

	
	drawFigures();
	displayWindow();
}
//---------------------------------------
void Board::drawFigures()
{
	drawPlayer();
	drawBoard();
	drawMonsters();
}
//---------------------------------------
void Board::drawPlayer()
{
	if (m_player)
	{
		m_player->draw(m_window);
	}
}
//---------------------------------------
void Board::drawBoard()
{
	for (int i = 0; i < m_boardPtr.size(); i++)
	{
		m_boardPtr[i]->draw(m_window);
	}
}
//---------------------------------------
void Board::drawMonsters()
{
	for (int i = 0; i < m_monsters.size(); i++)
	{
		m_monsters[i]->draw(m_window);
	}
}
//---------------------------------------
void Board::moveChareters()
{
	
	m_player->move1(sf::Vector2f(0, 0), m_time, checDir(m_player->getPosition()));
	
	if (m_player->getDeleteRight() == true)
	{
		m_player->setdeleteRight(false);
		
		mine(0);
	}
	if (m_player->getDeleteLeft() == true)
	{
		m_player->setdeleteLeft(false);
		mine(1);
	}
	for (int i = 0; i < m_monsters.size(); i++)
	{
		m_monsters[i]->move1(sf::Vector2f(1, 1), m_time,checDir(m_monsters[i]->getPosition()));
	}
	
}

void Board::mine(int dir)
{
	
	for (int i = 0; i < m_boardPtr.size(); i++)
	{


		
		if (dir == 0)
		{
			if (((int)(m_player->getPosition().y / TILE_SIZE) + 2) == (int)((m_boardPtr[i]->getPosition().y  / TILE_SIZE ))
				&& ((int)((m_player->getPosition().x / TILE_SIZE) + 1.5)) == (int)(m_boardPtr[i]->getPosition().x / TILE_SIZE))
			{
				m_digging.push_back(m_boardPtr[i]->getPosition());
				m_boardPtr.erase(m_boardPtr.begin() + i);
				break;
			}
		}
		
		
		else if(dir==1)
		{
			if (((int)(m_player->getPosition().y / TILE_SIZE) + 2) == (int)(m_boardPtr[i]->getPosition().y / TILE_SIZE)
				&& ((int)((m_player->getPosition().x / TILE_SIZE) - 0.5)) == (int)(m_boardPtr[i]->getPosition().x / TILE_SIZE))
			{
				m_digging.push_back(m_boardPtr[i]->getPosition());
				m_boardPtr.erase(m_boardPtr.begin() + i);
				break;
			}
		}
	}
	
	
}
//---------------------------------------
void Board::handelColision()
{
	Vector2f temp;
	bool notCollide = true;
	for (size_t i = 0; i < m_boardPtr.size(); i++)
	{
		if (m_boardPtr[i])
			if (m_player->getGlobalBound().intersects(m_boardPtr[i]->getGlobalBound()))
			{
				notCollide = false;
				if (m_player)
					
					if (m_player->collision(*m_boardPtr[i]))
					{
						if (m_player->getAddMonster())
						{
							m_player->setAddMonster(false);
							temp = m_boardPtr[i]->getPosition();
							m_monsters.push_back(std::make_unique<RandMonster>(Data::dataObj().getMonsterPic()
								, temp, TILE_SIZE));
						}
						if (m_boardPtr[i]->is_eating)
						{
							m_boardPtr.erase(m_boardPtr.begin() + i);
						}
						
					}
			}
	}
	if (notCollide)
	{
		notCollide = true;
		m_player->setPosition1(objFall(m_player->getPosition()));
	}
	notCollide = true;
	for (size_t c = 0; c < m_monsters.size(); c++)
	{
		for (size_t i = 0; i < m_boardPtr.size(); i++)
		{
			if (m_monsters[c])
				if (m_monsters[c]->getGlobalBound().intersects(m_boardPtr[i]->getGlobalBound()))
				{
					notCollide = false;
					if (m_boardPtr[i]->getType() == 'H')
					{
						if (!centered)
						{
							centerMonster(m_boardPtr[i]->getPosition(),c);
							centered = true;
						}
					}
					else if(m_boardPtr[i]->getType() != 'H')
					{
						centered = false;
					}

					if (m_monsters[c])
						m_monsters[c]->collision(*m_boardPtr[i]);
				}
				
		}

		
		if (notCollide)
		{
			centered = false;
			notCollide = true;
			m_monsters[c]->setPosition1(objFall(m_monsters[c]->getPosition()));
		}
	}
	for (size_t i = 0; i < m_monsters.size(); i++)
	{
		if (m_monsters[i])
			if (m_player->getGlobalBound().intersects(m_monsters[i]->getGlobalBound()))
			{
				notCollide = false;
				if (m_player)
					m_player->collision(*m_monsters[i]);
			}
	}
}
//--------------------------------------
int Board::checDir(Vector2f pos)
{
	m_boardFigure.setPosition(pos);
	m_boardFigure.move({ 0,-m_movespeed * m_time });
	bool up = false;
	bool down = true;

	for (int i = 0; i < m_boardPtr.size(); i++)
	{
		if (m_boardFigure.getGlobalBounds().intersects(m_boardPtr[i]->getGlobalBound()))
		{
			
			if (m_boardPtr[i]->getType() == 'H')
			{
				
					up = true;//can go up
				
			}
		}
	}
	m_boardFigure.setPosition(pos);
	m_boardFigure.move({ 0,m_movespeed * m_time });
	for (int i = 0; i < m_boardPtr.size(); i++)
	{
		if (m_boardFigure.getGlobalBounds().intersects(m_boardPtr[i]->getGlobalBound()))
		{

			if (m_boardPtr[i]->getType() == '#')
			{
				
				down = false;//cant go down 
			}
		}
	}
	
	if (up && down)
	{
		return 0;//can go up and down
	}
	else if (up && !down)
	{
		return 1; //can go up but cant go down 
	}
	else if (!up && down)
	{
		return 2; //cant go up but can go down
	}
	else
	{
		return 3;//cant go up and cant go down
	}
}
//---------------------------------------
Vector2f Board::objFall(Vector2f pos)
{

	m_boardFigure.setPosition(pos);
	m_boardFigure.move({ 0,-m_movespeed * m_time });
	bool down = true;
	while (down)
	{
		for (int i = 0; i < m_boardPtr.size(); i++)
		{
			if (m_boardFigure.getGlobalBounds().intersects(m_boardPtr[i]->getGlobalBound()))
			{

				if (m_boardPtr[i]->getType() == '#')
				{
					down = false;//can go up
				}
			}
		}
		m_boardFigure.move({ 0, m_movespeed* m_time});
	}

	m_boardFigure.move({ 0,9* -m_movespeed * m_time });

	return(m_boardFigure.getPosition());
}
//---------------------------------------
FloatRect Board::getGlobalbound() const
{
	return m_boardFigure.getGlobalBounds();
}
//--------------------------------------
void Board::centerMonster(Vector2f pos,int index)
{
	Vector2f p = { 0,m_monsters[index]->getPosition().y };
	p.x = pos.x;
	m_monsters[index]->setPosition1(p);
}
void Board::deleteDigging()
{

	for (int i = 0; i < m_digging.size(); i++)
	{

		
		m_boardPtr.push_back(std::make_unique <Wall>(Data::dataObj().getWallPic()
			, m_digging[i], TILE_SIZE));


	}
	
	m_digging.clear();
}