#include<iostream>
#include "Monster.h"
#include "Player.h"

Monster::Monster(const Player & player)
{
	//set level based on player level
	std::normal_distribution<double> monsterLevel((float)player.getLevel(), player.getLevel() / 4.0);
	level = std::max(1, (int)monsterLevel(engine));

	std::uniform_int_distribution<int> monsterType(1, (int)Object::Type::numTypes - 1);
	name = (Object::Type)monsterType(engine);

	double strengthVariance{ 0.0 };
	double healthVariance{ 0.0 };
	double ACVariance{ 0.0 };
	switch (name)
	{
	case Object::Type::slime:
		strengthVariance = level * 1.5;
		healthVariance = level * 1.25;
		ACVariance = level / 2;
		break;
	case Object::Type::orc:
		strengthVariance = level * 2.0;
		healthVariance = (long long)level * level * 1.25;
		ACVariance = level * 1.5;
		break;
	case Object::Type::sprite:
		strengthVariance = level * 1.75;
		healthVariance = level;
		ACVariance = 0;
		break;
	case Object::Type::dragon:
		strengthVariance = level * 6.0;
		healthVariance = (long long)level * level * 3.0;
		ACVariance = level *3;
		break;
	}

	std::normal_distribution<double> randomStrength(strengthVariance, level / 4.0);
	std::normal_distribution<double> randomHealth(healthVariance * 5, level / 2.0);
	if (ACVariance != 0)
	{
		std::normal_distribution<double> randomAC(ACVariance, level / 2.0);
		AC = std::max(0, int(randomAC(engine)));
	}

	strength = std::max(1, (int)randomStrength(engine));
	health = std::max(1, (int)randomHealth(engine));
}

void Monster::print() const
{
	printName();
	std::cout << " h:" << health << std::endl;
}

int Monster::damage() const
{
	int potentialDamage{ strength };
	std::normal_distribution<double> damageDealt(potentialDamage, 2.0);

	printName();
	std::cout << " deals ";
	return std::max(1, (int)damageDealt(engine));
}

void Monster::defense(int damage)
{
	std::normal_distribution<double> defense(AC, 1.0 / level);
	damage = std::max(0, damage - (int)defense(engine));
	std::cout << damage << " damage to ";
	printName();
	std::cout << "!!!" << std::endl;
	health -= damage;
}
