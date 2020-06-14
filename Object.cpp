#include <random>
#include <iostream>
#include "Object.h"
std::random_device Object::seed;
std::default_random_engine Object::engine(seed());

Object::Object(Type name, int strength, int health, int level) : name{ name }, strength{ strength }, health{ health }, level{ level }
{
}

bool Object::isDead()
{
	return health <= 0;
}

std::ostream& operator<<(std::ostream& output, const Object & objectMessage)
{
	output << "L:" << objectMessage.level << " ";
	switch (objectMessage.name)
	{
	case Object::Type::player:
		output << "Player";
		break;
	case Object::Type::slime:
		output << "Slime";
		break;
	case Object::Type::orc:
		output << "Orc";
		break;
	case Object::Type::sprite:
		output << "Sprite";
		break;
	case Object::Type::dragon:
		output << "Dragon";
		break;
	}
	return output;
}
