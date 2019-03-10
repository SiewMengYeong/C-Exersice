#include <iostream>
#include <curses.h>
#include <unistd.h>

int main()
{
int x(0);
int r[20]={0};
srand((unsigned) time(NULL));
initscr();
curs_set(0);
for (int i=0;i<20;i++)
{
  move(i,0);addstr("~/-\\^");
  move(i,30);addch('|');
  refresh;
}

for (;;)
{  
  x=rand()%20;
  move(x,r[x]);addch(' ');
  move(x,++r[x]);addstr("~/-\\^");
  refresh();
  usleep(50000);

  if (r[x]==26)
    break;
}
move(22,10);
printw("Horse No. %d",x+1);
addstr(" is WIN!!!");
refresh();
endwin();
}
