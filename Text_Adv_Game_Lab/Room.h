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
		std::string description;
		std::map<std::string, Room*> exits;
		std::vector<Item> items;
	public:
		Room(const std::string& desc);
		void AddItem(const Item& item);
		void RemoveItem(const Item& item);

			
		

		

	};


