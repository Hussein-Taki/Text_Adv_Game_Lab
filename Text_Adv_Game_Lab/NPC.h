#pragma once
#include <string>
#include "Character.h"  
#include "riddle_handler.h"  

class NPC {
public:
    enum State { Idle, AskingRiddle, Aggressive, Fleeing };

private:
    State currentState;
    int wrongAnswers;
    RiddleHandler riddleHandler;
    std::string currentRoom;

public:
    NPC();
    void specialState(const std::string& roomName);
    void askRiddle(Player* player);
    bool answerRiddle(Player* player, const std::string& answer);
    void reset();
    State getState() const;
};

