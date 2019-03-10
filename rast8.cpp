#include <curses.h>
int main()
{
int i;
char c;
initscr();
noecho();
for (i=0; i<5; i++) {
c = getch();
switch (c) {
case 'h':
addstr("Left");
break;
case 'l':
addstr("Right");
break;
}
refresh();
}
endwin();
return 0;
}
