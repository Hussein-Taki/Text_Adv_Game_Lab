#include <iostream>
#include <vector>
#include <map>
#include "Character.h"
#include "Item.h"
#include "Room.h"
#include "Area.h"
#include "CommandInterpreter.h" 
#include "NPC.h"

int main() {
    // Load the game area from game_map.txt
    Area gameArea;
    gameArea.LoadMapFromFile("game_map.txt");
    // Initialize player with the name and 100 health points
    Player player("Zeus", 100);
    // Initialize CommandInterpreter with pointer player
    CommandInterpreter interpreter(&player);
    // Initialize the NPC for giant mutated squirrel
    NPC squirrel;

    // Set starting location
    // try catch for recurring error of room not found
    try {
        Room& startRoom = gameArea.GetRoom("startRoom");
        player.set_location(&startRoom);
        // set NPC room to players starting room
        squirrel.update(startRoom.get_name());
    }
    catch (const std::out_of_range& e) {
        std::cerr << "Error setting initial location: " << e.what() << '\n';
        return 1; // Exit the game if the starting room cannot be found
    }

    // Main game loop
    std::string command;
    while (true) {
        std::cout << "Current Location: " << player.get_location()->get_description() << std::endl;

        // NPC state based on current room 
        // dont ask riddle if player is in startRoom
        if (player.get_location()->get_name() != "startRoom") {

            if (squirrel.getState() == NPC::Idle || squirrel.getState() == NPC::Aggressive) {
                //Squirrel will ask riddle 
                squirrel.askRiddle(&player);
                std::cout << "Answer the riddle: ";
                std::getline(std::cin, command);
                if (command != "quit" && command != "exit" && command != "5") {
                    if (!squirrel.answerRiddle(&player, command)) {
                        std::cout << "Incorrect. Your health: " << player.get_health() << std::endl;
                    }
                    else {
                        std::cout << "Correctly answered the riddle!" << std::endl;
                        // Squirrel state reset to Idle once the riddl answered correctly
                        squirrel.reset();
                    }
                    // Continue to next iteration of loop
                    continue;
                }
            }
        }
        // Display available items and exits 
        std::cout << "Items in the room:" << std::endl;
        for (const Item& item : player.get_location()->getItemList()) {
            std::cout << "- " << item.get_item_name() << ": " << item.get_description() << std::endl;
        }
        std::cout << "Exits available: ";
        for (const auto& exit : player.get_location()->getExits()) {
            std::cout << exit.first << " ";
        }
 
        // Display options 
        std::cout << "\nOptions: ";
        std::cout << "1. Look around | 2. Interact with an item | 3. Move to another room | 4. Quit | 5. Enter Command Mode\n> ";
        // Get user input
        std::getline(std::cin, command);
        //cases for user input
        if (command == "4") {
            std::cout << "Goodbye!" << std::endl;
            break;
        }
        else if (command == "5") {
            std::cout << "Entering command mode. Type 'exit' to return." << std::endl;
            while (true) {
                std::cout << "cmd> ";
                std::getline(std::cin, command);
                if (command == "exit") {
                    break;
                }
                interpreter.interpretCommand(command);
            }
            continue; // Skip the rest of the loop and prompt again
        }
        else if (command == "1") {
            // This is where you would re-display the current location's description and items
            continue; 
        }
        else if (command == "2") {
            std::cout << "Enter the name of the item you want to interact with: ";
            std::string itemName;
            std::getline(std::cin, itemName);
            bool found = false;
            // interact with item
            for (const Item& item : player.get_location()->getItemList()) {
                if (item.get_item_name() == itemName) {
                    std::cout << "You interact with the " << itemName << "." << std::endl;
                    // Add the item to the player's inventory
                    player.AddItem(item);
                    // Remove the item from the room
                    player.get_location()->RemoveItem(item);
                    found = true;
                    break;
                }
            }
            continue;
        }
        else if (command == "3") {
            std::cout << "Enter the direction (e.g., north, south): ";
            std::string direction;
            std::getline(std::cin, direction);
            Room* nextRoom = player.get_location()->GetExit(direction);
            if (nextRoom) {
                player.set_location(nextRoom);
                std::cout << "You move to the next room." << std::endl;
            }
            else {
                std::cout << "You can't go that way." << std::endl;
            }
            continue;
        }
        else {
            std::cout << "Invalid option. Please try again." << std::endl;
        }
    }

    return 0;
}


