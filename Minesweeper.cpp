#include<iostream>
#include<cstring>
#include <ctime>
#include <cstdlib>

using namespace std;
#define BEGINNER 0
#define INTERMEDIATE 1
#define ADVANCED 2
#define NOFLAG 'n'
#define YESFLAG 'y'
#define MAXLENGTH 17
#define MAXWIDTH 31
#define MAXMINES 99
#define MOVESIZE 428 // 31*17-99
#define NEWLINE '\n'

int LENGTH, WIDTH, MINES;
void Level ()
{
    int difficulty;
    cout<<"Choose the difficulty level: "<<NEWLINE;
    cout<<"PRESS 0 FOR"<<NEWLINE;
    cout<<"     Beginner"<<NEWLINE<<"   o 10 mines"<<NEWLINE<<"     9x9 tile grid"<<NEWLINE<<NEWLINE;
    cout<<"PRESS 1 FOR "<<NEWLINE;
    cout<<"     Intermediate"<<NEWLINE<<"   o 40 mines"<<NEWLINE<<"     16x16 tile grid"<<NEWLINE<<NEWLINE;
    cout<<"PRESS 2 FOR "<<NEWLINE;
    cout<<"     Advanced"<<NEWLINE<<"   o 99 mines"<<NEWLINE<<"     16x30 tile grid"<<NEWLINE<<NEWLINE;
    cin>>difficulty;
    if(difficulty==BEGINNER)
    {
        LENGTH=9;
        WIDTH=9;
        MINES=10;

        cout<<NEWLINE;
        cout<<"YOU CHOOSE TO PLAY: "<<NEWLINE;
        cout<<"     Beginner"<<NEWLINE<<"   "<<char(16)<<" 10 mines"<<NEWLINE<<"     9x9 tile grid"<<NEWLINE<<NEWLINE;
        cout<<"     Intermediate"<<NEWLINE<<"   o 40 mines"<<NEWLINE<<"     16x16 tile grid"<<NEWLINE<<NEWLINE;
        cout<<"     Advanced"<<NEWLINE<<"   o 99 mines"<<NEWLINE<<"     16x30 tile grid"<<NEWLINE<<NEWLINE;
        clock_t cl;
        cl = clock();
        _sleep(2800);
    }

    if(difficulty==INTERMEDIATE)
    {
        LENGTH=16;
        WIDTH=16;
        MINES=40;

        cout<<NEWLINE;
        cout<<"YOU CHOOSE TO PLAY: "<<NEWLINE;
        cout<<"     Beginner"<<NEWLINE<<"   o 10 mines"<<NEWLINE<<"     9x9 tile grid"<<NEWLINE<<NEWLINE;
        cout<<"     Intermediate"<<NEWLINE<<"   "<<char(16)<<" 40 mines"<<NEWLINE<<"     16x16 tile grid"<<NEWLINE<<NEWLINE;
        cout<<"     Advanced"<<NEWLINE<<"   o 99 mines"<<NEWLINE<<"     16x30 tile grid"<<NEWLINE<<NEWLINE;
        clock_t cl;
        cl = clock();
        _sleep(2800);
    }

    if(difficulty==ADVANCED)
    {
        LENGTH=16;
        WIDTH=30;
        MINES=99;

        cout<<NEWLINE;
        cout<<"YOU CHOOSE TO PLAY: "<<NEWLINE;
        cout<<"     Beginner"<<NEWLINE<<"   o 10 mines"<<NEWLINE<<"     9x9 tile grid"<<NEWLINE<<NEWLINE;
        cout<<"     Intermediate"<<NEWLINE<<"   o 40 mines"<<NEWLINE<<"     16x16 tile grid"<<NEWLINE<<NEWLINE;
        cout<<"     Advanced"<<NEWLINE<<"   "<<char(16)<<" 99 mines"<<NEWLINE<<"     16x30 tile grid"<<NEWLINE<<NEWLINE;
        clock_t cl;
        cl = clock();
        _sleep(2800);
    }


}

void myMove(int *x, int *y, char &flag)
{   cout<<NEWLINE;
    cout<<"Enter your move adding 'y' if you want to put a flag or 'n' if you don't"<<endl;
    cout<<"(row, col, flag) ->";
    cin>>*x;
    cin>>*y;
    cin>>flag;

}

bool Valid(int row, int col)
{
    return(row>=0)&&(row<WIDTH)&&(col>=0)&&(col<LENGTH);
}

bool Mine(char board[MAXWIDTH][MAXLENGTH], int row, int col)
{
    if(board[row][col]==char(4))
      return true;
    else return false;
}

void printBoard(char myPlayBoard[MAXWIDTH][MAXLENGTH])
{
    int i,j;
    cout<<"   ";
    for(j=0;j<LENGTH;j++)
     if(j>=0&&j<=9)
         cout<<'0'<<j<<" ";
     else cout<<j<<" ";
    cout<<NEWLINE<<NEWLINE;
    for(i=0;i<WIDTH;i++)
    {   if(i>=0&&i<=9)
        cout<<'0'<<i<<"  ";
       else cout<<i<<"  ";
         for(j=0;j<LENGTH;j++)
          cout<<myPlayBoard[i][j]<<"  ";
        cout<<NEWLINE;
    }

}

void initialiseBoard(char myPlayBoard[MAXWIDTH][MAXLENGTH], char realBoard[MAXWIDTH][MAXLENGTH])
{
    int i,j;
    srand(time (NULL));
    for(i=0;i<WIDTH;i++)
    {
        for(j=0;j<LENGTH;j++)
         myPlayBoard[i][j]=realBoard[i][j]='#';
    }

}


void placeMines(char realBoard[MAXWIDTH][MAXLENGTH], int mines[][2])
{
    int i,x,y;
    bool mark[MAXLENGTH*MAXWIDTH];

    memset (mark, false, sizeof (mark));

    i=0;
    while(i<MINES)
    {
        int random=rand()%(LENGTH*WIDTH);
        x=random/LENGTH;
        y=random%LENGTH;
       if (mark[random] == false)
       {
           mines[i][0]=x;
           mines[i][1]=y;
           realBoard[mines[i][0]][mines[i][1]] = char(4);
           mark[random]=true;
           i++;
       }
    }
  return;
}


int main()
{ char realBoard[MAXWIDTH][MAXLENGTH];
int mines[MAXMINES][2];
char myPlayBoard[MAXWIDTH][MAXLENGTH];
   Level();
   initialiseBoard(myPlayBoard, realBoard);
   printBoard(myPlayBoard);

 return 0;
}
