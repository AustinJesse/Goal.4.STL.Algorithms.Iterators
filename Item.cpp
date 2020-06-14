#include <iostream>
#include "Item.h"

Item::Item(Type classification, int bonusValue) : classification{ classification }, bonusValue{bonusValue}
{
}

Item::Type Item::getClassification() const
{
	return classification;
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
	output << "+" << itemMessage.bonusValue;
	return output;
}

bool operator<(const Item& param1, const Item& param2)
{
	return param1.bonusValue < param2.bonusValue;
}

int& operator+=(int& characteristic, const Item& Item)
{
	characteristic += Item.bonusValue;
	return characteristic;
}




