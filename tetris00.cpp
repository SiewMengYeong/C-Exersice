#include <curses.h>
#include <unistd.h>
#include <ctime>
#include <cmath>
#include <iostream>

struct Square
{
    int dx;
    int dy;
};

struct Tetromino
{
    Square s[4];
};

void draw_block(int n, Tetromino t ,int x ,int y)
{
  attron( COLOR_PAIR(n+1) );
  for (int j=0;j<4;j++)
  {
    move(t.s[j].dy+y,t.s[j].dx+x);addch(' ');
  }
  attroff( COLOR_PAIR(n+1) );
  return;
}

void erase_block(int n, Tetromino t,int x ,int y)
{
  attron( COLOR_PAIR(0) );
  for (int j=0;j<4;j++)
  {
    move(t.s[j].dy+y,t.s[j].dx+x);addch(' ');
  }
  attroff( COLOR_PAIR(0) );
  return;
}

int main()
{
    int x,y,c,z;
    int t1,t2;
    initscr();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);
    timeout(1000);
    srand((unsigned)time(NULL));
    start_color();
    init_pair(0, COLOR_WHITE, COLOR_BLACK);
    init_pair(1, COLOR_WHITE, COLOR_RED);
    init_pair(2, COLOR_WHITE, COLOR_GREEN);
    init_pair(3, COLOR_BLACK, COLOR_YELLOW);
    init_pair(4, COLOR_WHITE, COLOR_BLUE);
    init_pair(5, COLOR_WHITE, COLOR_MAGENTA);
    init_pair(6, COLOR_WHITE, COLOR_CYAN);
    init_pair(7, COLOR_BLACK, COLOR_WHITE);

    Tetromino t[7] = {
                       0,0, 1,0, 2,0, 3,0 ,
                       0,0, 0,1, 1,1, 2,1 ,
                       0,1, 1,1, 2,1, 2,0 ,
                       0,0, 1,0, 0,1, 1,1 ,
                       0,1, 1,1, 1,0, 2,0 ,
                       0,1, 1,1, 1,0, 2,1 ,
                       0,0, 1,0, 1,1, 2,1
                     };
    Tetromino r[7] = {

    for (int j=0;j<=LINES-5;j++)
    {
        move(j,6);addstr("**");
        move(j,18);addstr("**");
    }

    for (int j=8;j<=17;j++)
    {
        move(LINES-4,j);addstr("*");
        move(LINES-3,j);addstr("*");
    }

    for (int i=0;i<7;i++)
    {
        draw_block(i,t[i],0,i*3);
    }    
    refresh();
endwin();    
return 0;
}
