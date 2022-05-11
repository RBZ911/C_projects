// SNAKE WATER GUN
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int comp_score = 0, player_score = 0; // initialising globally with zero score
void win() // printing messages when player wins
{
    printf("You Won!\n");
    player_score++; // increament in overall score
    printf("Your Score: %d\n", player_score);
    printf("CPU Score: %d\n", comp_score);
}
void lose() // printing messages when player loses
{
    printf("You Lose!\n"); 
    comp_score++; // increament in overall score
    printf("Your Score: %d\n", player_score);
    printf("CPU Score: %d\n", comp_score);
}
int main()
{
    int number;
    char player, comp, ch;
    printf("\n*********************************************************************\n");
    printf("\n*********************************************************************\n");
    printf("\n*********************||||| SNAKE WATER GUN |||||*********************\n");
    printf("\n*********************************************************************\n");
    printf("\n*********************************************************************\n");
    printf("\nLET'S PLAY !!!\n"); // creating menu options
    printf("Press S For Snake\n");
    printf("Press W For WATER\n");
    printf("Press G For GUN\n");
    do
    {
        srand(time(0)); // generating a random number
        number = rand() % 100 + 1;
        if (number <= 33) // CPU choice selection
        {
            comp = 's';
        }
        else if (number > 33 && number <= 66)
        {
            comp = 'w';
        }
        else
        {
            comp = 'g';
        }
        fflush(stdin);
        printf("\nYour turn: ");
        scanf("%c", &player);
        // conditions for result making
        if (comp == player)
        {
            printf("Draw!\n");
            printf("Your Score: %d\n", player_score);
            printf("CPU Score: %d\n", comp_score);
        }
        if (comp == 's' && player == 'w')
        {
            lose();
        }
        else if (comp == 'w' && player == 's')
        {
            win();
        }
        if (comp == 'g' && player == 's')
        {
            lose();
        }
        else if (comp == 's' && player == 'g')
        {
            win();
        }
        if (comp == 'w' && player == 'g')
        {

            lose();
        }
        else if (comp == 'g' && player == 'w')
        {
            win();
        }
        printf("\nComputer selected %c and you selected %c.\n", comp, player);
        fflush(stdin);
        printf("\nQuit?(y/n): "); // asking player to quit the game
        scanf("%c", &ch);
    } while (ch == 'n');
    if (player_score > comp_score)
    {
        printf("\nComputer is a dumb machine!\n");
    }
    else
    {
        printf("\nMachine Rules!\n");
    }
    return 0;
}