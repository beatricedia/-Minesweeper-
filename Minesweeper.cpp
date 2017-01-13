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
    cout<<NEWLINE;
    cout<<" Choose the difficulty level: "<<NEWLINE<<NEWLINE;
    cout<<"  PRESS 0 FOR"<<NEWLINE;
    cout<<"       Beginner"<<NEWLINE<<"     o 10 mines"<<NEWLINE<<"       9x9 tile grid"<<NEWLINE<<NEWLINE;
    cout<<"  PRESS 1 FOR "<<NEWLINE;
    cout<<"       Intermediate"<<NEWLINE<<"     o 40 mines"<<NEWLINE<<"       16x16 tile grid"<<NEWLINE<<NEWLINE;
    cout<<"  PRESS 2 FOR "<<NEWLINE;
    cout<<"       Advanced"<<NEWLINE<<"     o 99 mines"<<NEWLINE<<"       16x30 tile grid"<<NEWLINE<<NEWLINE;
    cin>>difficulty;
    system("CLS");
    cout<<NEWLINE;
    if(difficulty==BEGINNER)
    {
        LENGTH=9;
        WIDTH=9;
        MINES=10;


        cout<<" YOU CHOOSE TO PLAY: "<<NEWLINE;
        cout<<NEWLINE;
        cout<<"     Beginner"<<NEWLINE<<"   "<<char(16)<<" 10 mines"<<NEWLINE<<"     9x9 tile grid"<<NEWLINE<<NEWLINE;
        cout<<"     Intermediate"<<NEWLINE<<"   o 40 mines"<<NEWLINE<<"     16x16 tile grid"<<NEWLINE<<NEWLINE;
        cout<<"     Advanced"<<NEWLINE<<"   o 99 mines"<<NEWLINE<<"     16x30 tile grid"<<NEWLINE<<NEWLINE;
        clock_t cl;
        cl = clock();
        _sleep(2800);
        system("CLS");

    }

    if(difficulty==INTERMEDIATE)
    {
        LENGTH=16;
        WIDTH=16;
        MINES=40;


        cout<<" YOU CHOOSE TO PLAY: "<<NEWLINE;
        cout<<NEWLINE;
        cout<<"     Beginner"<<NEWLINE<<"   o 10 mines"<<NEWLINE<<"     9x9 tile grid"<<NEWLINE<<NEWLINE;
        cout<<"     Intermediate"<<NEWLINE<<"   "<<char(16)<<" 40 mines"<<NEWLINE<<"     16x16 tile grid"<<NEWLINE<<NEWLINE;
        cout<<"     Advanced"<<NEWLINE<<"   o 99 mines"<<NEWLINE<<"     16x30 tile grid"<<NEWLINE<<NEWLINE;
        clock_t cl;
        cl = clock();
        _sleep(2800);
        system("CLS");
    }

    if(difficulty==ADVANCED)
    {
        LENGTH=16;
        WIDTH=30;
        MINES=99;


        cout<<" YOU CHOOSE TO PLAY: "<<NEWLINE;
        cout<<NEWLINE;
        cout<<"     Beginner"<<NEWLINE<<"   o 10 mines"<<NEWLINE<<"     9x9 tile grid"<<NEWLINE<<NEWLINE;
        cout<<"     Intermediate"<<NEWLINE<<"   o 40 mines"<<NEWLINE<<"     16x16 tile grid"<<NEWLINE<<NEWLINE;
        cout<<"     Advanced"<<NEWLINE<<"   "<<char(16)<<" 99 mines"<<NEWLINE<<"     16x30 tile grid"<<NEWLINE<<NEWLINE;
        clock_t cl;
        cl = clock();
        _sleep(2800);
        system("CLS");
    }


}

void myMove(int *x, int *y, char &flag)
{
    cout<<NEWLINE;
    cout<<" Enter your move adding 'y' if you want to put a flag or 'n' if you don't"<<endl;
    cout<<" then press Enter(row, col, flag) ->";
    cin>>*x;
    cin>>*y;
    cin>>flag;
    system("CLS");
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
    cout<<"     ";
    for(j=0; j<LENGTH; j++)
        if(j>=0&&j<=9)
            cout<<'0'<<j<<" ";
        else cout<<j<<" ";
    cout<<NEWLINE;
    cout<<"    "<<char(201);
    for(j=0;j<LENGTH*2+LENGTH;j++)
    cout<<char(205);
    cout<<char(187);
    cout<<NEWLINE;
    for(i=0; i<WIDTH; i++)
    {
        if(i>=0&&i<=9)
            cout<<" "<<'0'<<i<<" "<<char(186)<<" ";
        else cout<<" "<<i<<" "<<char(186)<<" ";
        for(j=0; j<LENGTH; j++)
            cout<<myPlayBoard[i][j]<<"  ";
            cout<<"\b"<<char(186);
        cout<<NEWLINE;
    }
    cout<<"    "<<char(200);
     for(j=0;j<LENGTH*2+LENGTH;j++)
      cout<<char(205);
      cout<<char(188);
      cout<<NEWLINE;
}


void initialiseBoard(char myPlayBoard[MAXWIDTH][MAXLENGTH], char realBoard[MAXWIDTH][MAXLENGTH])
{
    int i,j;
    srand(time (NULL));
    for(i=0; i<WIDTH; i++)
    {
        for(j=0; j<LENGTH; j++)
            myPlayBoard[i][j]=realBoard[i][j]=char(223);
    }
}


void Replace(char board[MAXWIDTH][MAXLENGTH], int row, int col)
{
    int i,j;
    for(i=0; i<WIDTH; i++)
    {
        for(j=0; j<LENGTH; j++)
            if(board[i][j]!=char(4))
            {
                board[i][j]=char(4);
                board[row][col]=char(223);
                return;
            }
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
}

int countMines(char realBoard[MAXWIDTH][MAXLENGTH], int row, int col, int mines[][2])
{
    int i, nr=0;
    if(Valid(row-1, col) == true)
    {
        if (Mine (realBoard,row-1, col ) == true)
            nr++;
    }
    if(Valid(row+1, col) == true)
    {
        if(Mine(realBoard,row-1,col)==true)
            nr++;
    }
    if(Valid(row,col+1)==true)
    {
        if(Mine(realBoard,row, col+1)==true)
            nr++;
    }
    if(Valid(row, col-1)==true)
    {
        if(Mine(realBoard,row, col-1)==true)
            nr++;
    }
    if(Valid(row-1,col-1)==true)
    {
        if(Mine(realBoard,row-1,col-1)==true)
            nr++;
    }
    if(Valid(row-1,col+1)==true)
    {
        if(Mine(realBoard,row-1,col+1)==true)
            nr++;
    }
    if(Valid(row+1,col-1)==true)
    {
        if(Mine(realBoard,row+1,col-1)==true)
            nr++;
    }
    if(Valid(row+1, col+1)==true)
    {
        if(Mine(realBoard,row+1, col+1)==true)
            nr++;
    }
    return nr;
}

bool playGameTill(char realBoard[MAXWIDTH][MAXLENGTH], char myPlayBoard[MAXWIDTH][MAXLENGTH],int row, int col,int mines[][2],int *moves, char flag)
{
    int i,j;
    if(myPlayBoard[row][col]!=char(223))
        return false;
    if(flag==NOFLAG)
    {
        if(realBoard[row][col]==char(4))
        {
            myPlayBoard[row][col]=char(4);
            for(i=0; i<MINES; i++)
                if (myPlayBoard[mines[i][0]][mines[i][1]] != char (20))
                    myPlayBoard[mines[i][0]][mines[i][1]]=char(4);
            system("CLS");
            cout<<NEWLINE;
            printBoard(myPlayBoard);
            cout<<NEWLINE;
            cout<<"   ###   ####  #   #  ###     #####  #   #  ###  ###        #######"<<NEWLINE;
            cout<<"  #   #  #  #  ## ##  #       #   #  #   #  #    #  #      #       #"<<NEWLINE;
            cout<<" #       #  #  # # #  #       #   #  #   #  #    ###      #         #"<<NEWLINE;
            cout<<" #  ###  ####  #   #  ###     #   #  #   #  ###  ##      #           #"<<NEWLINE;
            cout<<" #    #  #  #  #   #  #       #   #   # #   #    # #    #  # #   # #  #"<<NEWLINE;
            cout<<"  #####  #  #  #   #  ###     #####    #    ###  # #    #   #     #   #"<<NEWLINE;
            cout<<"                                                        #  # #   # #  #"<<NEWLINE;
            cout<<"                                                        #             #"<<NEWLINE;
            cout<<" #   #  #####  #  #    #      #####  ####  #####  ###   #     ###     #"<<NEWLINE;
            cout<<" #   #  #   #  #  #    #      #   #  #       #    ###   #    #   #    #"<<NEWLINE;
            cout<<" #   #  #   #  #  #    #      #   #  #       #     #     #   #   #   #"<<NEWLINE;
            cout<<"  # #   #   #  #  #    #      #   #  ####    #     #      #         #"<<NEWLINE;
            cout<<"   #    #   #  #  #    #      #   #     #    #             #       #"<<NEWLINE;
            cout<<"   #    #####  ####    #####  #####  ####    #     #        #######"<<NEWLINE;
            return true;
        }

        else
        {
            int count = countMines(realBoard,row,col,mines);
            (*moves)--;
            myPlayBoard[row][col]=count + '0';
            if(count==0)
            {
                if(Valid(row-1,col)==true)
                {
                    if(Mine(realBoard,row-1,col)==false)
                        playGameTill(realBoard,myPlayBoard,row-1,col,mines,moves,flag);
                }
                if (Valid (row+1, col) == true)
                {
                    if(Mine(realBoard,row+1,col)==false)
                        playGameTill(realBoard,myPlayBoard,row+1,col,mines,moves,flag);

                }
                if(Valid (row, col+1) == true)
                {
                    if(Mine(realBoard,row,col+1)==false)
                        playGameTill(realBoard,myPlayBoard,row,col+1,mines,moves,flag);

                }
                if(Valid (row, col-1) == true)
                {
                    if(Mine(realBoard,row,col-1)==false)
                        playGameTill(realBoard,myPlayBoard,row,col-1,mines,moves,flag);
                }
                if(Valid (row-1, col+1) == true)
                {
                    if(Mine(realBoard,row,col+1)==false)
                        playGameTill(realBoard,myPlayBoard,row,col+1,mines,moves,flag);
                }
                if(Valid (row-1, col-1) == true)
                {
                    if(Mine(realBoard,row-1,col-1)==false)
                        playGameTill(realBoard,myPlayBoard,row-1,col-1,mines,moves,flag);
                }
                if(Valid (row+1, col+1) == true)
                {
                    if(Mine(realBoard,row+1,col+1)==false)
                        playGameTill(realBoard,myPlayBoard,row+1,col+1,mines,moves,flag);
                }
                if(Valid (row+1, col-1) == true)
                {
                    if(Mine(realBoard,row+1,col-1)==false)
                        playGameTill(realBoard,myPlayBoard,row-1,col-1,mines,moves,flag);
                }
            }
            return false;
        }
    }
    else if (flag == YESFLAG)
    {
        myPlayBoard[row][col]=char(20);
        (*moves)--;


        return false;
    }
}

void playMinesweeper()
{
    char realBoard[MAXWIDTH][MAXLENGTH], myPlayBoard[MAXWIDTH][MAXLENGTH];
    int i,j,x,y,mines[MAXMINES][2];
    char flag;
    bool gameover=false;
    int moves=LENGTH*WIDTH-MINES;
    initialiseBoard(myPlayBoard,realBoard);
    placeMines(realBoard, mines);

    int IndexMove=0;
    while(gameover==false)
    {

        cout<<NEWLINE;
        printBoard (myPlayBoard);
        myMove(&x,&y,flag);

        if(IndexMove==0)
        {
            if (Mine (realBoard,x,y) == true)
                Replace (realBoard,x,y);
        }
        IndexMove++;
        gameover=playGameTill(realBoard, myPlayBoard, x, y, mines, &moves,flag);
        if(gameover==false&&moves==0)
        {
            for(i=0; i<WIDTH; i++)
            {
                for(j=0; j<LENGTH; j++)
                    if(realBoard[i][j]==char(4))
                        myPlayBoard[i][j]=char(20);
            }
            cout<<NEWLINE;
            system("CLS");
            cout<<NEWLINE;
            printBoard(myPlayBoard);
            cout<<NEWLINE;
            cout<<" #####  #####  #    #    ###   ###   #####  #####  ####  ###"<<NEWLINE;
            cout<<" #      #   #  ##   #   #   #  #  #  #   #    #       #  ###"<<NEWLINE;
            cout<<" #      #   #  # #  #  #       ###   #   #    #      #    #"<<NEWLINE;
            cout<<" #      #   #  #  # #  #  ###  ##    #####    #     #     #"<<NEWLINE;
            cout<<" #      #   #  #   ##  #    #  # #   #   #    #    #  "<<NEWLINE;
            cout<<" #####  #####  #    #   #####  #  #  #   #    #    ####   #"<<NEWLINE;
            cout<<NEWLINE<<NEWLINE;
            cout<<"                                                             ######"<<NEWLINE;
            cout<<" #   #  #####  #   #    #       #  #####  #    #  # # #     #      #"<<NEWLINE;
            cout<<" #   #  #   #  #   #    #       #  #   #  ##   #  # # #    #        #"<<NEWLINE;
            cout<<" #   #  #   #  #   #    #   #   #  #   #  # #  #  # # #   #  #  #    #"<<NEWLINE;
            cout<<"  # #   #   #  #   #    #   #   #  #   #  #  # #  # # #   #          #"<<NEWLINE;
            cout<<"   #    #   #  #   #     # # # #   #   #  #   ##          # #     #  #"<<NEWLINE;
            cout<<"   #    #####  #####      #   #    #####  #    #  # # #   #  #   #   #"<<NEWLINE;
            cout<<"                                                           #  ###   #"<<NEWLINE;
            cout<<"                                                            #      #"<<NEWLINE;
            cout<<"                                                             ######"<<NEWLINE;


            gameover=true;
        }
    }

}

int main()
{
    Level();
    clock_t startTime = clock();
    playMinesweeper ();
    cout<<NEWLINE<<NEWLINE;
    cout <<"Your time is:  "<< int(double( clock() - startTime ) / (double)CLOCKS_PER_SEC)<< " seconds." << endl;
    cout<<NEWLINE<<NEWLINE;
    return 0;
}
