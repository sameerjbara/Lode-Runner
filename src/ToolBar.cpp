#include <iostream>
#include "ToolBar.h"


ToolBar::ToolBar()
{

	m_selectedButton = 0;
	buildToolBar();
	creatwindow();
	m_ToolBarWindow.setSize(sf::Vector2u(width, height));
	
}



ToolBar::ToolBar(float width, float height)
	:m_width(width), m_hegiht(height)
{

	Data::dataObj().loadresources();
	m_selectedButton = 0;
	creatwindow();
	buildToolBar();
	m_background.setSize(sf::Vector2f(width, height));

	
}

ToolBar::~ToolBar()
{
}

void ToolBar::startToolBar()
{
}

void ToolBar::drawButoons()
{
	for (size_t i = 0; i < NUM_OF_BUTTONS; i++)
	{
		m_ToolBarWindow.draw(m_toolBar[i]);
	}
}

void ToolBar::creatwindow()
{
	m_ToolBarWindow.create(sf::VideoMode(width, height), "menu");
}

void ToolBar::draw()
{

	m_ToolBarWindow.clear();

	m_ToolBarWindow.draw(m_background);

	drawButoons();

	m_ToolBarWindow.display();
}

void ToolBar::setsize(float width, float hefight)
{
	m_width = width;
	m_hegiht = hefight;
}

void ToolBar::buildToolBar()
{
	m_toolBar[0].setFont(Data::dataObj().getfont());
	m_toolBar[0].setFillColor(sf::Color::White);
	m_toolBar[0].setString("play New Game");
	m_toolBar[0].setPosition(sf::Vector2f(width / 2 - 30, 240 + 73));
	m_toolBar[0].setScale(sf::Vector2f(1, 1));

	m_toolBar[1].setFont(Data::dataObj().getfont());
	m_toolBar[1].setFillColor(sf::Color::White);
	m_toolBar[1].setString("Exit");
	m_toolBar[1].setPosition(sf::Vector2f(width / 2 - 33, 430));
	m_toolBar[1].setScale(sf::Vector2f(1, 1));




}

void ToolBar::events()
{
	sf::Event menuevent;

	while (m_ToolBarWindow.pollEvent(menuevent))
	{

		switch (menuevent.type)
		{
		case sf::Event::Closed:
			m_ToolBarWindow.close();
			break;

		case sf::Event::KeyPressed:
			switch (menuevent.key.code)
			{
			case sf::Keyboard::Up:

				moveup();
				
				break;
			case sf::Keyboard::Down:
				movedown();
				break;


			case sf::Keyboard::Return:
				switch (getselecteditem())
				{

				case 0:
				{
				

					Board b2;
					b2.run();
					

				}
				case 1:
				{
					m_ToolBarWindow.close();
					EXIT_SUCCESS;
					break;
				}
				}
			}

		}

	}

}



/*
void ToolBar::moveup()
{
	if (m_selectedButton - 1 >= 0)
	{
		m_toolBar[m_selectedButton].setColor(sf::Color::White);
		m_selectedButton--;
		m_toolBar[m_selectedButton].setColor(sf::Color::Red);
	}
}
*/
void ToolBar::run()
{
	while (m_ToolBarWindow.isOpen())
	{
		events();
		draw();
	}



}
void ToolBar::moveup()
{
	if (m_selectedButton - 1 >= 0)
	{
		m_toolBar[m_selectedButton].setColor(sf::Color::White);
		m_selectedButton--;
		m_toolBar[m_selectedButton].setColor(sf::Color::Red);
	}
}

void ToolBar::movedown()
{
	if (m_selectedButton + 1 < NUM_OF_BUTTONS)
	{
		m_toolBar[m_selectedButton].setColor(sf::Color::White);
		m_selectedButton++;
		m_toolBar[m_selectedButton].setColor(sf::Color::Red);

	}
}