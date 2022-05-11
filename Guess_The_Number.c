// GUESS THE NUMBER
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int maxguesses = 8; // difficulty level: Normal by default
int random_number() // generating a random number
{
    int number;
    srand(time(0));
    number = rand() % 100 + 1;
    return number;
}
void game() // game process
{
    int number, guess, nguesses, no_of_games = 0, guess_record = 0, avg_guess, no_of_wins = 0;
    char ch;
    do
    {
        nguesses = 1;
        number = random_number();
        no_of_games++;
        do
        {
            if (nguesses <= maxguesses)
            {
                printf("Guess the number (Between 1-100): ");
                scanf("%d", &guess);
                if (guess > number)
                {
                    printf("Try a lower one!\n");
                }
                else if (guess < number)
                {
                    printf("Try a higher one!\n");
                }
                else
                {
                    printf("Congrats!\n");
                    printf("You cracked the number within %d attempts!\n", nguesses);
                    guess_record += nguesses;
                    no_of_wins++;
                }
                nguesses++;
            }
            else
            {
                printf("You exceeded the guessing limit!\n");
                printf("The number was %d.\n", number);
                printf("You LOST!\n");
                break;
            }
        } while (guess != number);
        fflush(stdin);
        printf("One more game?(y/n): "); // asking for another game
        scanf("%c", &ch);
    } while (ch == 'y');
    printf("No. of games you played: %d\n", no_of_games);
    if (no_of_wins > 0)
    {
        avg_guess = guess_record / no_of_wins; // calcuting for average
        printf("Your Average no. of attempts: %d\n", avg_guess); // showing average record at the end
    }
    printf("Returning to MAIN MENU ...\n");
}
void difficulty_level() // selecting difficulty level
{
    int select_DIFF;
    printf("\nPress 1: Easy\n");
    printf("\nPress 2: Normal\n");
    printf("\nPress 3: Hard\n");
    printf("\nPress 4: Extremely Hard\n");
    printf("\nSelect Options: ");
    scanf("%d", &select_DIFF);
    switch (select_DIFF)
    {
    case 1:
        maxguesses = 10; // easy level
        break;
    case 2:
        maxguesses = 8; // average level
        break;
    case 3:
        maxguesses = 6; // hard level
        break;
    case 4:
        maxguesses = 4; // extremely hard level
        break;
    default:
        printf("Invalid Input!\n");
        difficulty_level();
        break;
    }
}
void main_menu()
{
    int select;
    char ch;
    printf("\n********************|||||    MAIN MENU     |||||*********************\n");
    printf("\nPress 1: Start New Game\n");
    printf("\nPress 2: CPU Level\n");
    printf("\nPress 3: Quit Game\n");
    printf("\nSelect Options: ");
    scanf("%d", &select);
    switch (select)
    {
    case 1:
        game();
        main_menu();
        break;
    case 2:
        difficulty_level();
        game();
        main_menu();
    case 3:
        fflush(stdin);
        printf("Are you sure?(y/n): ");
        scanf("%c", &ch);
        if (ch == 'y')
        {
            exit(0);
        }
        else
        {
            printf("Returning to MAIN MENU ...\n");
            main_menu();
        }
    default:
        printf("Invalid Input!\n");
        main_menu();
        break;
    }
}
int main()
{
    printf("\n*********************************************************************\n");
    printf("\n*********************************************************************\n");
    printf("\n********************||||| GUESS THE NUMBER |||||*********************\n");
    printf("\n*********************************************************************\n");
    printf("\n*********************************************************************\n");
    main_menu(); // calling main_menu()
    return 0;
}