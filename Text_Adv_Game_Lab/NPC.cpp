#include "NPC.h"
#include "Character.h"
#include <iostream>
//cosntructor
NPC::NPC() : currentState(Idle), wrongAnswers(0) {}
//resets the squirrel
void NPC::reset() {
    currentState = Idle;
    wrongAnswers = 0;
}
//get state of squirrel
NPC::State NPC::getState() const {
    return currentState;
}

// agrressive state in twighlightRoom and treasureRoom
void NPC::specialState(const std::string& roomName) {
    currentRoom = roomName;
    //squirell starts agrressive and deals more damage in these 2 rooms
    if (currentRoom == "twighlightRoom" || "treasureRoom") {
        currentState = Aggressive;
    }
    //in all other rooms squirell starts idle, gets aggressive if wrong answer given
    else {
        if (currentState != Fleeing && currentState != AskingRiddle) {
            if (wrongAnswers > 0) {
                currentState = Aggressive;
            }
            else {
                currentState = Idle;
            }
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
//if answer is right or wrong
bool NPC::answerRiddle(Player* player, const std::string& answer) {
    if (currentState == AskingRiddle) {
        //if answer is right
        if (riddleHandler.EnterAnswer(player, answer)) {
            std::cout << "The squirrel shocked by your wisdom and flees." << std::endl;
            currentState = Fleeing;
            return true;
        }
        else {
            std::cout << "The squirrel grows more aggressive...it takes a swipe at you with its blood stained claws" << std::endl;
            wrongAnswers++;
            int damagePercent = 30;
            // Check if important room where damage is 50 not 30
            if (currentRoom == "twighlightRoom" || currentRoom == "treasureRoom") {
				damagePercent = 50;
			}
            // Calculate damage based on player's health
            int damageAmount = int(player->get_health() * (damagePercent / 100.0));
            //deal damage 
            player->TakeDamage(damageAmount);
            // display damage and state
            std::cout << "You've taken " << damageAmount << " damage." << std::endl;
            currentState = Aggressive;
            return false;
        }
    }
    return false;
}


