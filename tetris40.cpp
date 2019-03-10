#include <curses.h> 
#include <unistd.h>
#include <ctime>
#include <iostream>

void tetris(int n, int y0, int x0)
{
	if (n==1)
        {        
            move(1+y0, 1+x0); addch(' ');
            move(1+y0, 2+x0); addch(' ');
            move(2+y0, 2+x0); addch(' ');
            move(2+y0, 3+x0); addch(' ');                
	}
	if (n==2)
        {
            move(1+y0, 2+x0); addch(' ');
            move(1+y0, 3+x0); addch(' ');
            move(2+y0, 1+x0); addch(' ');
            move(2+y0, 2+x0); addch(' ');    
	}
	if (n==3)
        {
            move(1+y0, 1+x0); addch(' ');
            move(1+y0, 2+x0); addch(' ');
            move(2+y0, 1+x0); addch(' ');
            move(2+y0, 2+x0); addch(' ');    
	}
	if (n==4)
        {
            move(1+y0, 1+x0); addch(' ');
            move(1+y0, 2+x0); addch(' ');
            move(1+y0, 3+x0); addch(' ');
            move(2+y0, 3+x0); addch(' ');    
	}
	if (n==5)
        {
            move(1+y0, 1+x0); addch(' ');
            move(1+y0, 2+x0); addch(' ');
            move(1+y0, 3+x0); addch(' ');
            move(2+y0, 2+x0); addch(' ');    
	}
	if (n==6)
        {
            move(1+y0, 1+x0); addch(' ');
            move(1+y0, 2+x0); addch(' ');
            move(1+y0, 3+x0); addch(' ');
            move(1+y0, 4+x0); addch(' ');    
	}
	if (n==7)
        { 
            move(1+y0, 1+x0); addch(' ');
            move(1+y0, 2+x0); addch(' ');
            move(1+y0, 3+x0); addch(' ');
            move(2+y0, 1+x0); addch(' ');    
	}
	return;
}

void draw_block(int n, int y0, int x0)
{
	attron( COLOR_PAIR(n) );
	tetris(n,y0,x0);
	attroff( COLOR_PAIR(n) );
}

void erase_block(int n, int y0, int x0)
{
	attron( COLOR_PAIR(0) );
	tetris(n,y0,x0);
	attroff( COLOR_PAIR(0) );
	return;
}
        
int main()
{
    int x;
    int c;
    initscr();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);
    srand((unsigned)time(NULL));
    timeout(1000);
    start_color();
    init_pair(0, COLOR_WHITE, COLOR_BLACK);
    init_pair(1, COLOR_WHITE, COLOR_RED);
    init_pair(2, COLOR_WHITE, COLOR_GREEN);
    init_pair(3, COLOR_BLACK, COLOR_YELLOW);
    init_pair(4, COLOR_WHITE, COLOR_BLUE);
    init_pair(5, COLOR_WHITE, COLOR_MAGENTA);
    init_pair(6, COLOR_WHITE, COLOR_CYAN);
    init_pair(7, COLOR_BLACK, COLOR_WHITE);

    for (int j=0;j<=LINES-5;j++)
    {
        move(j,20);addstr("**");
        move(j,COLS-20);addstr("**");
    }
    
    for (int j=22;j<=COLS-21;j++)
    {
        move(LINES-4,j);addstr("*");
        move(LINES-3,j);addstr("*");
    }

    c=getch();	
    while (c!='q')
    {
        int i=rand()%7+1;
	x=(COLS-2)/2;
        for (int y=-1; y<LINES-6; y++)
        {
            draw_block(i, y, x);
            refresh();
	    c=getch();
            if (c=='q')break;

    	    erase_block(i, y,x);

	    if (x!=22&&c==260)x--;
            if (i==3&&x!=COLS-23&&c==261)x++;
            if (i==6&&x!=COLS-25&&c==261)x++;
	    if (i!=3&&i!=6&&x!=COLS-24&&c==261)x++;
	    if (c==258||c==32)y++;
        }
    }

    endwin();
    return 0;
}


