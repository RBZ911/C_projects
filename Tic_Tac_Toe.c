// TIC TAC TOE
#include <stdio.h>
#include <string.h>
int X_Score = 0, O_Score = 0; // scores globally initialised
void printBoard(char *board)  // printing board
{
    printf("%c | %c | %c\n", board[0], board[1], board[2]);
    printf("--|---|---\n");
    printf("%c | %c | %c\n", board[3], board[4], board[5]);
    printf("--|---|---\n");
    printf("%c | %c | %c\n", board[6], board[7], board[8]);
}
int checkWin(char *board)
{
    int wins[8][3] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, {0, 4, 8}, {2, 4, 6}}; // winning probabilities
    char winner[3]; // initialising a string winner to carry all winning probabilities
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            winner[j] = board[wins[i][j]];
        }
        int k = 0, X_count = 0, O_count = 0;
        while (winner[k] != '\0') 
        {
            // conditions to check winner
            if (winner[k] == 'X')
            {
                X_count++;
            }
            if (winner[k] == 'O')
            {
                O_count++;
            }
            k++;
        }
        if (X_count == 3)
        {
            X_Score++;
            printf("X Won the match!\n");
            return 1;
        }
        if (O_count == 3)
        {
            O_Score++;
            printf("O Won the match!\n");
            return 0;
        }
    }
    return -1;
}
int main()
{
    int value, cwin;
    char ch;
    printf("\n*********************************************************************\n");
    printf("\n*********************************************************************\n");
    printf("\n***********************||||| TIC TAC TOE |||||***********************\n");
    printf("\n*********************************************************************\n");
    printf("\n*********************************************************************\n");
    do
    {
        int turn = 1, no_turns = 0;
        char board[10] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '\0'};
        while (1)
        {
            printBoard(board);
            if (turn == 1) // initialising game with X's chance
            {
                printf("\nX's Chance: ");
                scanf("%d", &value);
                if (board[value - 1] != 'O')
                {
                    board[value - 1] = 'X';
                }
                no_turns++;
                turn = 0;
            }
            else
            {
                printf("\nO's Chance: ");
                scanf("%d", &value);
                if (board[value - 1] != 'X')
                {
                    board[value - 1] = 'O';
                }
                no_turns++;
                turn = 1;
            }
            if (no_turns > 4) // minimal turns needed for result making process (i.e. 5)
            {
                cwin = checkWin(board);
                if (cwin != -1)
                {
                    printf("Match over!\n");
                    break;
                }
                if (no_turns == 9 && cwin == -1)
                {
                    printf("Match Drawn!\n");
                    break;
                }
            }
        }
        printf("\nX's Score: %d\n", X_Score); // printing scores
        printf("\nO's Score: %d\n", O_Score);
        fflush(stdin);
        printf("\nOne more game?(y/n): "); // asking for one more game
        scanf("%c", &ch);
    } while (ch == 'y');
    if (X_Score > O_Score) // deciding overall winner
    {
        printf("\nOverall winner: X\n");
    }
    else if (O_Score > X_Score)
    {
        printf("\nOverall winner: O\n");
    }
    else
    {
        printf("\nOverall winner: NO ONE! Both opponents have equal points!\n");
    }
    printf("Press any key to exit ...");
    fflush(stdin);
    getchar();
}