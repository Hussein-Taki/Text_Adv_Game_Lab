#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include "Character.h"  
#include "riddle_handler.h" 
using namespace std;

class CommandInterpreter {
public:
    CommandInterpreter(Player* player) : player_(player) {}

    void interpretCommand(const std::string& command) {
        std::istringstream stream(command);
        std::string action;
        std::getline(stream, action, ' '); // Extract the action part of the command

        if (action == "riddle") {
            riddleHandler.presentRiddle(player_);
        }
        else if (action == "answer") {
            std::string answer;
            std::getline(stream, answer); // Extract the rest of the command as the answer
            riddleHandler.EnterAnswer(player_, answer);
        }
        else if (action == "hint") {
            riddleHandler.provideHint(player_);
        }
        // if action or command is not recognized
        else {
            std::cout << " commad not recognised "<< std::endl; 
        }
    }

private:
    Player* player_; // Pointer to the player object
    RiddleHandler riddleHandler; // Instance of RiddleHandler for riddle-related commands
};

