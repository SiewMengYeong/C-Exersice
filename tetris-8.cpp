#include <curses.h>
#include <unistd.h>
#include <cstdlib>
#define nSize	4		// How many squares are there in a tetromino
#define nType   7               // How many tetromino types
#define nLeftBorder	9
#define nRightBorder	23
#define nBottomBorder   21
#define nTopBorder      1

enum Movement { up, rotate = 0, down, left, right };

class CSquare
{
public:
    short dy;
    short dx;
};

#include "tetris.h"

void init_game();
void game_over();

int main()
{
    int i, x0;
    int c;
    CTetromino a;
    init_game();

    while (true)
    {
        x0 = (rand() % (nRightBorder - nLeftBorder -1 -3 -2) )+ 2;
        i = rand() % nType;
        a = CTetromino(i, i+2);
        do {
            refresh();
            // usleep(300000);
            c=getch();
            switch (c)
            {
                case 'q':
                    echo();
                    game_over();
                    return 0;
                    break;
                case KEY_LEFT:
                case 'h':
                    a.Move(left);
                    break;
                case KEY_RIGHT:
                case 'l':
                    a.Move(right);
                    break;
            }
        } while (a.Move(down));
    }

    refresh();
    // getch();
    game_over();
    return 0;
}

void init_game()
{
    int y0, x0;
    initscr();
    noecho();
    curs_set(0);
    timeout(300);       // 300ms
    keypad(stdscr, TRUE);
    start_color();

    init_pair(0, COLOR_WHITE, COLOR_BLACK);
    init_pair(1, COLOR_WHITE, COLOR_CYAN);
    init_pair(2, COLOR_WHITE, COLOR_BLUE);
    init_pair(3, COLOR_BLACK, COLOR_WHITE);
    init_pair(4, COLOR_BLACK, COLOR_YELLOW);
    init_pair(5, COLOR_WHITE, COLOR_GREEN);
    init_pair(6, COLOR_WHITE, COLOR_MAGENTA);
    init_pair(7, COLOR_BLACK, COLOR_RED);

    for (y0=nTopBorder + 1; y0< nBottomBorder; y0++)
    {
        move(y0, nLeftBorder * 2);
        addch('*'); addch('*');
        move(y0, nRightBorder * 2);
        addch('*'); addch('*');
    }
    /* for (x0=0; x0<nWidth; x0++)
        occupy[nBottomBorder][x0] = true;
     */

        for (x0=(nLeftBorder + 1) * 2; x0<nRightBorder * 2; x0++)
        {
            /*
            move(nTopBorder, (nLeftBorder + 1) * 2 + x0);
            addch('*'); 
            move(nTopBorder+1, (nLeftBorder + 1) * 2);
            addch('*'); 
            */
            move(nBottomBorder, x0);
            addch('*'); 
            move(nBottomBorder+1, x0);
            addch('*'); 
        }

}

void game_over()
{
    move(nTopBorder + 1, nRightBorder*2 + 2);
    addstr("Game Over!");
    refresh();
    echo();
    endwin();
    _Exit(0);
}

