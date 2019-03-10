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
  static int m_rotate;
  static CSquare r[nSize];

CTetromino(int id=0,int x=0,int y=0)
{
  type_id=id;
  pos_x=x;
  pos_y=y;
  m_rotate=0;
}

bool Move(Movement x)
{
rotate();
for (int k=0;k<nWidth;k++)
  if (occupied[0][k])
  {
    move(nTopBorder + 1, nRightBorder*2 + 2);
    addstr("Game Over!");
    refresh();
    echo();
    endwin();
    _Exit(0);
  }

check_horizontal();
Draw();

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
    if (r[j].dy+pos_y<=nBottomBorder-4)
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
    if (r[j].dx+pos_x>0&&occupied[r[j].dy+pos_y][r[j].dx+pos_x-1]==0)
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
    if (r[j].dx+pos_x<nRightBorder-nLeftBorder-2&&occupied[r[j].dy+pos_y][r[j].dx+pos_x+1]==0)
      x++;
  if (x==nSize) 
    pos_x++;
  break;
}
case up:
{
  Erase();
  m_rotate++;
  rotate();
  for(int j=0;j<nSize;j++)
  {
    if (occupied[r[j].dy+pos_y][r[j].dx+pos_x]||r[j].dy+pos_y==nBottomBorder-3)
    {
      m_rotate--;
      break;
    }
  }
  for(int j=0;j<nSize;j++)
  {
    if(r[j].dx+pos_x<0)
    {
      pos_x++;
    }
    if(r[j].dx+pos_x>nRightBorder-nLeftBorder-2)
    {
      pos_x--;
    }
  }

  break;
}
}
  Draw();
  return 1;
}


bool detect_confliction()
{
  rotate();
  for (int i=0;i<nSize;i++)
  {
    short y=r[i].dy+pos_y;
    short x=r[i].dx+pos_x;
    if(occupied[y+1][x])
      return 1;
  }
  return 0;
}

void update_occupy()
{
  rotate();
  for (int j=0;j<nSize;j++)
    {
      short y=r[j].dy+pos_y;
      short x=r[j].dx+pos_x;
      occupied[y][x]=1;
    }
}

void rotate()
{
  switch(m_rotate%4)
  {
    case 0:
    {
      for (int i=0;i<nSize;i++)
       {
         r[i].dy=t[type_id].s[i].dx;
         r[i].dx=t[type_id].s[i].dy;
       }
      break;       
    }
    case 3:
    {
      for (int i=0;i<nSize;i++)
      {
        r[i].dy=-t[type_id].s[i].dy;
        r[i].dx=t[type_id].s[i].dx;
      }
        break;
    }
    case 2:
    {
      for (int i=0;i<nSize;i++)
      {
        r[i].dy=-t[type_id].s[i].dx;
        r[i].dx=-t[type_id].s[i].dy;
      }
      break; 
    }
    case 1:
    {
      for (int i=0;i<nSize;i++)
      {
        r[i].dy=t[type_id].s[i].dy;
        r[i].dx=-t[type_id].s[i].dx;
      }
      break;      
    }
  }
}


void check_horizontal()
{
rotate();
int x;
for (int j=0;j<nHeight;j++)
{
  x=0;
  for (int k=0;k<nWidth;k++)
  {
    if (occupied[j][k])
      x++;
  }
  if(x==nWidth)
  {
     for( int i=0;i<3;i++)
     {
       for (int k=0;k<nWidth;k++)
       {
         attron( COLOR_PAIR(3) );
         move( j+2, (nLeftBorder+1+k)*2+1);addstr(" ");
         move( j+2, (nLeftBorder+1+k)*2);addstr(" ");
         attroff( COLOR_PAIR(3) );
       }
       refresh();
       usleep(50000);

       for (int k=0;k<nWidth;k++)
       {
         attron( COLOR_PAIR(0) );
         move( j+2, (nLeftBorder+1+k)*2+1);addstr(" ");
         move( j+2, (nLeftBorder+1+k)*2);addstr(" ");
         attroff( COLOR_PAIR(0) );
       }
       refresh();
     }
      for (int k=0;k<nWidth;k++)
       {
         occupied[j][k]=0;
       }
  }
}
}

private:
void Draw()
{
  rotate();
  attron( COLOR_PAIR(type_id+1) );
  for (int j=0;j<nSize;j++)
  {
    short y=r[j].dy;
    short x=r[j].dx;
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
    short y=r[j].dy;
    short x=r[j].dx;
    move(y+pos_y+nTopBorder+1,(x+pos_x+nLeftBorder+1)*2);addch(' ');
    move(y+pos_y+nTopBorder+1,(x+pos_x+nLeftBorder+1)*2+1);addch(' ');
  }
  attroff( COLOR_PAIR(0) );
}
};

bool CTetromino::occupied[nHeight][nWidth]={0};
int CTetromino::m_rotate=0;
CSquare CTetromino::r[nSize]={0};

