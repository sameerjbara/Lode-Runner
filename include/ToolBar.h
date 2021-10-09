#pragma once
#include "Data.h"
#include "Board.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

const int NUM_OF_BUTTONS = 2;

class ToolBar
{
public:
	//---------- c-tor / d-tor ---------------
	ToolBar();
	ToolBar(float height,
		float width);
	void buildToolBar();

	~ToolBar();
	void startToolBar();

	//---------handel menu ----------------
	void run();
	void events();
	//void highlight();
	

	//---------- get --------------------
	int getselecteditem() const { return m_selectedButton; }

	//------------ set ---------------
	void setsize(float width,
		float hefight);

	//---------- draw ----------------
	void drawButoons();
	void draw();
	void creatwindow();
	void moveup();
	void movedown();
	

private:
	float m_width;         //window size
	float m_hegiht;		  //window size

	int m_selectedButton;     //check wich button pressed
	sf::RectangleShape m_background;
	sf::Text m_toolBar[NUM_OF_BUTTONS];     //vector of buttons
	sf::RenderWindow m_ToolBarWindow;
	

};