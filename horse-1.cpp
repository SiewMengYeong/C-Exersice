#include <curses.h>
#include <cstring>
#include <unistd.h>
#include <cstdlib>

#define FINISH  70
#define START  3
#define strHorse  "~/-\\^"

const unsigned short nHorseLength = strlen(strHorse);

#include "horse.h"
void initialize();

int main()
{
    initialize();

    CHorse* horse[100];	// Assume at most 100 horses on the screen
    int i, t = 0;
    int n;

    do
    {
        n = CHorse::m_count;
        if (t % 5 == 0)
            horse[n] = new CHorse( t / 5 + 1 );
        usleep(300000);

        for (i=0; i< CHorse::m_count; i++)
            horse[i]->Forward();
        refresh();
        t++;
    } while (!horse[0]->Final() );

    endwin();
    return 0;
}

void initialize()
{
    int i;

    initscr();
    start_color();
    curs_set(0);

    init_pair(COLOR_WHITE, COLOR_WHITE, COLOR_BLACK);
    init_pair(COLOR_BLACK, COLOR_BLACK, COLOR_BLACK);
    init_pair(COLOR_RED,   COLOR_RED,   COLOR_BLACK);

    for (i=1; i<8; i++)
    {
        move(0, i*10);
        printw("%d", i);
    }
    move(1,0);
    for (i=0; i<8; i++)
        addstr("0123456789");
    for (i=0; i<8; i++)
    {
        move(i + 2, 0);
        printw("(%d)", i+1 );
        move(i + 2, FINISH - nHorseLength); 
        addch('I');
        move(i + 2, FINISH ); 
        addch('H');
    }
}

