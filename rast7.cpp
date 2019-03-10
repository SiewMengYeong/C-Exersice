#include <curses.h>
int main()
{
  initscr();
  addch('=');
  addstr("Hello\n");
  printw("%d\t%d\n", LINES, COLS);
  move(0, 2); addch('A');
  move(1, 2); addch('B');
  refresh();
  endwin();
}
