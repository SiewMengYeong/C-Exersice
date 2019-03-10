#include <iostream>
#include <curses.h>
#include <unistd.h>

int main()
{
int x(0);
int r[8]={0};
srand((unsigned) time(NULL));
initscr();
for (int i=0;i<8;i++)
{
  move(i,0);addstr("~/-\\^");
  move(i,15);addch('|');
  refresh();
}

for (;;)
{  
  x=rand()%8;
  move(x,r[x]);addch(' ');
  move(x,++r[x]);addstr("~/-\\^");
  refresh();
  usleep(300000);

  if (r[x]==11)
    break;
}
move(10,10);
printw("Horse No. %d",x+1);
addstr(" is WIN!!!");
refresh();
endwin();
}
