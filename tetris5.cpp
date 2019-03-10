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

    for (int j=0;j<=LINES-5;j++)
    {
        move(j,20);addstr("**");
        move(j,COLS-20);addstr("**");
    }
    
    for (int j=22;j<=COLS-21;j++)
    {
        move(LINES-4,j);addstr("*");
        move(LINES-3,j);addstr("*");
    }

    c=getch();
    while (c!='q')
    {
       int i=rand()%7;
       int x=rand()%(COLS-25-22)+22;
       t1=time(NULL);
       z=0;
       for (int y=0; y<=LINES-5; y++)
       {
       if (y==LINES-5&&i!=0)
       {
              draw_block(i,t[i],x,y-1);
              continue;
       }
       draw_block(i,t[i],x,y);
       refresh();
       c=getch();
       if (c=='q')break;
       erase_block(i,t[i],x,y);

       if (x!=22&&c==260)x--;
       if ( t[i].s[0].dx+x!=COLS-21&& t[i].s[1].dx+x!=COLS-21&& t[i].s[2].dx+x!=COLS-21&& t[i].s[3].dx+x!=COLS-21&&c==261)x++;
       if (c==258||c==32)z++;
       if (c==260||c==261)y--;
       t2=time(NULL);
       y=floor(t2-t1-1)+z;

       if (y==LINES-5&&i==0)
            draw_block(i,t[i],x,y);
       }
    }
    endwin();
    return 0;
}
