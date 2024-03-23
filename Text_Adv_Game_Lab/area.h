#pragma once
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "Room.h"

class Area {
private:
    // Map of room names to Room objects
    std::map<std::string, Room> rooms;

public:
    // Constructor and destructor
    Area() = default;
    ~Area() = default;
    // Add a room to the area
    void AddRoom(const std::string& name, const std::string& description);
    // Get a room by its name
    Room& GetRoom(const std::string& name);
    // Connect two rooms together
    void ConnectRooms(const std::string& room1Name, const std::string& room2Name, const std::string& direction);
    // Load a map from game_map.txt
    void LoadMapFromFile(const std::string& filename);
    // Trim whitespace from string from game_map.txt
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
