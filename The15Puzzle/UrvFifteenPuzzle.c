// The 15 Puzzle by URV
// This is the latest version 

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <ctype.h>

void gotoxy (short int col, short int row);
void DrawArea ();   
int getkey();
void modifyarea();


#define HLINE for (i = 0 ; i < 72; i++)\
                        printf ("%c", 223);

#define VLINE(X, Y) {\
                        gotoxy(X,Y);\
                        printf("%c", 219);\
                    }

const int r = 4;
const int c = 4; 

//void jumble_it (int arr[][c]);

int numbers[r][c] = { 1, 4, 15, 7,
                    8, 10, 2, 11,
                    14, 3, 6, 13,
                    12, 9, 5, 16
                    };

int ideal[r][c] = { 1, 2, 3, 4,
                5, 6, 7, 8,
                9, 10, 11, 12,
                13, 14, 15, 16
              };


void print (int q[][c]);
int checkwin (int nums[][c], int id [][c]);



int main ()
{
    int key, tempry, moves = 0, winner;
    int blr = r-1, blc = c-1;
    int blank = numbers[blr][blc];


    DrawArea();

    printf("\n\n\t\t\tPress %c %c %c %c to arrange\n\n", 30, 31, 16, 17);
    printf("\n\n\t\t\tPress 'q' to quit.\n");

    //key = getkey();
    
    do
    {
        key = getkey();
        if(tolower(key) == 113)
        {
            moves = -1;
            break;
        }

        if(key == 72)
        {
            if(blr != 3)
            {
                tempry = numbers [blr][blc];
                numbers [blr][blc] = numbers [blr + 1][blc];
                numbers [blr + 1][blc] = tempry;

                blr ++;
            }
            modifyarea ();
            moves++;
        }

        else if (key == 80)
        {
            if(blr != 0)
            {
                tempry = numbers [blr][blc];
                numbers [blr][blc] = numbers [blr - 1][blc];
                numbers [blr - 1][blc] = tempry;

                blr --;
            }
            modifyarea ();
           moves++;
        }

        else if (key == 75)
        {
            if(blc != 3)
            {
                tempry = numbers [blr][blc];
                numbers [blr][blc] = numbers [blr][blc + 1];
                numbers [blr][blc + 1] = tempry;

                blc ++;
            }
            modifyarea ();
            moves++;
        }

        else if (key == 77)
        {
            if(blc != 0)
            {
                tempry = numbers [blr][blc];
                numbers [blr][blc] = numbers [blr][blc - 1];
                numbers [blr][blc - 1] = tempry;

                blc --;
            }
            modifyarea ();
            moves++;
        }

        winner = checkwin(numbers, ideal);

    } while (winner == 1);

    (moves == -1 ? printf("\n\n\t\t\t>>> GAME OVER <<<\n\n\n") : printf("\n\n\t\t\t WINNER WINNER CHICKEN DINNER with %d Moves !!! %c %c %c \n\n", moves , 1,1,1));
    
    getch ();

    return 0;
}

void gotoxy (short int col, short int row)
{
    HANDLE hStdout = GetStdHandle (STD_OUTPUT_HANDLE);
    COORD position = {col, row};
    SetConsoleCursorPosition (hStdout, position);
}

/*void jumble_it (int arr[][c])
{
    int temp;
    int num = 4;
    int num_of_elem = 16;
    int re1, re2, ce1, ce2;


    for (int i = 0 ; i < num_of_elem ; i++)
    {
        re1 = rand() % num;
        ce1 = rand() % num;
        re2 = rand() % num;
        ce2 = rand() % num;

        temp = arr [re1][ce1];
        arr [re1][ce1] = arr [re2][ce2];
        arr [re2][ce2] = temp;
    }
}*/

void DrawArea ()
{
    int i, y, vert, hori, row = 0, col = 0, iteration = 0;
    system("cls");

    for (hori = 1 ; hori <= 30 ; hori += 6)
    {
       gotoxy (50, hori);
       
       HLINE 
    }
    

    for (vert = 50 ; vert <= 122 ; vert += 18)
    {
        for (y = 1 ; y <= 24 ; y++)
        {
            VLINE(vert, y);
        }
    }

    //jumble_it (numbers);

    for(int k = 4 ; k < 28 ; k += 6)
    {
        for(int j = 59 ; j < 122  ; j += 9 )
        {
            iteration ++;
            if((iteration % 2) != 0)
            {
                gotoxy (j, k);
                ( numbers[row][col] == 16 ? printf ("%c", 0) : printf("%d", numbers[row][col]) );
                col++;
            }
        }
        iteration = 0;
        col = 0;
        row++;
    }

    gotoxy (50, 26);

}

int getkey()
{
    int ch;
    ch = getch();
    if(ch == 0)
    {
        ch = getch();
        return ch;
    }
    return ch;
}

void print (int q[][c])
{
    int i, j;

    for (i = 0 ; i < r ; i++)
    {
        for (j = 0; j < c ; j++)
            ( q[i][j] == 16 ? printf (" %c ", 0) : printf(" %d ", q[i][j]) );
        printf ("\n");
    }
    printf ("\n");
}

void modifyarea()
{
    int iteration = 0, row = 0 , col = 0 ;
    for(int k = 4 ; k < 28 ; k += 6)
    {
        for(int j = 59 ; j < 122  ; j += 9 )
        {
            iteration ++;
            if((iteration % 2) != 0)
            {
                gotoxy (j, k);
                ( numbers[row][col] == 16 ? printf ("%c%c%c", 32,32,32) : printf("%d", numbers[row][col]) );
                col++;
            }
        }
        iteration = 0;
        col = 0;
        row++;
    }

    gotoxy (50, 32);
}

int checkwin (int nums[][c], int id [][c])
{
    for(int i = 0; i < r ; i++)
    {
        for(int j = 0 ; j < c ; j++)
        {
            if(nums[i][j] != id [i][j])
            {
                return 1;
            }
        }
    }

    return 0;

}