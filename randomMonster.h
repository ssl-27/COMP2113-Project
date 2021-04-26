#include <time.h>
#include <stdlib.h>
int randomMonster(){
    srand(time(NULL));
    int monsterCode;
    monsterCode = rand()%3 + 1;
    return monsterCode;
}