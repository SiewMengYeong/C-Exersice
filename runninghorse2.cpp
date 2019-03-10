#include <iostream>
#include <curses.h>
#include <unistd.h>

int main()
{
int x(0);
int r[8];
srand((unsigned) time(NULL));
initscr();
curs_set(0);
start_color();
init_pair(1,COLOR_RED,COLOR_BLACK);
for (int i=0;i<8;i++)
{
  r[i]=COLS-6;
  move(i,COLS-6);addstr("^/-\\~");
  move(i,0);addch('|');
  refresh;
}

for (;;)
{  
  x=rand()%8;
  move(x,r[x]+4);addch(' ');
  if (r[x]>5)
  {
    move(x,--r[x]);addstr("^/-\\~");
    refresh();
    usleep(1);
  }
  if (r[x]<=5)
  {
    move(x,r[x]+4);addch(' ');
    attron(COLOR_PAIR(1));
    move(x,--r[x]);addstr("^/-\\~");
    refresh();
    usleep(1);
    attroff(COLOR_PAIR(1));
  }  
  if (r[x]==0)
    break;
}
move(10,10);
printw("Horse No. %d",x+1);
addstr(" is WIN!!!");
refresh();
endwin();
}
