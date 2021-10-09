#pragma once

#include "Object.h"
#include <fstream>
#include <sstream>
#include<iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>



using std::cout;
using std::endl;
using sf::Font;
using sf::Texture;
using std::ifstream;
using std::vector;
using std::ostringstream;
using sf::SoundBuffer;

class Data
{
public:
	//----------d-tor-------------------------
	Data();
		Data(const Data&) = default;

	~Data();
	static Data& dataObj();

	
	const Font& getfont() const;

	const Texture& getBackround() const;
	const Texture& getPlayerPic() const;
	const Texture& getMonsterPic() const;
	const Texture& getWallPic() const;
	const Texture& getPresentPic() const;
	const Texture& getPointsPic() const;
	const Texture& getLadderPic() const;
	const Texture& getPolePic() const;

	const SoundBuffer& getGAMEMUSICtune()const;
	const SoundBuffer& getMostertune()const;
	const SoundBuffer& getPointstune()const;
	void loadsound();

		void loadresources();
		void loadtextures();
		void loadfont();

private:
	sf::Font m_font;                                  
	vector<sf::SoundBuffer> m_soundefects;
	vector<sf::Texture> m_textures;		              
};








