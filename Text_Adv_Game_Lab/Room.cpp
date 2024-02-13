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


