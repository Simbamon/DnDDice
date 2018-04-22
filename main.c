#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <conio.h>
#include <time.h>

void battleDice();
void initiativeDice();
void DiceAverage();

int main()
{
    /*================TEST FOR THE RNG DICE================

    printf("TEST ROLLS\n");
    printf("==========================================\n");

    int testRoll;

    for(int i = 1; i <21; i++){
        testRoll = rand()%20 + 1;
        printf("Test #%d (20 sides): %d\n", i, testRoll);
    }

    =======================================================
    */
    int loopInt = 1;
    char diceType;

    diceOptions();

    while(loopInt){

        printf("Enter the dice type you want to roll: ");

        diceType = getche();

        switch(diceType){
            case 'B':
            case 'b': battleDice();
                      break;
            case 'I':
            case 'i': initiativeDice();
                      break;
            case 'A':
            case 'a': DiceAverage();
                      break;
            case 'C':
            case 'c': system("cls");
                      diceOptions();
                      break;
            case 'Q':
            case 'q': exit(0);
                      break;
            default: system("cls");
                     diceOptions();
        }

    }

}

void diceOptions(){
    printf("      ________          ________\n");
    printf("     / ____  /         / ____  /    ______  ___  _____  _____\n");
    printf("    / /   / /         / /   / /    / __  / /  / / ___/ / ___/\n");
    printf("   / /   / / ______  / /   / /    / / / / /  / / /    / /__\n");
    printf("  / /   / / / __  / / /   / /    / / / / /  / / /    / ___/\n");
    printf(" / /___/ / / / / / / /___/ /    / /_/ / /  / / /___ / /__\n");
    printf("/_______/ /_/ /_/ /_______/    /_____/ /__/ /_____//____/\n\n\n");
    printf("************************************\n\n");
    printf("Enter 'B' for dice roll\n");
    printf("Enter 'I' for initiative roll\n");
    printf("Enter 'A' for average dice roll\n");
    printf("Enter 'C' to clear the screen\n");
    printf("Enter 'Q' to quit the application\n\n");
    printf("************************************\n\n");
}

void battleDice(){
    int firstRoll;
    int secondRoll;
    char hitOrMiss;

    firstRoll = (rand()%20) + 1;
    secondRoll = (rand()%6) + 1;
    printf("\n\nFirst roll (20 sides): %d\n", firstRoll);
    printf("\nDid you hit or miss? (y or n): ");
    scanf(" %c", &hitOrMiss);

    switch(hitOrMiss){
        case 'Y':
        case 'y': printf("\nYou hit! Your hit point is: %d\n\n", secondRoll);
                  break;
        case 'N':
        case 'n': printf("\nYou missed. Wait for DM's instructions\n\n");
                  break;
        default: printf("\nWrong input. You have rolled %d if you did not miss your attack\n\n", secondRoll);

    }
}

void initiativeDice(){
    int initiativeDice = 0;

    initiativeDice = (rand()%20) + 1;

    printf("\n\nYour initiative dice rolled: %d\n\n", initiativeDice);
    srand(time(NULL));

}

void DiceAverage(){

    int i, rollNum;
    int total = 0;
    int dice;
    float average = 0.0;
    int *pDiceRollsSize;

    printf("\n\nHow many time would you like to roll? ");
    scanf(" %d", &rollNum);
    pDiceRollsSize = malloc(rollNum * sizeof * pDiceRollsSize);
    free(pDiceRollsSize);


    srand(time(NULL));

    printf("\n\nDice Rolls: \n\n");
    printf("---------------------------------------------\n");


    for(i = 0; i < rollNum; i++){
        dice = (rand()%20) + 1;
        printf("Roll Number %d: %d\n", (i + 1), dice);
        total += dice;

    }
    printf("---------------------------------------------\n\n");

    average = (float)total / (float)rollNum;

    printf("Your average is: %.1f\n", average);



}
