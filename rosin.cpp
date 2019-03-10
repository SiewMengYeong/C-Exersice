#include <iostream>
#include <cmath>
#include <curses.h>

int main()
{
  initscr();
  float x,y;
  int i;
  for (i=0;i<=720;i+=15)
   {
    x=i*M_PI/180;
    y=sin(x);
    y=(y*10)+10;
    move(y,i/15);addch('*');
    move(10,i/15);addch('-');
    move(i/35,24);addch('|');
   }
  move(10,48);addch('>');
  move(0,24);addch('^');  
  refresh();
  endwin();
  return 0;
} 

