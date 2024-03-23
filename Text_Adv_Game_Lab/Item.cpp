#include "Item.h"
#include "Character.h"
using std::endl;

Item::Item(const std::string& name, const std::string& description)
{
}


// getters and setters for item description and name
void Item::set_description(const std::string& new_description){
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
    void Item::Interact(Character& character) {
        std::string pickup;
        std::cout << "Pick up " << get_item_name() << " ? y/n" << std::endl;
        std::cin >> pickup;
        if (pickup == "y") {
            std::cout << "You picked up " << get_item_name() << std::endl;
            // Create an Item object with the provided name and description
            Item newItem(get_item_name(), get_description());
            // Add the newly created item to the character's inventory
            character.inventory.push_back(newItem);
            // Optionally, remove the item from the room
            // room.remove_item(*this); // Assuming room has a remove_item function
        }
        else {
            std::cout << "You did not pick up " << get_item_name() << std::endl;
        }
    }

	

