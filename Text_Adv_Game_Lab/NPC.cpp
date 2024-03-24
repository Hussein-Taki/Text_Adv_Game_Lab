#include "NPC.h"
#include "Character.h"
#include <iostream>
//cosntructor
NPC::NPC() : currentState(Idle), incorrectAnswers(0) {}
//resets the squirrel
void NPC::reset() {
    currentState = Idle;
    incorrectAnswers = 0;
}
//get state of squirrel
NPC::State NPC::getState() const {
    return currentState;
}


void NPC::update(const std::string& roomName) {
    currentRoom = roomName;
    //squirell starts agrressive and deals more damage in these 2 rooms
    if (currentRoom == "twighlightRoom" || "treasureRoom") {
        currentState = Aggressive;
    }
    //in all other rooms squirell starts idle
    else {
        if (currentState != Fleeing && currentState != AskingRiddle) {
            currentState = (incorrectAnswers > 0) ? Aggressive : Idle;
        }
    }
}
//ask riddle
void NPC::askRiddle(Player* player) {
    if (currentState == Idle || currentState == Aggressive) {
        std::cout << "A giant mutated squirrel appears and asks you a riddle..." << std::endl;
        riddleHandler.giveRiddle(player);
        currentState = AskingRiddle;
    }
}
//answer riddle correctly or incorrectly
bool NPC::answerRiddle(Player* player, const std::string& answer) {
    if (currentState == AskingRiddle) {
        if (riddleHandler.EnterAnswer(player, answer)) {
            std::cout << "The squirrel shocked by your wisdom and flees." << std::endl;
            currentState = Fleeing;
            return true;
        }
        else {
            std::cout << "The squirrel grows more aggressive." << std::endl;
            incorrectAnswers++;

            // Check if NPC is in an important room 
            int damagePercentage = currentRoom == "twighlightRoom" ? 50 : 30;
            int damageAmount = static_cast<int>(player->get_health() * (damagePercentage / 100.0));
            //deal damage 
            player->TakeDamage(damageAmount);
            std::cout << "You've taken " << damageAmount << " damage." << std::endl;
            currentState = Aggressive;
            return false;
        }
    }
    return false;
}


