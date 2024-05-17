// area.cpp
#include "area.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cctype>
#include <locale>

void Area::AddRoom(const std::string& name, const std::string& description) {
    if (rooms.find(name) == rooms.end()) {
        rooms[name] = Room(name, description); // Assumes Room constructor taking description
    }
}

void Area::AddItemToRoom(const std::string& roomName, const std::string& itemName, const std::string& itemDescription) {
    if (rooms.find(roomName) != rooms.end()) {
        rooms[roomName].AddItem(Item(itemName, itemDescription)); // Assumes Room::AddItem method
    }
    else {
        std::cerr << "Error: Attempting to add item to non-existing room '" << roomName << "'." << std::endl;
    }
}

Room& Area::GetRoom(const std::string& name) {
    return rooms.at(name); // Use at() for direct access with bound checking
}

void Area::ConnectRooms(const std::string& room1Name, const std::string& room2Name, const std::string& direction) {
    if (rooms.find(room1Name) != rooms.end() && rooms.find(room2Name) != rooms.end()) {
        Room& room1 = GetRoom(room1Name);
        Room& room2 = GetRoom(room2Name);
        room1.AddExit(direction, &room2); // Assumes Room::AddExit accepts a direction and Room pointer
    }
    else {
        std::cerr << "Error: Attempting to connect non-existing rooms '" << room1Name << "' and '" << room2Name << "'." << std::endl;
    }
}

void Area::LoadMapFromFile(const std::string& filename) {
    std::ifstream file(filename);
    std::string line;

    while (getline(file, line)) {
        std::istringstream iss(line);
        std::string part1, part2, part3, part4;
        std::getline(iss, part1, '|');
        std::getline(iss, part2, '|');
        std::getline(iss, part3, '|');
        std::getline(iss, part4);

        part1 = trim(part1);
        part2 = trim(part2);
        part3 = trim(part3);
        part4 = trim(part4);

        if (part3.empty() && part4.empty()) {
            // This line defines a room and its description
            AddRoom(part1, part2);
        }
        else if (part3.empty()) {
            // This line is invalid because it must have at least 3 parts to define a connection or an item
            std::cerr << "Error: Invalid line format in map file: " << line << std::endl;
        }
        else if (part4.empty() && rooms.find(part1) != rooms.end() && rooms.find(part2) != rooms.end()) {
            // This line defines a connection between rooms
            ConnectRooms(part1, part2, part3);
        }
        else {
            // This line defines an item in a room
            AddItemToRoom(part1, part2, part3);
        }
    }
}
