#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int number, guess, nguesses = 1;
    srand(time(0));
    number = rand() % 100 + 1;
    do
    {
        printf("Guess the number: ");
        scanf("%d", &guess);
        if (guess > number)
        {
            printf("Try a lower one!\n");
        }
        else if (guess < number)
        {
            printf("Try a higher one\n");
        }
        else
        {
            printf("Congrats!\n");
            printf("You cracked the number within %d attempts!", nguesses);
        }
        nguesses++;
    } while (guess != number);
    return 0;
}
