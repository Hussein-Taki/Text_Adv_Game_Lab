#include "Character.h"
#include "Room.h"

void Player::set_location(Room* new_location) {
	location = new_location;
}

Room* Player::get_location() const {
	return location;
}


