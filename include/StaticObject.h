#pragma once
#include "Object.h"
#include<SFML/Graphics.hpp>

using sf::Texture;
using sf::Vector2f;


class StaticObject : public Object
{
public:
	using Object::Object;
	virtual ~StaticObject();
	bool is_eating = false;


};