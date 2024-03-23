#pragma once
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "Character.h"
using namespace std;
class RiddleHandler {
public:
    void presentRiddle(Player* player) {
        // Present riddle to player
        std::cout << "Riddle: What has keys but can't open locks? you may ask for a hint by typing 'hint'\n type 'answer' then your answer" << std::endl;
    }

    bool EnterAnswer(Player* player, const std::string& answer) {
        // Check the player's answer
        if (answer == "piano") {
            std::cout << "Correct answer!" << std::endl;
            return true;
        }
        else {
            std::cout << "Wrong answer. Try again!" << std::endl;
            return false;
        }
    }

    void provideHint(Player* player) {
        // Provide a hint for the current riddle
        std::cout << "Hint: It's a musical instrument." << std::endl;
    }
};
