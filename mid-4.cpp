#include <curses.h>

int main()
{
    const int HEIGHT = 3;
    int y;

    initscr();
    for (y=0; y<=HEIGHT; y++)
    {
        move(y, y); addch('*');
        move(y, 2*HEIGHT - y); addch('*');
    }
    refresh();
    endwin();
    return 0;
}
