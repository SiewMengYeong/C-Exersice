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
    init_pair(3, COLOR_BLACK, COLOR_YELLOW);
    init_pair(4, COLOR_WHITE, COLOR_BLUE);
    init_pair(5, COLOR_WHITE, COLOR_MAGENTA);
    init_pair(6, COLOR_WHITE, COLOR_CYAN);
    init_pair(7, COLOR_BLACK, COLOR_WHITE);

    attron( COLOR_PAIR(1) );
    move(1, 40); addch('1');
    move(1, 41); addch(' ');
    move(2, 41); addch(' ');
    move(2, 42); addch(' ');
    attroff( COLOR_PAIR(1) );

    attron( COLOR_PAIR(2) );
    move(4, 40); addch('2');
    move(4, 41); addch(' ');
    move(5, 41); addch(' ');
    move(4, 42); addch(' ');
    attroff( COLOR_PAIR(2) );
    
    attron( COLOR_PAIR(3) );
    move(7, 40); addch('3');
    move(7, 41); addch(' ');
    move(8, 40); addch(' ');
    move(8, 41); addch(' ');
    attroff( COLOR_PAIR(3) );

    attron( COLOR_PAIR(4) );
    move(10, 40); addch('4');
    move(10, 41); addch(' ');
    move(10, 42); addch(' ');
    move(11, 42); addch(' ');
    attroff( COLOR_PAIR(4) );
    
    attron( COLOR_PAIR(5) );
    move(13, 40); addch('5');
    move(13, 41); addch(' ');
    move(13, 42); addch(' ');
    move(14, 41); addch(' ');
    attroff( COLOR_PAIR(5) );
   
    attron( COLOR_PAIR(6) );
    move(16, 40); addch('6');
    move(16, 41); addch(' ');
    move(16, 42); addch(' ');
    move(16, 43); addch(' ');
    attroff( COLOR_PAIR(6) );
   
    attron( COLOR_PAIR(7) );
    move(18, 40); addch('7');
    move(18, 41); addch(' ');
    move(18, 42); addch(' ');
    move(19, 40); addch(' ');
    attroff( COLOR_PAIR(7) );
            
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
