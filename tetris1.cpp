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
        for(int i(0);i<4;i++)
        {
          for(int j(0);j<2;j++)
         {
            attron( COLOR_PAIR(0) );
            move(10+j,10+i); addch(' ');
            attroff( COLOR_PAIR(0) );
          }
        refresh();
        }
        if (c=='1')
        {
            attron( COLOR_PAIR(1) );
            move(10, 10); addch(' ');
            move(10, 11); addch(' ');
            move(11, 11); addch(' ');
            move(11, 12); addch(' ');
            attroff( COLOR_PAIR(1) );
            refresh();
        }
        if (c=='2')
        {
            attron( COLOR_PAIR(2) );
            move(10, 11); addch(' ');
            move(11, 10); addch(' ');
            move(11, 11); addch(' ');
            move(10, 12); addch(' ');
            attroff( COLOR_PAIR(1) );
            refresh();
        }
        if (c=='3')
        {
            attron( COLOR_PAIR(3) );
            move(10, 10); addch(' ');
            move(10, 11); addch(' ');
            move(11, 10); addch(' ');
            move(11, 11); addch(' ');
            attroff( COLOR_PAIR(3) );
            refresh();
        }
        if (c=='4')
        {
            attron( COLOR_PAIR(4) );
            move(10, 10); addch(' ');
            move(10, 11); addch(' ');
            move(10, 12); addch(' ');
            move(11, 12); addch(' ');
            attroff( COLOR_PAIR(4) );
            refresh();
        }
        if (c=='5')
        {
            attron( COLOR_PAIR(5) );
            move(10, 10); addch(' ');
            move(10, 11); addch(' ');
            move(10, 12); addch(' ');
            move(11, 11); addch(' ');
            attroff( COLOR_PAIR(5) );
            refresh();
        }
        if (c=='6')
        {
            attron( COLOR_PAIR(6) );
            move(10, 10); addch(' ');
            move(10, 11); addch(' ');
            move(10, 12); addch(' ');
            move(10, 13); addch(' ');
            attroff( COLOR_PAIR(6) );
            refresh();
        }
        if (c=='7')
        {
            attron( COLOR_PAIR(7) );
            move(10, 10); addch(' ');
            move(10, 11); addch(' ');
            move(10, 12); addch(' ');
            move(11, 10); addch(' ');
            attroff( COLOR_PAIR(7) );
            refresh();
        }

    }

    endwin();
    return 0;
}
