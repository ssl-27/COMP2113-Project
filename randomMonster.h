#include <time.h>
#include <stdlib.h>
//this function returns a random value from 1 to 3 to represent the monster code
int randomMonster(){
    srand(time(NULL));
    int monsterCode;
    monsterCode = rand()%3 + 1;
    return monsterCode;
    //return the random generated id of monster
}
