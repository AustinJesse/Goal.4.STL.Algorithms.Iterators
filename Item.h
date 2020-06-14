#ifndef ITEM_H
#define ITEM_H


class Item
{
public:
	Item() {};
	enum class Type { sword, armor, shield, numTypes };
	Item(Type classification, int bonusValue);

	Type getClassification() const;
	int getBonusValue() const;

	friend std::ostream& operator<<(std::ostream& output, const Item& itemMessage);

private:
	Type classification;
	int bonusValue;
};

#endif // !ITEM_H