#include "headers.h"
#include <fstream>



struct monster
{
    int id;
    string name;
    float atk, def, hp;
};

vector <monster> monsterInfo;
monster monstertemp;
vector <monster>:: iterator monsteriter;


void readMonster(){
    ifstream monster;
    monster.open("monsters.txt");

    if (monster.fail()){
        cout << "Error!";
        exit(1);
    }

    while (monster.eof() != 1){
        monster >> monstertemp.id >> monstertemp.name >> monstertemp.atk >> monstertemp.def >> monstertemp.hp;
        monsterInfo.push_back(monstertemp);
    }

    monster.close();

}

void damage(float pdamage, float mdamage, float &mHp, float &pHp){
        cout << "Damage you dealt: " << mdamage << endl; 
        cout << "Your damage received; " << pdamage << endl;
        pHp -= pdamage;
        mHp -= mdamage;
}

bool battle(int monster_id, player withItems){
    readMonster();
    monster battleMonster;
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

    float mAtk, mDef, mHp, pAtk, pDef, pHp;
    mAtk = battleMonster.atk;
    mDef = battleMonster.def;
    mHp = battleMonster.hp;
    pAtk = withItems.atk;
    pDef = withItems.def;
    pHp = withItems.hp;

    while (mHp > 0 && pHp > 0){
        int pAtkdef, mAtkdef;
        float pdamage, mdamage;
        cout << "Your HP: " << pHp << endl;
        cout << battleMonster.name << "'s HP: " << mHp << endl;
        cout << "Instruction: Your opponent would attack or defend in random. You may choose to 1. Attack or 2. Defend. Please type your option and hit enter." << endl;
        cin >> pAtkdef;
        mAtkdef = rand()%2 + 1;
        if (pAtkdef == 1 && mAtkdef == 1){
            pdamage = mAtk;
            mdamage = pAtk;
            damage (pdamage, mdamage, mHp, pHp);
        }
        else if (pAtkdef == 2 && mAtkdef == 1){
            mdamage = 0;
            pdamage = mAtk - pDef;
            damage (pdamage, mdamage, mHp, pHp);
        }
        else if (pAtkdef == 1 && mAtkdef == 2){
            mdamage = pAtk - mDef;
            pdamage = 0;
            damage (pdamage, mdamage, mHp, pHp);
        }
        else if (pAtkdef == 2 && mAtkdef == 2)
        {
            mdamage = 0;
            pdamage = 0;
            damage (pdamage, mdamage, mHp, pHp);
        }
        
    }

    if (pHp != 0){
        cout << "You win! You have " << pHp <<" HP left. " << endl;
        return true;
    }
    else {
        cout << "Your HP is empty! You lose! " << endl;
        return false;
    }

}