#include <curses.h>

int main()
{
  int x=10,y=10;
  char c('h');
  initscr();
  noecho();
  for (;c!='q';)
  {
    move(y,x);addch('q');
    c=getch();
    move(y,x);addch(' ');
    switch(c)
    {
      case('h'):
        if (x!=0)
          x--;
        break;
      case('l'):
        if (x!=COLS-1)
          x++;
        break;
      case('j'):
        if (y!=LINES-1)
          y++;
        break;
      case('k'):
        if (y!=0)
          y--;
        break;

    }
    refresh();
  }
  endwin();
  return 0;
}
