#include <iostream>
#include <curses.h>
#include <unistd.h>

int main()
{
  initscr();
  int x(0),y(0);
  for (;x<20;x++)
  {
    move(x,y);addch('*');
    refresh();
    usleep(300000);
    move(x,y);addch(' ');
  }

  for (;y<20;y++)
  {
    move(x,y);addch('*');
    refresh();
    usleep(300000);
    move(x,y);addch(' ');
  }

  for (;x>0;x--)
  {
    move(x,y);addch('*');
    refresh();
    usleep(300000);
    move(x,y);addch(' ');
  }

  for (;y>=0;y--)
  {
    move(x,y);addch('*');
    refresh();
    usleep(300000);
    move(x,y);addch(' ');
  }
  endwin();
}
