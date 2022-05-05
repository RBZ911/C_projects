// Using C: The legend's language
#include <stdio.h>
void printBoard(int X_State[], int O_State[])
{
    char zero = X_State[0] == 1 ? 'X' : (O_State[0] == 1 ? 'O' : '1');
    char one = X_State[1] == 1 ? 'X' : (O_State[1] == 1 ? 'O' : '2');
    char two = X_State[2] == 1 ? 'X' : (O_State[2] == 1 ? 'O' : '3');
    char three = X_State[3] == 1 ? 'X' : (O_State[3] == 1 ? 'O' : '4');
    char four = X_State[4] == 1 ? 'X' : (O_State[4] == 1 ? 'O' : '5');
    char five = X_State[5] == 1 ? 'X' : (O_State[5] == 1 ? 'O' : '6');
    char six = X_State[6] == 1 ? 'X' : (O_State[6] == 1 ? 'O' : '7');
    char seven = X_State[7] == 1 ? 'X' : (O_State[7] == 1 ? 'O' : '8');
    char eight = X_State[8] == 1 ? 'X' : (O_State[8] == 1 ? 'O' : '9');
    printf("%c | %c | %c\n", zero, one, two);
    printf("--|---|---\n");
    printf("%c | %c | %c\n", three, four, five);
    printf("--|---|---\n");
    printf("%c | %c | %c\n", six, seven, eight);
}

int checkWin(int X_State[], int O_State[])
{
    int wins[8][3] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, {0, 4, 8}, {2, 4, 6}};
    for (int i = 0; i < 8; i++)
    {
        int sum_X = 0, sum_O = 0;
        for (int j = 0; j < 3; j++)
        {
            sum_X += X_State[wins[i][j]];
            sum_O += O_State[wins[i][j]];
        }
        if (sum_X == 3)
        {
            printf("X Won the match!\n");
            return 1;
        }
        if (sum_O == 3)
        {
            printf("O Won the match!\n");
            return 0;
        }
    }
    return -1;
}

int main()
{
    int X_State[9] = {0}, O_State[9] = {0}, turn = 1, value, cwin;
    printf("Welcome to Tic Tac Toe\n");
    while (1)
    {
        printBoard(X_State, O_State);
        if (turn == 1)
        {
            printf("X's Chance: ");
            scanf("%d", &value);
            X_State[value - 1] = 1;
            turn = 0;
        }
        else
        {
            printf("O's Chance: ");
            scanf("%d", &value);
            O_State[value - 1] = 1;
            turn = 1;
        }
        cwin = checkWin(X_State, O_State);
        if (cwin != -1)
        {
            printf("Match over!\n");
            break;
        }
    }
}