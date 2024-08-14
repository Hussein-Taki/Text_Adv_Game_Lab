# Text Adventure Game

## Overview

This project is a simple text-based adventure game where players explore rooms, interact with items, solve riddles, and encounter non-player characters (NPCs). The game is designed with modularity in mind, allowing for easy extension and customization.

## Features

- **Room Navigation**: Players can move between connected rooms.
- **Item Interaction**: Players can interact with items found in rooms.
- **NPC Interaction**: Players can interact with NPCs that provide additional gameplay elements.
- **Riddle Solving**: Players can solve riddles presented by NPCs.
- **Command Interpretation**: Commands entered by players are processed to perform various actions.
- **Modular Design**: The game is built with a modular structure, making it easy to add new features and extend existing ones.

## File Structure

- `main.cpp`: The main entry point for the game.
- `Room.h/cpp`: Defines the `Room` class, which represents each room in the game.
- `Item.h/cpp`: Defines the `Item` class, which represents items that can be found in rooms.
- `ItemHandler.h/cpp`: Defines the `ItemHandler` class, which handles item interactions.
- `area.h/cpp`: Manages the overall game map, including room creation, item placement, and connections between rooms.
- `CommandInterpreter.h/cpp`: Processes and interprets player commands, translating them into actions within the game.
- `NPC.h/cpp`: Defines the `NPC` class, representing non-player characters that the player can interact with.
- `RiddleHandler.h/cpp`: Manages riddles presented to the player, including checking answers and providing feedback.
- `game_map.txt`: A text file that defines the rooms, items, NPCs, riddles, and connections in the game world.

## How to Use

### 1. Setting Up the Game Map

The game map is defined in the `game_map.txt` file. This file specifies the rooms, their descriptions, items, NPCs, riddles, and connections between rooms. The format is as follows:

- **Room Definition**: `<RoomName>|<RoomDescription>`
- **Item Definition**: `<RoomName>|<ItemName>|<ItemDescription>`
- **NPC Definition**: `<RoomName>|<NPCName>|<NPCDescription>`
- **Riddle Definition**: `<RoomName>|<RiddleQuestion>|<CorrectAnswer>`
- **Connection Definition**: `<Room1Name>|<Room2Name>|<Direction>`

Example:
```txt
startRoom|You are in the starting room.
startRoom|item1|A shiny key.
startRoom|npc1|A wise old man who offers a riddle.
startRoom|What has keys but can't open locks?|A piano
hallway|A long, dark hallway stretches before you.
startRoom|hallway|north
hallway|startRoom|south
```

### 2. Compiling and Running
```bash
g++ main.cpp Room.cpp Item.cpp ItemHandler.cpp area.cpp CommandInterpreter.cpp NPC.cpp RiddleHandler.cpp -o TextAdventureGame
./TextAdventureGame
```
### 3. Game Interaction
Once the game is running, you'll be presented with the current room's description, a list of items in the room, available exits, NPCs, and any riddles. You can choose to look around, interact with an item, talk to an NPC, answer a riddle, move to another room, or quit the game.
```yaml
Current Location: You are in the starting room.
Items in the room:
- item1: A shiny key
NPCs in the room:
- npc1: A wise old man who offers a riddle.
Riddle: What has keys but can't open locks?
Exits available: north
Options: 1. Look around | 2. Interact with an item | 3. Talk to an NPC | 4. Answer a riddle | 5. Move to another room | 6. Quit | 7. Enter Command Mode
>
```
## Class Descriptions
Room Class (Room.h)
The Room class represents a room in the game. Each room has:

A name and description.
A list of exits to other rooms.
A list of items contained in the room.
A list of NPCs in the room.
A riddle, if any, associated with the room.
Item Class (Item.h)
The Item class represents an item in the game. Each item has:

A name and description.
An Interact method to allow the player to interact with the item.
ItemHandler Class (ItemHandler.h)
The ItemHandler class manages item interactions within a room. It provides methods to:

List items in a room.
Interact with a specific item in the room.
NPC Class (NPC.h)
The NPC class represents a non-player character in the game. Each NPC has:

A name and description.
Dialogue or actions that occur when the player interacts with the NPC.
RiddleHandler Class (RiddleHandler.h)
The RiddleHandler class manages riddles presented to the player. It provides methods to:

Present a riddle to the player.
Check the player's answer.
Provide feedback based on the player's response.
CommandInterpreter Class (CommandInterpreter.h)
The CommandInterpreter class processes and interprets player commands. It translates the player's text input into actions within the game, such as moving between rooms, interacting with items, or talking to NPCs.

Area Class (area.h)
The Area class manages the entire game world, including:

Creating rooms and adding them to the game.
Placing items in rooms.
Adding NPCs and riddles to rooms.
Connecting rooms to each other.
Loading the game map from a file (game_map.txt).

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Contact
For any inquiries or suggestions, please contact Hussein Taki at h.taki@student.reading.ac.uk
