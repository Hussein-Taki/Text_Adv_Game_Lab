#include <iostream>
#include <vector>
#include <map>
#include "Character.h"
#include "Item.h"
#include "Room.h"
#include "Area.h" 
#include "CommandInterpreter.h"
#include "riddle_handler.h"
/*
int main() {
    Area gameArea;
    gameArea.LoadMapFromFile("game_map.txt"); // Load the game area from a file

    // Initialize player with the name "Alice" and 100 health points
    Player player("Alice", 100);

    // Set the player's starting location based on the room retrieved from gameArea
    try {
        Room& startRoom = gameArea.GetRoom("startRoom"); // Use the new GetRoom method returning a Room reference
        player.set_location(&startRoom);
    }
    catch (const std::out_of_range& e) {
        std::cerr << "Error setting initial location: " << e.what() << '\n';
        return 1; // Exit the game if the starting room cannot be found
    }

    // Game loop
    while (true) {
        // Display current location, available items, and exits
        std::cout << "Current Location: " << player.get_location()->get_description() << std::endl;
        std::cout << "Items in the room:" << std::endl;
        for (const Item& item : player.get_location()->getItemList()) {
            std::cout << "- " << item.get_item_name() << ": " << item.get_description() << std::endl;
        }

        // New: Display available exits
        std::cout << "Exits available: ";
        for (const auto& exit : player.get_location()->getExits()) {
            std::cout << exit.first << " ";
        }
        std::cout << "\nOptions: ";
        std::cout << "1. Look around | ";
        std::cout << "2. Interact with an item | ";
        std::cout << "3. Move to another room | ";
        std::cout << "4. Quit" << std::endl;

        // Handle player input
        int choice;
        std::cin >> choice;
        switch (choice) {
        case 1:
            std::cout << "You look around the room." << std::endl;
            break;
        case 2: {
            std::cout << "Enter the name of the item you want to interact with: ";
            std::string itemName;
            std::cin >> itemName;
            bool found = false;
            for (Item& item : player.get_location()->getItemList()) {
                if (item.get_item_name() == itemName) {
                    item.Interact(player);
                    found = true;
                    break;
                }
            }
            if (!found) {
                std::cout << "Item not found." << std::endl;
            }
            break;
        }
        case 3: {
            std::cout << "Enter the direction (e.g., north, south): ";
            std::string direction;
            std::cin >> direction;
            Room* nextRoom = player.get_location()->GetExit(direction);
            if (nextRoom) {
                player.set_location(nextRoom);
                std::cout << "You move to the next room." << std::endl;
            }
            else {
                std::cout << "You can't go that way." << std::endl;
            }
            break;
        }
        case 4:
            std::cout << "Goodbye!" << std::endl;
            return 0;
        default:
            std::cout << "Invalid choice. Try again." << std::endl;
            break;
        }
    }

    return 0;
}
*/
int main() {
    Player player; // Assumes Player has a default constructor
    CommandInterpreter interpreter(&player); // Assumes CommandInterpreter takes a Player pointer

    std::cout << "Welcome to the game! Enter commands to interact with the game world." << std::endl;
    std::cout << "Type 'quit' to exit the game." << std::endl;

    std::string command;
    while (true) {
        std::cout << "> ";
        std::getline(std::cin, command);

        // Check for the quit command to exit the loop
        if (command == "quit") {
            std::cout << "Thank you for playing. Goodbye!" << std::endl;
            break;
        }

        // Process the entered command
        interpreter.interpretCommand(command);
    }

    return 0;
}
