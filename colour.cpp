#include <curses.h> 

int main()
{
    char i, c;
    initscr();
    noecho();
    curs_set(0);
    start_color();
    init_pair(0, COLOR_WHITE, COLOR_BLACK);
    init_pair(1, COLOR_WHITE, COLOR_RED);
    init_pair(2, COLOR_WHITE, COLOR_GREEN);
    init_pair(3, COLOR_WHITE, COLOR_YELLOW);
    init_pair(4, COLOR_WHITE, COLOR_BLUE);
    init_pair(5, COLOR_WHITE, COLOR_MAGENTA);
    init_pair(6, COLOR_WHITE, COLOR_CYAN);
    init_pair(7, COLOR_BLACK, COLOR_WHITE);

    for (i=1; i<=7; i++)
    {
        attron( COLOR_PAIR(i) );
        move(i, 40); addch(' ');
        attroff( COLOR_PAIR(i) );
    }
    refresh();

    while ( (c = getch() ) != 'q')
    {
        if ('0' <= c && c <= '7')
        {
            i = c - '0';
            attron( COLOR_PAIR(i) );
            move(10, 10); addch(' ');
            attron( COLOR_PAIR(i) );
            refresh();
        }
    }

    endwin();
    return 0;
}
