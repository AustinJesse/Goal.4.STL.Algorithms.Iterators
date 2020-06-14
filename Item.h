#ifndef ITEM_H
#define ITEM_H


class Item
{
public:
	Item() {};
	enum class Type { sword, armor, shield, numTypes };
	Item(Type classification, int bonusValue);

	Type getClassification() const;

	friend std::ostream& operator<<(std::ostream& output, const Item& itemMessage);
	friend bool operator<(const Item& param1, const Item& param2); 
	friend int& operator+=(int& characteristic, const Item& Item);

private:
	Type classification; 
	int bonusValue;
};

#endif // !ITEM_H