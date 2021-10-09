#include "Data.h"

Data::Data()
{
	loadresources();

}

Data::~Data()
{
}

Data& Data::dataObj()
{
	static Data d1;
	return d1;
}


void Data::loadresources()
{
	loadtextures();
	loadsound();
	loadfont();

}



void Data::loadtextures()
{


	int NUM_OF_PICTURES =8;

	m_textures.resize(NUM_OF_PICTURES);

	m_textures[P_player].loadFromFile("player.png");
	m_textures[P_monster].loadFromFile("monster.png");
	m_textures[P_wall].loadFromFile("wall.png");
	m_textures[P_pole].loadFromFile("pole.png");
	m_textures[P_points].loadFromFile("coin.png");
	m_textures[P_present].loadFromFile("gift.png");
	m_textures[P_backround].loadFromFile("background.jpg");
	m_textures[P_ladder].loadFromFile("ladder.png");


	



}

void Data::loadfont()
{

	
		if (!m_font.loadFromFile("font.TTF"))	// if font couldn't be loaded
		{
			perror("cant load font");
			exit(EXIT_FAILURE);
		}
	
}





const Font& Data::getfont() const
{
	return m_font;
}

const Texture& Data::getBackround() const
{
	return m_textures[P_backround];
}



const Texture&Data::getPlayerPic() const
{
	return m_textures[P_player];
}

const Texture& Data::getMonsterPic() const
{
	return m_textures[P_monster];
}



const Texture& Data::getWallPic() const
{

	return m_textures[P_wall];
}

const Texture& Data::getPresentPic() const
{
	return m_textures[P_present];
}


const Texture& Data::getPointsPic() const
{
	return m_textures[P_points];
}

const Texture& Data::getLadderPic() const
{
	return m_textures[P_ladder];
}
const Texture& Data::getPolePic() const
{
	return m_textures[P_pole];
}


void Data::loadsound()
{

	int NUM_OF_SOUNDS = 3;

	m_soundefects.resize(NUM_OF_SOUNDS);

	
	m_soundefects[0].loadFromFile("soundback.wav");
	m_soundefects[1].loadFromFile("m_okay.wav");
	m_soundefects[2].loadFromFile("bubble4.wav");




}



const SoundBuffer& Data::getGAMEMUSICtune()const
{
	return m_soundefects[0];
}
const SoundBuffer& Data::getMostertune()const
{
	return m_soundefects[1];
}
const SoundBuffer& Data::getPointstune()const
{
	return m_soundefects[2];
}