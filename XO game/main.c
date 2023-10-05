#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

char check_win(char(*arr)[3],char row,char col,char user);
char check_constant(char(*flag)[3],char x,char y);
char check_rowAndcolumn(int x,int y);
char scanAndCheck_char (char *ch1,char *ch2);


int main()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    char user1,user2;
    int check,x,y,counter=0,k=0,start;
    char arr[3][3];
    char flag[3][3];
    print_GUI();
    while(1)
    {
        printf("1- Start new game.\n");
        printf("2-End game.\n");
        while(1)
        {
            fflush(stdin);
            scanf("%d",&start);
            system("cls");
            print_GUI();
            if((start==1)||(start==2))
            {
                break;
            }
            else
            {
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_RED | FOREGROUND_RED);
                printf("******** ERROR ********\n");
                Beep(500,900);
                printf("Please press 1 or 2\n");
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                printf("1- Start new game.\n");
                printf("2-End game.\n");
            }
        }
        if(start==1)
        {
            counter=0;
            reset_arr(arr,3,3);
            reset_flags(flag,3,3);
            while(1)
            {
                check=scanAndCheck_char(&user1,&user2);
                if(check==1)
                    break;
            }
            while(check)
            {
                system("cls");
                print_GUI();
                printf_charater(user1,user2);
                print_game(arr,3,3);
                printf("Player 1's turn: Choose a row and a column.\n\n");
                while(1)
                {
                    fflush(stdin);
                    printf("Enter the row: ");
                    scanf("%d",&x);
                    fflush(stdin);
                    printf("Enter the column: ");
                    scanf("%d",&y);
                    system("cls");
                    print_GUI();
                    printf_charater(user1,user2);
                    print_game(arr,3,3);
                    if(check_rowAndcolumn(x-1,y-1))
                    {
                        if(check_constant(flag,x-1,y-1))
                        {
                            set_data(arr,user1,x-1,y-1);
                            counter++;
                            print_game(arr,3,3);
                            k=check_win(arr,3,3,user1);
                            break;
                        }
                        else
                        {
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_RED | FOREGROUND_RED);
                            printf("******** ERROR ********\n");
                            Beep(500,900);
                            printf("This place is used before , player 1 enter another Row and Column.\n\n");
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                        }
                    }
                    else
                    {
                        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_RED | FOREGROUND_RED);
                        printf("******** ERROR ********\n");
                        Beep(500,900);
                        printf("Player 1 please enter correct Row and Column.\n\n");
                        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                    }
                }
                if(k==1)
                {
                    system("cls");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_GREEN | FOREGROUND_GREEN);
                    printf("\033[4;40f");
                    printf("\033[4m");
                    printf(" The first player has won. (:\n");
                    Beep(500,900);
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                    break;
                }
                if(counter==9)
                {
                    system("cls");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_RED | FOREGROUND_RED);
                    printf("\033[4;40f");
                    printf("\033[4m");
                    printf("  No one won. ):\n");
                    Beep(500,900);
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

                    break;
                }
                system("cls");
                print_GUI();
                printf_charater(user1,user2);
                print_game(arr,3,3);
                printf("Player 2's turn: Choose a row and a column.\n\n");

                while(1)
                {
                    fflush(stdin);
                    printf("Enter the row: ");
                    scanf("%d",&x);
                    fflush(stdin);
                    printf("Enter the column: ");
                    scanf("%d",&y);
                    system("cls");
                    print_GUI();
                    printf_charater(user1,user2);
                    print_game(arr,3,3);
                    if(check_rowAndcolumn(x-1,y-1)==1)
                    {

                        if(check_constant(flag,x-1,y-1))
                        {
                            set_data(arr,user2,x-1,y-1);
                            counter++;
                            print_game(arr,3,3);
                            k=check_win(arr,3,3,user2);
                            break;
                        }
                        else
                        {
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_RED | FOREGROUND_RED);
                            printf("******** ERROR ********\n");
                            Beep(500,900);
                            printf("This place is used before , player 2 enter another Row and Column.\n\n");
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                        }
                    }
                    else
                    {
                        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_RED | FOREGROUND_RED);
                        printf("******** ERROR ********\n");
                        Beep(500,900);
                        printf("Player 2 please enter correct Row and Column.\n\n");
                        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                    }
                }

                if(k==1)
                {
                    system("cls");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_GREEN | FOREGROUND_GREEN);
                    printf("\033[4;40f");
                    printf("\033[4m");
                    printf(" The second player has won. (:\n");
                    Beep(500,900);
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                    break;
                }
            }
        }
        else
        {
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_RED | FOREGROUND_RED);
            printf("\033[16;50f");
            printf("\033[4m");
            printf("You end game\n");
            printf("\033[0m");
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

            break;
        }

    }

    return 0;
}

