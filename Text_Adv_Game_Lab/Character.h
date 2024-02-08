#pragma once
#include <string>
#include"Room.h"

	class Character {
	private:
		std::string name;
		int health;
		std::vector<Item> inventory;
	public:
		Character(const std::string& name, int health);
		void TakeDamage(int damage);
	};
	class Player : public Character {
	private:
		Room* location;
	public:
		Player(const std::string& name, int health);

		void set_location(Room* new_location);
		Room* get_location() const;

		
	

};

