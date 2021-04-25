#include <iostream>
#include <cctype>

using namespace std;

#include "randomMonster.h"
#include "inventory.h"
#include "playerstatus.h"
#include "battle.h"



int main(){
    int choice;
    getMounted();
    getUserInfo();
    compileUser();

    cout << "Save my Bonnie. Be the hero kid. " << endl;
    cout << "Main menu: " << endl;
    cout << "1. Search for mobs." << endl;
    cout << "2. Fight the boss." << endl;
    cout << "3. Check inventory." << endl;
    cout << "4. Check player status." << endl;
    cout << "0. Exit." << endl;
    cout << "Your choice? ";
    cin >> choice;
    while (choice !=0 ){
        if (choice == 1){
            cout << battle(randomMonster(), withItems) << endl;
        }
        else if (choice == 2 ){
            cout << battle(100, withItems) << endl;
        }
        else if (choice == 3){
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