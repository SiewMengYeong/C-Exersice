class CHorse
{
	private:
		int x;
		int y;
		
	public:
		
		static int m_count;
		
		CHorse()
		{
			x = START;
			m_count++;
			y = rand() % 8 + 2;
		}
	
		CHorse(int t)
		{
			x = START;
			y = (y % 8) + 2;
			y++;
			m_count++;
		}
	
		void Show(int x)
		{
			if(x > FINISH-10)
			{
				attron( COLOR_PAIR(COLOR_RED) );
				move(y, x);addstr(strHorse);
				attroff( COLOR_PAIR(COLOR_RED) );
			}
			
			else
				move(y, x);addstr(strHorse);
		}
	
		void Hide(int x)
		{
			attron( COLOR_PAIR(COLOR_BLACK) );
			move(y, x - 1);addch(' ');
			attroff( COLOR_PAIR(COLOR_BLACK) );
		}
		
		void Forward()
		{			
                        Hide(x);
                        x++;
                        Show(x);
			
		}

		bool Final()
		{
                if(x == FINISH )
		return 1;
                else
                return 0;
		}

};

int CHorse::m_count(0);

