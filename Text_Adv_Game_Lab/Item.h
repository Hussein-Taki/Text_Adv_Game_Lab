#pragma once
#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;
class Item
{
private:
	std::string name;
	std::string description;
public:
	Item(const std::string& name, const std::string& description):
	void Interact();
	
	void set_description(const std::string& new_description);
	string get_description() const;
};


