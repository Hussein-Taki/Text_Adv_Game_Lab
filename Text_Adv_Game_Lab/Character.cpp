#include "Character.h"
#include "Room.h"

// Constructor for Player class
Player::Player(const std::string& name, int health)
    : Character(name, health), location(nullptr) {
}

void Player::set_location(Room* new_location) {
    location = new_location;
}

Room* Player::get_location() const {
    return location;
}

// Constructor for Character class
Character::Character(const std::string& name, int health)
    : name(name), health(health) {
    
}

// Function to make the character take damage
void Character::TakeDamage(int damage) {
    // Subtract damage from health
    health -= damage;
    
}

// Function to add an item to the character's inventory
void Character::AddItem(const Item& item) {
	// Add the item to the inventory vector
	inventory.push_back(item);
}