#include <curses.h>
int main()
{
char text[10];
int i, j, c;
initscr();
getstr(text); // input the string "1,2"
addstr(text); addch('\n');
scanw("%d,%d", &i, &j); // input the string "1,2" again
printw("%d\t%d\n", i, j);
c = getch();
endwin();
return 0; }
