#include <iostream>
#include "Item.h"

Item::Item(Type classification, int bonusValue) : classification{ classification }, bonusValue{bonusValue}
{
}

Item::Type Item::getClassification() const
{
	return classification;
}

int Item::getBonusValue() const
{
	return bonusValue;
}

std::ostream& operator<<(std::ostream& output, const Item& itemMessage)
{
	switch (itemMessage.getClassification())
	{
	case Item::Type::armor:
		output << "Armor";
		break;
	case Item::Type::shield:
		output << "Shield";
		break;
	case Item::Type::sword:
		output << "Sword";
		break;
	}
	output << "+" << itemMessage.getBonusValue();
	return output;
}
