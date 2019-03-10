#include <curses.h>
int main()
{
  initscr();
//  addch('=');
//  addstr("Hello\n");
  printw("%d\t%d\n", LINES, COLS);
//  move(3, 3); addch('A');
//  move(2, 2); addch('B');
  refresh();
  endwin();
}

