#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include "Character.h"  
#include "riddle_handler.h" 
using namespace std;

class CommandInterpreter {
private:
    Player* player; 
    RiddleHandler riddleHandler; 


public:
    // Constructor that accepts pointer to player object
    CommandInterpreter(Player* player) : player(player) {}
    //interpret commands
    void interpretCommand(const std::string& command) {
        // Parse the command string
        std::istringstream stream(command);
        std::string action;
        // read the action part of the command only
        //type of action tells progtam what to do (e.g. riddle, answer, hint)
        std::getline(stream, action, ' '); 
        //responses to possible actions
        if (action == "riddle") {
            riddleHandler.giveRiddle(player);
        }
        // player would enter:"answer piano" in order to read "piano" as answer
        else if (action == "answer") {
            std::string answer;
            std::getline(stream, answer);
            // remove leading whitespace to make sure the answer is read right
            riddleHandler.EnterAnswer(player, answer);
        }
        else if (action == "hint") {
            riddleHandler.giveHint(player);
        }
        // if action or command is not recognized, not if answer is wrong
        else {
            std::cout << " commad not recognised " << std::endl;
        }
    }

};


