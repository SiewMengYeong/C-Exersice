struct Tetromino
{
    CSquare s[4];
};

Tetromino t[7] = {
                    0,0, 0,2, 1,2, 1,4 ,
                    0,2, 0,4, 1,0, 1,2 ,
                    0,0, 0,2, 1,0, 1,2 ,
                    0,0, 1,0, 1,2, 1,4 ,
                    0,2, 1,0, 1,2, 1,4 ,
                    0,4, 1,0, 1,2, 1,4 ,
                    0,0, 0,2, 0,4, 0,6
                 };

class CTetromino
{
	private:
		unsigned short type_id;
		unsigned short pos_x;
		unsigned short pos_y;

		const static int nHeight = nBottomBorder - nTopBorder -1;
		const static int nWidth = nRightBorder - nLeftBorder - 1;
		
		static bool occupied[nHeight][nWidth*2];

		void Draw() 
		{		
			attron(COLOR_PAIR(type_id + 1));
			
			char a = static_cast<char>(type_id)+48;
			
			for (int j = 0;j < 4;j++)
			{
				
				move(t[type_id].s[j].dy+pos_y + 2,t[type_id].s[j].dx+pos_x + 20 ); 
				
				if(j == 1)
				{
					addch(a);addch(' ');
				}
				
				else
					addstr("  ");
			}
		
			attroff(COLOR_PAIR(type_id + 1));
		}
		
		void Erase()
		{
			attron(COLOR_PAIR(0));
		
			for (int j = 0;j < 4;j++)
			{
				move(t[type_id].s[j].dy+pos_y+2,t[type_id].s[j].dx+pos_x + 20 ); addstr("  ");
			}
		
			attroff(COLOR_PAIR(0));
		}

	public:
			
		CTetromino(int z = 0 , int x = 0 , int y = 0)
		{	
			type_id = z;
			pos_x = x;
			pos_y = y;       
			Draw();
		}
		
		bool Move(int n)
		{
			if(detect_confliction())
			{
				update_occupy();
				return 0;
			}
			
			Erase();
			
			switch(n)
			{
				case (down):
					pos_y++;
					break;
					
				case (left):
					if(pos_x == 0)
						break;
					--pos_x;
					break;
					
				case (right):
					if(type_id != 2 && pos_x == 20)
						break;
					else if(type_id == 2 && pos_x == 22)
						break;
            		else if(type_id == 6 && pos_x == 18)
						break;
					++pos_x;
					break;
			}
			
			Draw();
			
			move(2,55);printw("                             ");
			move(2,55);printw("y = %d , x = %d", pos_y , pos_x);
			
			int x = (type_id == 6 ? 3 : 4);
			
			if (pos_y == nBottomBorder-x || detect_confliction())
			{
				update_occupy();
				return 0;
			}
		}

		bool detect_confliction()
		{
			for(int j = 0 ; j < 4 ; j++)
			{
				int y = t[type_id].s[j].dy + pos_y;
				int x = t[type_id].s[j].dx + pos_x;
                                if (occupied[y+1][x])
				return 1;
                                if (occupied[y+1][x+1])
                                return 1;
                        }
                        return 0;

				
		}

		void update_occupy()
		{
			for(int j = 0 ; j < 4 ; j++)
			{
				int y = t[type_id].s[j].dy + pos_y;
				int x = t[type_id].s[j].dx + pos_x;
				occupied[y][x] = 1;
				occupied[y][x + 1] = 1;
			}
		}

};
bool CTetromino::occupied[nHeight][nWidth*2]={0};
