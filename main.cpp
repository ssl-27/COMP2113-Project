#include <iostream>
#include <cctype>
#include "battle.h"
#include "randomMonster.h"
#include "inventory.h"

using namespace std;

int main(){
    int choice;

    cout << "Save my Bonnie. Be the hero kid. " << endl;
    cout << "1. Search for mobs." << endl;
    cout << "2. Fight the boss." << endl;
    cout << "3. Check inventory." << endl;
    cout << "Your choice?";
    cin >> choice;
    while (choice != 1 || choice != 2 || choice != 3 || choice != 0 ){
        cout << "Wrong command!";
        cin >> choice;
    }
    if (choice == 1){
        battle(randomMonster());
    }
    else if (choice == 2 ){
        battle(100);
    }
    else if (choice == 3){
        inventory();
    }
    main();
    if (choice == 0){
        return 0;
    }

}