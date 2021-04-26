#include <time.h>
#include <stdlib.h>
int randomMonster(){
    srand(time(NULL));
    //this function returns a random value from 1 to 3 to represent the monster code
    int monsterCode;
    monsterCode = rand()%3 + 1;
    return monsterCode;
    //return the random generated id of monster
}
