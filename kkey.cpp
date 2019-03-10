#include <curses.h>
int main()
{
int c;
initscr();
noecho();
keypad(stdscr, TRUE);
do {
move(9, 10);
printw("Press a key ('q' to quit):");
c = getch();
move(10, 10);
printw("%0do %c\n", c, c);
refresh();
} while (c != 'q');
endwin();
return 0;
}
