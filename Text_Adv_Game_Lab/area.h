// area.h
#pragma once
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "Room.h"
#include "Item.h"

class Area {
private:
    std::map<std::string, Room> rooms;

public:
    Area() = default;
    ~Area() = default;

    void AddRoom(const std::string& name, const std::string& description);
    void AddItemToRoom(const std::string& roomName, const std::string& itemName, const std::string& itemDescription);
    Room& GetRoom(const std::string& name);
    void ConnectRooms(const std::string& room1Name, const std::string& room2Name, const std::string& direction);
    void LoadMapFromFile(const std::string& filename);
    static inline std::string& trim(std::string& s) {
        s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
            return !std::isspace(ch);
            }));
        s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
            return !std::isspace(ch);
            }).base(), s.end());
        return s;
    }
};
