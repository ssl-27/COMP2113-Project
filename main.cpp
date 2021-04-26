// Name: Lam Tsz Yi, Wong Kin Shing
// UID: 3035704825
// COMP2113 Project
// Title: Save my bonnie


#include <iostream>
#include <cctype>

using namespace std;

#include "randomMonster.h"
#include "inventory.h"
#include "playerstatus.h"
#include "battle.h"



int main(){
    int choice;
    //File input/output (e.g., for loading/saving game status)
    getMounted();
    getUserInfo();
    compileUser();
// start menu for the game
    cout << "Save my Bonnie. Be the hero kid. " << endl;
    cout << "Main menu: " << endl;
    cout << "1. Search for mobs." << endl;
    cout << "2. Fight the boss." << endl;
    cout << "3. Check inventory." << endl;
    cout << "4. Check player status." << endl;
    cout << "0. Exit." << endl;
    cout << "Your choice? ";
    cin >> choice;
    //use while loop to read the instruction, stops until "0" is inputed
    while (choice !=0 ){
        if (choice == 1){
            //jump to the battle function which generate monster
            //Generation of random game sets or events
            if(battle(randomMonster(), withItems) == true){        
                levelUp(10);
                //Dynamic memory management(inventory)
                dropinventory();
            }
        }
          //jump to the battle with the boss
        else if (choice == 2 ){
            if(battle(100, withItems) == true){
                levelUp(100);
                cout << "Bonnie Saved!" << endl;
            }
        }
        else if (choice == 3){
            // jump to the display inventory function
            cout << "" << endl;
            inventory();
        }
        else if (choice == 4){
            cout << "Your stats: " << endl;
            printUserInfo(base);
            cout << "Your stats with items mounted: " << endl;
            printUserInfo(withItems);
        }
        else {
            //verifcation for the input
            cout << "Wrong command!" << endl;
        }
        cout << "Main menu: " << endl;
        cout << "1. Search for mobs." << endl;
        cout << "2. Fight the boss." << endl;
        cout << "3. Check inventory." << endl;
        cout << "4. Check player status." << endl;
        cout << "0. Exit." << endl;
        cout << "Your choice? ";        
        cin >> choice;        
    }


}
