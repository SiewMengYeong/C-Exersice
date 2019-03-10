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
  move(i,0);addch('Q');
  move(i,15);addch('|');
  refresh;
}

for (;;)
{  
  x=rand()%8;
  move(x,r[x]);addch(' ');
  move(x,++r[x]);addch('Q');
  refresh();
  usleep(300000);

  if (r[x]==15)
    break;
}
move(10,10);
printw("NO. %d",x+1);
addstr(" is WIN!!!");
refresh();
endwin();
}
