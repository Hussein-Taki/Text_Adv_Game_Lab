#include "Room.h"
#include "Item.h"

//constructor
Room::Room(const std::string& desc){

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

//get description
std::string Room::get_description() const {
	return description;
}
//instead of get item, a function to list names and descriptions of all items in a room
//vector of strings so compatible with main.cpp
std::vector<std::string> Room::getItemList() const {
    std::vector<std::string> itemList;
    for (const Item& item : items) {
        std::string itemInfo = "Name: " + item.get_item_name() + ", Description: " + item.get_description();
        itemList.push_back(itemInfo);
    }
    return itemList;
}



//remove item from room when added to inventory
void Room::RemoveItem(const Item& item) {
    for (auto it = items.begin(); it != items.end(); ++it) {
        if (it->get_item_name() == item.get_item_name()) {
			items.erase(it);
			break;
		}
	}
}




