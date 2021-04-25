#include "headers.h"
#include <fstream>


//create a data structure which consist of the monster's basic data
struct monster
{
    int id;
    string name;
    float atk, def, hp;
    //id is the primary key for the monster
    //name is the display name of the monster
    //atk stands for the attack value
    //def stands for the  defense value
    //hp stands for the health points
};

//use vector to store the monster's data

vector <monster> monsterInfo;
monster monstertemp;
vector <monster>:: iterator monsteriter;


void readMonster(){
    ifstream monster;
    monster.open("monsters.txt");
//open txt file of monster
    if (monster.fail()){
        cout << "Error!";
        exit(1);
    }
//read the monster.txt file to access the monster's basic data
    while (monster.eof() != 1){
        monster >> monstertemp.id >> monstertemp.name >> monstertemp.atk >> monstertemp.def >> monstertemp.hp;
        monsterInfo.push_back(monstertemp);
    }
//close the textt file of monster.txt
    monster.close();

}

//the demage function is used to calculate the health point of player and monster
void damage(float pdamage, float mdamage, float &mHp, float &pHp){
        cout << "Damage you dealt: " << mdamage << endl; 
        cout << "Your damage received; " << pdamage << endl;
        pHp -= pdamage;
        mHp -= mdamage;
}

bool battle(int monster_id, player withItems){
    readMonster();
    monster battleMonster;
    //use for loop to search for the target monster retrieved from the monster file
    for (monsteriter = monsterInfo.begin(); monsteriter != monsterInfo.end(); monsteriter++){
        if (monsteriter->id == monster_id){
            battleMonster.id = monsteriter->id;
            battleMonster.name = monsteriter->name;
            battleMonster.hp = monsteriter->hp;
            battleMonster.def = monsteriter->def;
            battleMonster.atk = monsteriter->atk;
        }
        
    }

    cout << "Your opponent is " << battleMonster.name << endl;
//Initializing variables for storing the monster and player basic info
    float mAtk, mDef, mHp, pAtk, pDef, pHp;
    //load the monster attack defense and health point
    mAtk = battleMonster.atk;
    mDef = battleMonster.def;
    mHp = battleMonster.hp;
    //load the player attack defense and health point
    pAtk = withItems.atk;
    pDef = withItems.def;
    pHp = withItems.hp;
//use while loop to make the battle stops whenever one side health points below zero
    while (mHp > 0 && pHp > 0){
        int pAtkdef, mAtkdef;
        float pdamage, mdamage;
        //display both side health point first
        cout << "Your HP: " << pHp << endl;
        cout << battleMonster.name << "'s HP: " << mHp << endl;
        cout << "Instruction: Your opponent would attack or defend in random. You may choose to 1. Attack or 2. Defend. Please type your option and hit enter." << endl;
        //read the player decision on attack or defense
        cin >> pAtkdef;
        //here random generate a value from 1 or 2 to represent the monster decide to attack or defense
        mAtkdef = rand()%2 + 1;
        //Illustrate different situation of the battle
        if (pAtkdef == 1 && mAtkdef == 1){
            pdamage = mAtk;
            mdamage = pAtk;
            damage (pdamage, mdamage, mHp, pHp);
        }
        //this case player side will take the damage by monster minus player defense value
        else if (pAtkdef == 2 && mAtkdef == 1){
            mdamage = 0;
            pdamage = mAtk - pDef;
            damage (pdamage, mdamage, mHp, pHp);
        }
        //this case player side will take the damage by player minus monster defense value
        else if (pAtkdef == 1 && mAtkdef == 2){
            mdamage = pAtk - mDef;
            pdamage = 0;
            damage (pdamage, mdamage, mHp, pHp);
        }
        //both side decide to defense, so no damage
        else if (pAtkdef == 0 && mAtkdef == 0)
        {
            mdamage = 0;
            pdamage = 0;
            damage (pdamage, mdamage, mHp, pHp);
        }
        
    }
//this part will return true or false to the main function to tell whether player wins or not
    if (pHp != 0){
        cout << "You win! You have " << pHp <<" HP left. " << endl;
        return true;
    }
    else {
        cout << "Your HP is empty! You lose! " << endl;
        return false;
    }

}
