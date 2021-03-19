# COMP2113-Project

## Group Information
- **Group Number**: 56
- **Name**: Tsz Yi Lam 3035704825
- **Name**: Kin Shing Wong 

## Game Description
The player, playing as a prince, would defeat monsters to get the prince leveled up. When the player feels the prince's level is high enough, the player would then challenge for the boss to save the princess, who was held hostage by the final boss.

## Rules
- The player has to defeat monsters to get the prince leveled up.
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
  - If one goes for "HP recovery" and the other goes for "Defend", HP would be recovered for the recovery side and nothing would happen for the defence side.
  - If one goes for "attack" and one goes for "HP recovery", the HP would be recovered **BEFORE** the attack action.
  - The HP of both sides would be checked after each round. The battle would be continued if both sides' HP is not 0.

## Features to implement
### Generation of random game sets or events
- Monsters are generated in random.
- Drop items are generated in random.

### Data structures for storing game status
- Array would be used to store the drop items.
- Array would be used to store prince's inventory.
- Array would be used to store ID of different monsters.
- Array would be used to store ID of different boss.

### Dynamic memory management
- The inventory size would be dynamic.
- The drop item amount after each defeat of monster would be dynamic.

### Program codes in multiple files
- the main.cpp would be contain main function.
- the battle.cpp would be used to deploy the battling system.
- the gameFunctions.cpp would be used to manipulate other functions in the game.

