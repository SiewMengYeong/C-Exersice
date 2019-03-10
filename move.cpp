#include <iostream>
#include <curses.h>
int main()
{
  initscr();
  move(LINES-1,COLS-1);addch('*');
  move(1,1);addch('*');
  refresh();
  endwin();
}
