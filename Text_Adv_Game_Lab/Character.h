#pragma once
#include <string>
#include"Room.h"
#include "Item.h"

//class Item; // Forward declaration

	class Character {
	private:
		std::string name;
		int health;
		//std::vector<Item> inventory;
	public:
		Character() : name(""), health(0) {} // Default constructor
		Character(const std::string& name, int health);
		void TakeDamage(int damage);
		std::vector<Item> inventory;
	};
	
	class Player : public Character { // Inherit from Character
	private:
		Room* location;
	public:
		Player() : location(nullptr) {} // Default constructor
		Player(const std::string& name, int health);

		void set_location(Room* new_location);
		Room* get_location() const;
	};

