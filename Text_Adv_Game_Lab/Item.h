#pragma once
#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;


class Character; // Forward declaration

class Item
{
private:
    std::string item_name;
    std::string description;
public:
    Item(const std::string& name, const std::string& description);
    void Interact(Character& character);

    void set_description(const std::string& new_description);
    string get_description() const;

    void set_item_name(const std::string& new_item_name);
    string get_item_name() const;
};
