#include "Room.h"

// Default constructor definition
Room::Room()
    : name(""), description("") {
    }
// Constructor implementation
Room::Room(const std::string& name, const std::string& desc) : name(name), description(desc) {
}

// Add an item to the room
void Room::AddItem(const Item& item) {
    items.push_back(item);
}

// Add an exit to the room
void Room::AddExit(const std::string& direction, Room* destination) {
    exits[direction] = destination;
}

// Get the room in the specified direction
Room* Room::GetExit(const std::string& direction) {
    auto it = exits.find(direction);
    if (it != exits.end()) {
        // Return the pointer to the exit room
        return it->second;
    }
    return nullptr; // No exit in that direction
}

// Get description of the room
std::string Room::get_description() const {
    return description;
}
// Get name of the room
std::string Room::get_name() const {
	return name;
}

// Get list of items in the room
std::vector<Item> Room::getItemList() const {
    return items; // Simply return the items vector
}

// Remove item from room when added to inventory
void Room::RemoveItem(const Item& item) {
    for (auto it = items.begin(); it != items.end(); ++it) {
        if (it->get_item_name() == item.get_item_name()) {
            items.erase(it);
            break;
        }
    }
}
const std::map<std::string, Room*>& Room::getExits() const {
    return exits;
}
