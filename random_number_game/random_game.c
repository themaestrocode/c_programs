#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

void gamePlay(char name[]);
void playerRecord(char *name, int, int, int);
void rmline(char *string);
void stars(void);

/* global variables to store the player's game data */
int winCount = 0;
int lossCount = 0;
int totalGames;

int main(void)
{

    puts("THEMAESTROCODE'S RANDOM NUMBER GAME IN C\n");
    printf("Please, enter your name before we get started: ");
    char name[40];
    fgets(name, sizeof(name), stdin);
    rmline(name);

    stars();

    printf("Welcome on board, %s!\n", name);

    gamePlay(name);

    return 0;
}

void gamePlay(char name[])
{
    puts("Please, read the instructions below:\n");
    puts("ABOUT THE GAME (INSTRUCTIONS)");
    puts("* In this game, you are to guess the number that will be randomly generated by the computer.");
    puts("* The generated number will always range from 1 to 20.");
    puts("* You have 5 attempts to try to guess the generated number correctly.");
    puts("* There will be a hint after each attempt telling you whether to guess higher or lower.");
    printf("\nGoodluck, %s!\n", name);

    stars();

    printf("Are you ready to play? Press 1 to start\n");
    int opcode;
    scanf("%d", &opcode);

    while (opcode != 1)
    {
        printf("\nAre you ready to play? Press 1 to start\n");
        scanf("%d", &opcode);
    }

    // generating the random number
    srand(time(NULL));
    int x = (rand() % 5) + 1;

    stars();

    int attempt = 1;

    printf("\n\nAttempt %d", attempt);
    printf("\nWhat is the generated number?\nYour answer: ");
    int answer;
    scanf("%d", &answer);

    int counter = 1;

    while (counter <= 5)
    {
        attempt++;

        if (x == answer)
        {
            stars();
            printf("\nCongratulations, %s", name);
            printf("You have won THE RANDOM NUMBER C GAME\nThe generated number is: %d", x);
            winCount++;
            break;
        }
        else if (x > answer)
        {

            printf("\n* HINT: Try a higher number *");
            printf("\nAttempt %d", attempt);
            printf("\nWhat is the generated number?\nYour answer: ");
            scanf("%d", &answer);
            counter++;
        }
        else
        {
            printf("\n* HINT: Try a lower number *");
            printf("\nAttempt %d", attempt);
            printf("\nWhat is the generated number?\nYour answer: ");
            scanf("%d", &answer);
            counter++;
        }

        if (counter == 5 && x != answer)
        {
            stars();
            printf("\n\nGAME OVER!\nThe generated number is: %d", x);
            lossCount++;
            break;
        }
    }

    playerRecord(name, winCount, lossCount, totalGames);

    printf("\n\nWould you like to play again %s", name);
    printf("\tPress 1 to play again\n\tPress any other number to quit and exit\n");
    int playAgain;
    scanf("%d", &playAgain);

    if (playAgain == 1)
    {
        gamePlay(name);
    }
    else
    {
    }
}

void playerRecord(char name[30], int won, int lost, int totalGames)
{
    stars();
    printf("\nPLAYER RECORD");
    printf("\nPlayer name: %s", name);
    printf("Games won: %d", won);
    printf("\nGames lost: %d", lost);
    totalGames = won + lost;
    printf("\nTotal Games Played: %d", totalGames);
}


/**
 * stars - prints astericks character to the display as a decorative divider
 * just for formatting and readability
*/
void stars(void) {

    puts("\n***********************************************************************************************\n");
}


/**
 * rmline - removes the new line character from the end of the string when the fgets method is used
 * @string: the String or text from which the ending new line is to be removed
*/
void rmline(char string[]) {

    string[strcspn(string, "\n")] = '\0';
}