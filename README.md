# COMP2113-Project

## Group Information
- **Group Number**: 56
- **Name**: Tsz Yi Lam 
- **Name**: Kin Shing Wong 
- **Game Name**: Bring back my Bonnie

## Game Description
The player, playing as a prince, would defeat monsters to get different items. When the player feels the prince's ability is high enough, the player would then challenge for the boss to save the princess, who was held hostage by the final boss.

## Rules
- The player has to defeat the boss and save the princess.
- Random Drops would be awarded to player when monsters are defeated.
- Attribute of monster/boss/prince would be classified into attack, defence and HP.
- To attack and defend, equipments are needed. This could be acheived from the random drops.
- The battling system is as follows:
  - Action of opponents would be classified into attack, defend, and recover HP, times for HP recovery is limited.
  - The action would be decided randomly.
  - The player's actions available is the same as the monsters.
  - In a game round, players would decide the prince's action from the 3 options.
  - The the action would be compared with the opponent's.
  - If both's option is "attack", damage would be dealt on both sides.
  - If one chose to "defend" and the other goes for "attack", the attack value would be subtracted by the defence value of the opponent. If the difference is positive, damage would be dealt. Else nothing happens in the round.
  - If both chose defend, nothing would happen in the round.
  - The HP of both sides would be checked after each round. The battle would be continued if both sides' HP is not 0.

## Features to implement
### Generation of random game sets or events
- Monsters are generated in random.
- Drop items are generated in random.

### Data structures for storing game status
- Vector are used to store the drop items.
- Vector are used to store prince's inventory.
- Vector are used to store ID of different monsters.
- Vector are used to store ID of different boss.
- Structs are used to hold items in the vector.
- Structs are used to store player's status.

### Dynamic memory management
- The inventory size would be dynamic.

### File input/output
- saving player's stats.
- loading player's status.
- saving player's inventory.
- loading player's inventory
- load monsters' attributes.
- load boss' attributes.

### Program codes in multiple files
- the main.cpp would be contain main function.
- the battle.h is used to load battle-related functions in the game.
- inventory.h is used to load inventory-related functions of the game.
- playerstatus.h us used to load player status-related functions of the game.
- randomMonster.h is used to load random monster id.
- headers.h is used to load Necessary headers for the files.

