#include <iostream>
#include <curses.h>

void frame(void);
void draw_block(int n, int y, int x , int a );
void erase_block(int n, int y, int x , int a );
int sign (int c);

int main()
{
	int n, i;
	int x = 33;
	int c;
	initscr();
	noecho();
	curs_set(0);
	srand(unsigned(time(NULL)));
	int keypad(WINDOW *win, bool bf);
	keypad(stdscr, TRUE);

	frame();
	
	timeout(300);
	
	loop:

	while (c != 'q')
	{
		n = rand() % 7 + 1;
		int a = 0;

		if ( n == 7)
		{
			for (i = 0 ; i <= 20 ; i++)
			{
				delay_1:
				draw_block(n, i, x, a);
				refresh();
				c = getch();
				erase_block(n, i, x, a);
				
				if (c == 'q')
					goto loop;
					
				switch (c)
				{
				case (KEY_LEFT):
					if (x + a == 23)
						break;
					a--;
					goto delay_1;
				case (KEY_RIGHT):
					if (x + a == 41)
						break;
					a++;
					goto delay_1;
				}
			}
		}
		else
		{
			for (i = 0 ; i < 20 ; i++)
			{
				delay_2:
				draw_block(n, i, x, a);
				refresh();
				c = getch();
				erase_block(n, i, x, a);

				if (c == 'q')
					goto loop;

				switch (c)
				{
				case (KEY_LEFT):
					if (x + a == 23)
						break;
					a--;
					goto delay_2;
				case (KEY_RIGHT):
					if (n == 3)
					{
						if (x + a == 45)
							break;
						a++;
						goto delay_2;
					}	
					else 
					{	
						if(x + a == 43)
							break;
						a++;
						goto delay_2;
					}
				}
			}
		}
	}
	endwin();	
	return 0;
}

void frame(void)
{
	for (int i=0 ; i <= 20 ; i++)
	{
		move(i,21);addch('*');
		move(i,22);addch('*');
		move(i,49);addch('*');
		move(i,50);addch('*');
	}
	
	for (int j = 21 ; j <= 50 ; j++)
	{
		move(21,j);addch('*');
		move(22,j);addch('*');
	}
	refresh();

	return;
}


void draw_block(int n, int y, int x ,int a)
{
	int j;
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_RED);
	init_pair(2, COLOR_WHITE, COLOR_GREEN);
	init_pair(3, COLOR_WHITE, COLOR_YELLOW);
	init_pair(4, COLOR_WHITE, COLOR_BLUE);
	init_pair(5, COLOR_WHITE, COLOR_MAGENTA);
	init_pair(6, COLOR_WHITE, COLOR_CYAN);
	init_pair(7, COLOR_BLACK, COLOR_WHITE);
	init_pair(8, COLOR_BLACK, COLOR_BLACK);

	int LS[4][2] = { {0+y,x+0+a},{0+y,x+2+a},{1+y,x+2+a},{1+y,x+4+a} };
	int RS[4][2] = { {0+y,x+2+a},{0+y,x+4+a},{1+y,x+2+a},{1+y,x+0+a} };
	int B [4][2] = { {0+y,x+0+a},{0+y,x+2+a},{1+y,x+0+a},{1+y,x+2+a} };
	int LG[4][2] = { {0+y,x+0+a},{1+y,x+0+a},{1+y,x+2+a},{1+y,x+4+a} };
	int T [4][2] = { {0+y,x+2+a},{1+y,x+0+a},{1+y,x+2+a},{1+y,x+4+a} };
	int RG[4][2] = { {0+y,x+4+a},{1+y,x+0+a},{1+y,x+2+a},{1+y,x+4+a} };
	int L [4][2] = { {0+y,x+0+a},{0+y,x+2+a},{0+y,x+4+a},{0+y,x+6+a} };

	attron(COLOR_PAIR(n));

	switch(n)
	{
        case 1:
                for (j = 0;j < 4;j++)
                {
		        move(LS[j][0],LS[j][1]); printw("  ");
                }
		break;
        case 2:
                for (j = 0;j < 4;j++)
                {
		        move(RS[j][0],RS[j][1]);printw("  ");
                }
		break;
        case 3:
                for (j = 0;j < 4;j++)
                {
                        move( B[j][0], B[j][1]);printw("  ");
                }
                break;
        case 4:
                for (j = 0;j < 4;j++)
                {
		        move(LG[j][0],LG[j][1]);printw("  ");
                }
		break;
        case 5:
                for (j = 0;j < 4;j++)
                {
		        move( T[j][0], T[j][1]);printw("  ");
                }
		break;
        case 6:
                for (j = 0;j < 4;j++)
                {
		        move(RG[j][0],RG[j][1]);printw("  ");
                }
		break;
        case 7:
                for (j = 0;j < 4;j++)
                {
		        move( L[j][0], L[j][1]);printw("  ");
                }
		break;
        }
	attroff(COLOR_PAIR(n));
	return;
}

void erase_block(int n,int y,int x,int a)
{
        int c, j;
        start_color();
        init_pair(8, COLOR_BLACK, COLOR_BLACK);

	int LS[4][2] = { {0+y,x+0+a},{0+y,x+2+a},{1+y,x+2+a},{1+y,x+4+a} };
        int RS[4][2] = { {0+y,x+2+a},{0+y,x+4+a},{1+y,x+2+a},{1+y,x+0+a} };
        int B [4][2] = { {0+y,x+0+a},{0+y,x+2+a},{1+y,x+0+a},{1+y,x+2+a} };
        int LG[4][2] = { {0+y,x+0+a},{1+y,x+0+a},{1+y,x+2+a},{1+y,x+4+a} };
        int T [4][2] = { {0+y,x+2+a},{1+y,x+0+a},{1+y,x+2+a},{1+y,x+4+a} };
        int RG[4][2] = { {0+y,x+4+a},{1+y,x+0+a},{1+y,x+2+a},{1+y,x+4+a} };
        int L [4][2] = { {0+y,x+0+a},{0+y,x+2+a},{0+y,x+4+a},{0+y,x+6+a} };

        attron(COLOR_PAIR(8));

        switch(n)
        {
        case 1:
                for (j = 0;j < 4;j++)
                {
                        move(LS[j][0],LS[j][1]); printw("  ");
                        refresh();
                }
		break;
        case 2:
                for (j = 0;j < 4;j++)
                {
                        move(RS[j][0],RS[j][1]);printw("  ");
                        refresh();
                }
		break;
        case 3:
                for (j = 0;j < 4;j++)
                {
                        move( B[j][0], B[j][1]);printw("  ");
                        refresh();
                }
		break;
        case 4:
                for (j = 0;j < 4;j++)
                {
                        move(LG[j][0],LG[j][1]);printw("  ");
                        refresh();
                }
		break;
        case 5:
                for (j = 0;j < 4;j++)
                {
                        move( T[j][0], T[j][1]);printw("  ");
                        refresh();
                }
		break;
        case 6:
                for (j = 0;j < 4;j++)
                {
                        move(RG[j][0],RG[j][1]);printw("  ");
                        refresh();
                }
		break;
        case 7:
                for (j = 0;j < 4;j++)
                {
                        move( L[j][0], L[j][1]);printw("  ");
                        refresh();
                }
		break;
        }
        attroff (COLOR_PAIR(8));

        return;
}
