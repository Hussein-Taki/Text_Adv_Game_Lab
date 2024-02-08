#include "Item.h"
using std::endl;

// getters and setters for item description and name
void Item::set_description(std::string& new_description){
    description = new_description;
}

std::string Item::get_description()const {
    return description;
}
   
void Item::set_item_name(const std::string & new_name) {
		item_name = new_name;
	}
    std::string Item::get_item_name() const {
        return item_name;
    }
    
// function for player to choose to pick up item or not
void Item::Interact() {
    std::string pickup;
		std::cout << "Pick up  " << item_name << " ? y/n" << endl;
        std::cin >> pickup;
        if (pickup == "y") {
			std::cout << "You picked up " << item_name << endl;
            //add to item to inventory vector
            return Item;
          //  std::vector<Item> inventory;
            //inventory.push_back(Item);

		}
        else {
			std::cout << "You did not pick up " << item_name << endl;
		}
	}
// dont do that, dont include chracter in item, make it all happen in main , so in main the player intercts with an item, picks it up which passes it to the character, the character then adds it to inventory, you also want to telll the room to remove item from room so its nnot tstill there when you pick it up