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
    //call this function to read the inventory list
    readInventory();
    //use for loop to read the item
    for (iter = items.begin(); iter != items.end(); iter++){
        if (iter->mounted == 1){
            //store the item mounted in temp
            temp.mounted = iter->mounted;
            temp.effect = iter->effect;
            temp.id = iter->id;
            temp.name = iter->name;
            temp.type = iter->type;
            itemsMounted.push_back(temp);
            numMounted += 1;
            //counter of mounted item +1
        }
    }
}

//this function. is used to retrieved the player's information
void getUserInfo(){
    ifstream playerInfo;
    //open the playerstat.txt text file
    playerInfo.open("playerstat.txt");
    if (playerInfo.fail()){
        cout << "Error in file opening!" << endl;
        exit(1);
        //output error message if cannot open
    } 
    //read the player info into base
    playerInfo >> base.level >> base.atk >> base.def >> base.hp >> base.exp;
    //close the playerinfo text file
    playerInfo.close();
}

//this function is used to display the different value of the player after adding the mounted item
void printUserInfo(player type){
    cout << "Level: " << type.level << endl;
    cout << "Attack: " << type.atk << endl;
    cout << "Defence: " << type.def << endl;
    cout << "HP: " << type.hp << endl;
    cout << "Experience: " << type.exp << endl;
    cout << "" << endl;
    
}
//the function below is used to calculate the player's attack defense and health point adding the mounted item effect
void compileUser(){
    //if number of mounted item is 0 then nothing need to be process
    if (numMounted == 0){
        //so the withitem value is the same as the player base
        withItems = base;
        cout << numMounted;
    }
    else {
        //use for loop to read and search the item that is mounted
        for (iter = itemsMounted.begin(); iter != itemsMounted.end(); iter++){
            if (iter->type == 0) // weapon
            {
                withItems = base;
                //adding the attack value of mounted item which it's type is attack
                withItems.atk = base.atk * (1 + iter->effect / 10 );
            }
            else if (iter->type == 1) // shield
            {
                withItems = base;
                //adding the attack value of mounted item which it's type is defense
                withItems.def = base.def * (1 + iter->effect / 10 );
            }       
            else if (iter->type == 2) // armor
            {
                withItems = base;
                //adding the attack value of mounted item which it's type is health
                withItems.hp = base.hp * (1 + iter->effect / 10 );
            }                 
        }
    }
    
}


