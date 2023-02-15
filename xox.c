#include <stdio.h>
#include <stdlib.h>

char Square[10]={'0',' ',' ',' ',' ',' ',' ',' ',' ',' '};

int checkwin();
void drawboard();
void draw_initial_board();


int main()
{
    int player=1,i,choice;
    char mark;
    draw_initial_board();
    do
    {
        drawboard();
        player=(player % 2 ) ? 1:2;
        printf("==> May player%d enter the choice: ",player);
        scanf("%d",&choice);
        mark=(player==1) ? 'X' : 'O';
        if(Square[choice]==' ')
            Square[choice]=mark;
        else
        {
            printf("invalid option\n");
            player--;
        }
        i=checkwin();
        player++;
    } while (i==-1);
    drawboard();
    if(i==1)
    {
        printf("\n*** player%d has won! ***\n",player);
    }        
    else
    {
        printf("\n*** game is draw ***\n");
    }
    return 0;
}


int checkwin()
{
    int i,var=1;
    if( (Square[1]!=' ') && Square[1]==Square[2] && Square[2]==Square[3])
        return 1;
    else if((Square[4]!=' ') && Square[4]==Square[5] && Square[5]==Square[6])
        return 1;
    else if((Square[7]!=' ') && Square[8]==Square[7] && Square[8]==Square[9])
        return 1;
    else if((Square[5]!=' ') && Square[1]==Square[5] && Square[5]==Square[9])
        return 1;
    else if((Square[5]!=' ') && Square[3]==Square[5] && Square[5]==Square[7])
        return 1;
    else if((Square[1]!=' ') && Square[1]==Square[4] && Square[4]==Square[7])
        return 1;
    else if((Square[2]!=' ') && Square[2]==Square[5] && Square[5]==Square[8])
        return 1;
    else if((Square[3]!=' ') && Square[3]==Square[6] && Square[9]==Square[6])
        return 1;
    for(i=1;i<10;i++)
    {
        if(Square[i]==' ')
            var=0;
    }
    if(var)
        return 0;
    return -1;
}

void drawboard()
{
    printf("\n");
    printf("player1(X) - player2(O)");
    printf("\n\n");
    printf(" _____ _____ _____\n");
    printf("|     |     |     |\n");
    printf("|  %c  |  %c  |  %c  |\n",Square[1],Square[2],Square[3]);
    printf("|_____|_____|_____|\n");
    printf("|     |     |     |\n");
    printf("|  %c  |  %c  |  %c  |\n",Square[4],Square[5],Square[6]);
    printf("|_____|_____|_____|\n");
    printf("|     |     |     |\n");
    printf("|  %c  |  %c  |  %c  |\n",Square[7],Square[8],Square[9]);
    printf("|_____|_____|_____|\n");
}
void  draw_initial_board()
{
    printf("These are the positions you need to refer!");
    printf("\n\n");
    printf(" _____ _____ _____\n");
    printf("|     |     |     |\n");
    printf("|  1  |  2  |  3  |\n");
    printf("|_____|_____|_____|\n");
    printf("|     |     |     |\n");
    printf("|  4  |  5  |  6  |\n");
    printf("|_____|_____|_____|\n");
    printf("|     |     |     |\n");
    printf("|  7  |  8  |  9  |\n");
    printf("|_____|_____|_____|\n\n");
    printf("****** ***** ******");
}
