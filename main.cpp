#include <iostream>
#include <cctype>

using namespace std;

//#include "battle.h"
#include "randomMonster.h"
#include "inventory.h"



int main(){
    int choice;

    cout << "Save my Bonnie. Be the hero kid. " << endl;
    cout << "Main menu: " << endl;
    cout << "1. Search for mobs." << endl;
    cout << "2. Fight the boss." << endl;
    cout << "3. Check inventory." << endl;
    cout << "Your choice? ";
    cin >> choice;
    while (choice !=0 ){
        if (choice == 1){
            //battle(randomMonster());
        }
        else if (choice == 2 ){
            //battle(100);
        }
        else if (choice == 3){
            cout << "" << endl;
            inventory();
        }
        else {
            cout << "Wrong command!" << endl;
        }
        cout << "Main menu: " << endl;
        cout << "1. Search for mobs." << endl;
        cout << "2. Fight the boss." << endl;
        cout << "3. Check inventory." << endl;
        cout << "Your choice? ";        
        cin >> choice;        
    }


}