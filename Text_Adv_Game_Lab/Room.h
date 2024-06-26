#pragma once
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "Item.h"
using namespace std;
class Room

{
	
private:
	std::string name;       
	std::string description;
	std::map<std::string, Room*> exits;
	std::vector<Item> items;
public:
	Room();
	Room(const std::string& name, const std::string& desc);
	void AddItem(const Item& item);
	void RemoveItem(const Item& item);

	// exit setters (adders) and getters	
	void AddExit(const std::string& direction, Room* destination);
	Room* GetExit(const std::string& direction);

	//get_description
	std::string get_description() const;
	//get_name
	std::string get_name() const;


	//get_item
	std::vector<Item> get_item() const;
	
	//list item names and descriptions in vector of strings
	std::vector<Item> getItemList() const; // Vector of Item objects
	//vector of strings so compatible with main.cpp
	//std::vector<std::string> getItemList() const;
	const std::map<std::string, Room*>& getExits() const; // Map of all available exits
};