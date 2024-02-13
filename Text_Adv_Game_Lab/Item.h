#pragma once
#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;
class Item
{
private:
	std::string item_name;// item_name so as to avoid mix up with character name, as character.h in included in item.h
	std::string description;
public:
	Item(const std::string& name, const std::string& description);
	void Interact();	
	
	void set_description(const std::string& new_description);
	string get_description() const;

	void set_item_name(const std::string& new_item_name);
	string get_item_name() const;
	
};


