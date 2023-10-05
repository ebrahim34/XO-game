
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void print_game(char (*arr)[3],char row,char col)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
    char i,j,flag=0;
    printf("\n");
    printf("-------------------------\n");
    printf("   |");
    for(i=1; i<4; i++)
    {
        printf("%4d",i);
        if(i!=3)
        {
            printf("   ");
        }
    }
    printf("  ");
    printf("|");
    printf("\n");
    printf("-------------------------\n");

    for(i=0; i<row; i++)
    {
        SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
        printf("%d  ",i+1);
        flag=1;
        for(j=0; j<col; j++)
        {
            SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
            printf("|");
            if(arr[i][j]=='X')
            {
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_RED | FOREGROUND_RED);

                printf("%4c",arr[i][j]);
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            }
            else
            {
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_BLUE | FOREGROUND_GREEN);

                printf("%4c",arr[i][j]);
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            }
            printf("  ");
        }
        SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);

        printf("|");
        printf("\n");
        printf("-------------------------\n");
    }
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

}

char scanAndCheck_char (char *ch1,char *ch2)
{
    char user1,user2;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    printf("Player 1 choose  X  or  O \n");
    fflush(stdin);
    scanf("%c",&user1);
    system("cls");
    print_GUI();
    if(user1>='a'&&user1<='z')
    {
        user1=user1-'a'+'A';
    }

    if((user1!='X')&&(user1!='O'))
    {
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_RED | FOREGROUND_RED);
        printf("******** ERROR ********\n");
        Beep(500,900);
        printf("Player 1 please enter correct character  X  or  O .\n");
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        return 0;
    }
    if(user1=='X')
    {
        user2='O';
        *ch1=user1;
        *ch2=user2;
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_GREEN | FOREGROUND_GREEN);

        printf("Player 1 character is  %c.\n",user1);
        printf("Player 2 character is  %c.\n",user2);
    }
    else
    {
        user2='X';
        *ch1=user1;
        *ch2=user2;
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_GREEN | FOREGROUND_GREEN);

        printf("Player 1 character is  %c.\n",user1);
        printf("Player 2 character is  %c.\n",user2);
    }
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

    return 1;

}

char check_rowAndcolumn(int x,int y)
{
    if((x<3)&&(y<3)&&(x>=0)&&(y>=0))
    {
        return 1;
    }
    return 0;
}
char check_constant(char(*flag)[3],char x,char y)
{
    if(flag[x][y])
    {
        flag[x][y]=0;
        return 1;
    }
    else
    {
        return 0;
    }

}

void set_data(char(*arr)[3],char user,char x,char y)
{
    arr[x][y]=user;

}

char check_win(char(*arr)[3],char row,char col,char user)
{
    char i,j,count=0;
    for(i=0; i<row; i++)
    {
        count=0;
        for(j=0; j<col; j++)
        {
            if(arr[i][j]==user)
            {
                count++;
            }
        }
        if(count==3)
        {
            return 1;
        }
    }

    for(j=0; j<col; j++)
    {
        count=0;
        for(i=0; i<row; i++)
        {
            if(arr[i][j]==user)
                count++;
        }
        if(count==3)
        {
            return 1;
        }
    }
    count=0;

    for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
        {
            if(i==j)
            {
                if(arr[i][j]==user)
                {
                    count++;
                }
            }
        }

        if(count==3)
        {
            return 1;
        }
    }
    count=0;
    for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
        {
            if((i+j)==2)
            {
                if(arr[i][j]==user)
                {
                    count++;
                }
            }
        }
        if(count==3)
        {
            return 1;
        }
    }

    return 0;

}
void reset_arr(char(*arr)[3],char row,char col)
{
    char i,j;
    for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
        {
            arr[i][j]=' ';
        }
    }
}
void reset_flags(char (*flag)[3],char row,char col)
{
    char i,j;
    for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
        {
            flag[i][j]=1;
        }
    }
}

void print_GUI(void)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_RED | FOREGROUND_RED);
    printf("\n");
    printf("                                               X   X    OOOO   \n");
    printf("                                                X X    O    O  \n");
    printf("                                                 X     O    O  \n");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_BLUE | FOREGROUND_GREEN);
    printf("                                                X X    O    O  \n");
    printf("                                               X   X   O    O  \n");
    printf("                                              X     X   OOOO    \n");
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_GREEN | FOREGROUND_GREEN);
    printf("                                       GGGG      A              EEEEE  \n");
    printf("                                      GG       A   A   MMM MMM  E       \n");
    printf("                                      GG  GG   AAAAA   MM M MM  EEE     \n");
    printf("                                      GG   G  A     A  MM   MM  E       \n");
    printf("                                       GGGG   A     A  MM   MM  EEEEE  \n");

    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void printf_charater(char ch1,char ch2)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_GREEN | FOREGROUND_GREEN);
    printf("\033[7m");
    printf("player 1 character is  %c.\n",ch1);
    printf("player 2 character is  %c.\n",ch2);
    printf("\033[0m");
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

