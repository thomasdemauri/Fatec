#include <stdio.h>

typedef struct _contract {
    char name[20];
    int  idContract;
    int  plpAmount;
    int  armyAmount;
    int  eventOnWeek;
    int  multipleContracts;
    int  corporation;
} Contract;


int main() {

    int LEN = 2;

    Contract contracts[LEN] = {
        {"RAFINHA", 1, 100, 0, 0, 1, 2},
        {"GUILHERME", 2, 100, 3, 1, 1, 2, 1}
    };

    return 0;
}