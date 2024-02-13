#include <iostream>
#include <vector>
#include <map>
#include "Character.h"
#include "Item.h"
#include "Room.h"
// Include the Room and Item classes (assuming they are defined in separate files, which they should be!)
int main() {
	// Create Rooms
	Room startRoom("You are in a dimly lit room.");
	Room hallway("You are in a long hallway.");
	Room treasureRoom("You have entered a treasure room!");
	// Define exits between rooms
	startRoom.AddExit("north", &hallway);
	hallway.AddExit("south", &startRoom);
	hallway.AddExit("north", &treasureRoom);
	treasureRoom.AddExit("south", &hallway);
	// Create Items
	Item key("Key", "A shiny key that looks important.");
	Item sword("Sword", "A sharp sword with a golden hilt.");
	// Add items to rooms
	startRoom.AddItem(key);
	treasureRoom.AddItem(sword);
	// Create a Player
	Player player("Alice", 100);
	// Set the player's starting location
	player.set_location(&startRoom);
	// Game loop (basic interaction)
	while (true) {
		std::cout << "Current Location: " << player.get_location() -> GetDescription() << std::endl;
		std::cout << "Items in the room:" << std::endl;
		for (const Item& item : player.get_location()->GetItems()) {
			std::cout << "- " << item.get_item_name() << ": " <<
				item.get_description() << std::endl;
		}
		std::cout << "Options: ";
		std::cout << "1. Look around | ";
		std::cout << "2. Interact with an item | ";
		std::cout << "3. Move to another room | ";
		std::cout << "4. Quit" << std::endl;
		int choice;
		std::cin >> choice;
		if (choice == 1) {
			// Player looks around (no action required)
			std::cout << "You look around the room." << std::endl;
		}
		else if (choice == 2) {
			// Player interacts with an item in the room
			std::cout << "Enter the name of the item you want to interact with: ";
				std::string itemName;
			std::cin >> itemName;
			for (Item& item : player.get_location()->GetItems()) {
				if (item.get_item_name() == itemName) {
					item.Interact();
					break;
				}
			}
		}
		else if (choice == 3) {
			// Player moves to another room
			std::cout << "Enter the direction (e.g., north, south): ";
			std::string direction;
			std::cin >> direction;
			Room* nextRoom = player.get_location()->GetExit(direction);
			if (nextRoom != nullptr) {
				player.set_location(nextRoom);
				std::cout << "You move to the next room." << std::endl;
			}
			else {
				std::cout << "You can't go that way." << std::endl;
			}
		}
		else if (choice == 4) {
			// Quit the game
			std::cout << "Goodbye!" << std::endl;
			break;
		}
		else {
			std::cout << "Invalid choice. Try again." << std::endl;
		}
	}
	return 0;
}