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
int main()
{
   Level();

 return 0;
}
