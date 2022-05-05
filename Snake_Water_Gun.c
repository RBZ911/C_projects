#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int number;
    char you, comp;
    srand(time(0));
    number = rand() % 100 + 1;
    if (number <= 33)
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
    printf("SNAKE    WATER    GUN\n");
    printf("Let's Play!\n");
    printf("Your turn: ");
    scanf("%c", &you);
    if (comp == you)
    {
        printf("Draw!");
    }
    if (comp == 's' && you == 'w')
    {
        printf("You Lose!");
    }
    else if (comp == 'w' && you == 's')
    {
        printf("You Won!");
    }
    if (comp == 'g' && you == 's')
    {
        printf("You Lose!");
    }
    else if (comp == 's' && you == 'g')
    {
        printf("You Won!");
    }
    if (comp == 'w' && you == 'g')
    {
        printf("You Lose!");
    }
    else if (comp == 'g' && you == 'w')
    {
        printf("You Won!");
    }
    printf("\nComputer selected %c and you selected %c.", comp, you);
    return 0;
}