#include <fstream>
#include <vector>
using namespace std;
//initalize a data structure storing player's attack denfense and health points and the level
struct player
{
    int level;
    float atk, def,hp, exp;
};

player base;
player withItems;
vector <inventory_item> itemsMounted;
inventory_item temp;
vector <inventory_item>:: iterator iter;
int numMounted = 0;

void getMounted(){
    readInventory();
    for (iter = items.begin(); iter != items.end(); iter++){
        if (iter->mounted == 1){
            temp.mounted = iter->mounted;
            temp.effect = iter->effect;
            temp.id = iter->id;
            temp.name = iter->name;
            temp.type = iter->type;
            itemsMounted.push_back(temp);
            numMounted += 1;

        }
    }
}

void getUserInfo(){
    ifstream playerInfo;
    playerInfo.open("playerstat.txt");
    if (playerInfo.fail()){
        cout << "Error in file opening!" << endl;
        exit(1);
    } 
    playerInfo >> base.level >> base.atk >> base.def >> base.hp >> base.exp;
    playerInfo.close();
}

void printUserInfo(player type){
    cout << "Level: " << type.level << endl;
    cout << "Attack: " << type.atk << endl;
    cout << "Defence: " << type.def << endl;
    cout << "HP: " << type.hp << endl;
    cout << "Experience: " << type.exp << endl;
    cout << "" << endl;
    
}

void compileUser(){
    if (numMounted == 0){
        withItems = base;
        cout << numMounted;
    }
    else {
        for (iter = itemsMounted.begin(); iter != itemsMounted.end(); iter++){
            if (iter->type == 0) // weapon
            {
                withItems = base;
                withItems.atk = base.atk * (1 + iter->effect / 10 );
            }
            else if (iter->type == 1) // shield
            {
                withItems = base;
                withItems.def = base.def * (1 + iter->effect / 10 );
            }       
            else if (iter->type == 2) // armor
            {
                withItems = base;
                withItems.hp = base.hp * (1 + iter->effect / 10 );
            }                 
        }
    }
    
}


