struct Tetromino
{
    CSquare s[nSize];
};

Tetromino t[nType] = {
                       0,0, 1,0, 2,0, 3,0 ,
                       0,0, 1,0, 2,0, 0,1 ,
                       0,0, 0,1,-1,0,-2,0 ,
                       0,0, 1,0, 0,1, 1,1 ,
                       0,0, 0,1, 1,0,-1,1 ,
                       0,0, 0,1, 1,0,-1,0 ,
                       0,0, 0,1, 1,1,-1,0
                     };

const int nHeight = nBottomBorder - nTopBorder -1;
const int nWidth = nRightBorder - nLeftBorder - 1;

class CTetromino
{
public:
  unsigned short type_id; // [0..6]
  unsigned short pos_x;
  unsigned short pos_y;
  static bool occupied[nHeight][nWidth];

CTetromino(int id=0,int x=0,int y=0)
{
  type_id=id;
  pos_x=x;
  pos_y=y;
}

bool Move(Movement x)
{
Draw();

for (int k=0;k<nRightBorder - nLeftBorder - 1;k++)
  if (occupied[0][k])
  {
    move(nTopBorder + 1, nRightBorder*2 + 2);
    addstr("Game Over!");
    refresh();
    echo();
    endwin();
    _Exit(0);
  }

if (detect_confliction())
{
  update_occupy();
  return 0;
}

switch(x)
{
case down:
{
  Erase();
  int y=0;
  for (int j=0;j<nSize;j++)
    if (t[type_id].s[j].dx+pos_y<=nBottomBorder-4)
      y++;
  if (y==nSize)
  {
    pos_y++;
    Draw();
    return 1;
  }
  else
  {
    Draw();
    update_occupy();
    return 0;
  }
    break;
}
case left:
{
  Erase();
  int x=0;
  for (int j=0;j<nSize;j++)
    if (t[type_id].s[j].dy+pos_x>0&occupied[t[type_id].s[j].dx+pos_y][t[type_id].s[j].dy+pos_x-1]==0)
      x++;
  if (x==nSize)
    pos_x--;
  break;
}

case right:
{
  Erase();
  int x=0;
  for (int j=0;j<nSize;j++)
    if (t[type_id].s[j].dy+pos_x<nRightBorder-nLeftBorder-2&occupied[t[type_id].s[j].dx+pos_y][t[type_id].s[j].dy+pos_x+1]==0)
      x++;
  if (x==nSize) 
    pos_x++;
  break;
}
}
  Draw();
  return 1;
}

bool detect_confliction()
{
  for (int i=0;i<nSize;i++)
  {
    short y=t[type_id].s[i].dx+pos_y;
    short x=t[type_id].s[i].dy+pos_x;
    if(occupied[y+1][x])
      return 1;
  }
  return 0;
}

void update_occupy()
{  
  for (int j=0;j<nSize;j++)
    {
      short y=t[type_id].s[j].dx+pos_y;
      short x=t[type_id].s[j].dy+pos_x;
      occupied[y][x]=1;
    }
}


private:
void Draw()
{
  attron( COLOR_PAIR(type_id+1) );
  for (int j=0;j<nSize;j++)
  {
    short x = t[type_id].s[j].dy;
    short y = t[type_id].s[j].dx;
    move( y + pos_y + nTopBorder+1,( x + pos_x + nLeftBorder+1)*2+1);addch(' ');
    move( y + pos_y + nTopBorder+1,( x + pos_x + nLeftBorder+1)*2);
    if(x==y&&y==0)
      printw("%d",type_id);
    else
      addch(' ');
  }
  attroff( COLOR_PAIR(type_id+1) );
}

void Erase()
{
  attron( COLOR_PAIR(0) );
  for (int j=0;j<nSize;j++)
  {
    short x = t[type_id].s[j].dy;
    short y = t[type_id].s[j].dx;
    move(y+pos_y+nTopBorder+1,(x+pos_x+nLeftBorder+1)*2);addch(' ');
    move(y+pos_y+nTopBorder+1,(x+pos_x+nLeftBorder+1)*2+1);addch(' ');
  }
  attroff( COLOR_PAIR(0) );
}

};

bool CTetromino::occupied[nHeight][nWidth]={0};
