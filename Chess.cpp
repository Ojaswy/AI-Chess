#include<iostream.h>
#include<conio.h>
#include<process.h>
#include<iomanip.h>
struct AI
{
	int cover,attack,value,tini,fini,enei,enef,chance;
};
 void MOVES(int board[8][8]);

struct Piece
{
 int priority;
 int x[25],y[25],attack_v,cover_v,pos_x,pos_y,pos_x2,pos_y2,move2,dead;
 AI x1[25];
 AI y1[25];

}piece[32];


void COMP(int board[8][8])
{

 for(int i=0;i<16;i++)
 {
  int board2[8][8];
  for(int y=0;y<8;y++)
  {
	  for(int u=0;u<8;u++)
	  {
	    board2[y][u]=board[y][u];
	  }
  }
  for(int j=0 ; piece[i].x[j]!=66 ; j++)
	{
	cout<<i<<"  "<<j<<endl;
	int def_x = piece[i].pos_x;
	int def_y = piece[i].pos_y;	
	piece[i].x1[j].cover = 0;
	piece[i].x1[j].attack = 0;
	piece[i].x1[j].enei = 0;
	piece[i].x1[j].enef = 0;
	piece[i].x1[j].fini = 0;
	piece[i].x1[j].tini = 0;
	piece[i].x1[j].chance = 0;
	int o = piece[i].x[j];
	int p = piece[i].y[j];


	if (board2[p][o]<=0)
	{
			//Threat Initial Computing
		for(int m = 16;m<32;m++)
		{
			for(int n = 0;piece[m].x[n]!=66;n++)
			{
				if(board2[piece[m].y[n]][piece[m].x[n]]>0)
				{
					piece[i].x1[j].tini+=board2[piece[m].y[n]][piece[m].x[n]];

				}
			}

		}
		//Enemy Initial Computing
		for(m = 0;m<8;m++)
		{
			for(int n = 0;n<8;n++)
			{
				if(board2[m][n]<0)
					piece[i].x1[j].enei += board2[m][n];
			}
		}
		board2[p][o] = piece[i].priority;
		board2[piece[i].pos_y][piece[i].pos_x] = 0;
		piece[i].pos_x = piece[i].x[j];
		piece[i].pos_y = piece[i].y[j];
		piece[i].x1[j].value = piece[i].x[j];
		piece[i].y1[j].value = piece[i].y[j];
		MOVES(board2);
		for(m = 0;m<16;m++)
		{
			for(int u = 0;piece[m].x[u]!=66;u++)
			{
				for(int h=0;h<16;h++)
				{
					if(piece[h].pos_x == piece[m].x[u] && piece[h].pos_y == piece[m].y[u])
					{
						piece[i].y1[u].cover += piece[h].priority;
						piece[i].x1[u].cover += piece[h].priority;
					}

				}
			}
		}


		for(m = 0;m<16;m++)
		{
			for(int u = 0;piece[m].x[u]!=66;u++)
			{
				for(int h=16;h<32;h++)
				{
					if(piece[h].pos_x == piece[m].x[u] && piece[h].pos_y == piece[m].y[u])
					{
						piece[i].y1[u].attack += piece[h].priority;
						piece[i].x1[u].attack += piece[h].priority;
					}

				}
			}
		}
		int len1=0;
		for (m=0 ; m<16 ; m++)
		{
			int len = 0;
			for(int n = 0;piece[i].x[n]!=66;n++)
				len++;
			piece[i].x1[j].chance+=piece[i].priority*len;
			len1 += len;
		}
		piece[i].x1[j].chance /=len1;
		for(m = 16;m<32;m++)
		{
			for(int n = 0;piece[m].x[n]!=66;n++)
			{
				if(board2[piece[m].y[n]][piece[m].x[n]]>0)
				{
					piece[i].x1[j].fini+=board2[piece[m].y[n]][piece[m].x[n]];

				}


			}

		}
		for(m = 0;m<8;m++)
		{
			for(int n = 0;n<8;n++)
			{
				if(board2[m][n]<0)
					piece[i].x1[j].enef += board2[m][n];
			}
		}

	}


     }
	piece[i].pos_x = def_x;
	piece[i].pos_y = def_y;
	MOVES(board)
 }

 clrscr();

 }


}



void MOVES(int board[8][8])
{

//LEGALIZING...

// 1) WHITE KING

 for(int i =0;i<25;i++)
 {
	if(piece[0].x[i]!=55&&piece[0].y[i]!=55)
	{
		piece[0].x[i]=66;        //All possible positions of King becomes == 0
		piece[0].y[i]=66;
	}
 }
 int countK=0;
 for(i = 0;i<8;i++)
 {
	for(int j = 0;j<8;j++)
	{
		if((board[i][j]<=0)&&piece[0].x[countK]!=55&&piece[0].y[countK]!=55&&(i==piece[0].pos_y+1||i==piece[0].pos_y-1||i==piece[0].pos_y)&&(j==piece[0].pos_x+1||j==piece[0].pos_x-1||j==piece[0].pos_x))
		{
			piece[0].x[countK]=j;
			piece[0].y[countK]=i;
			countK++;
		}
	}
 }

// 1.5) BLACK KING

 for(i =0;i<25;i++)
 {
	if(piece[16].x[i]!=55&&piece[16].y[i]!=55)
	{
		piece[16].x[i]=66;       //All possible positions of King becomes == 0
		piece[16].y[i]=66;
	}
 }
 int countK1=0;
 for(i = 0;i<8;i++)
 {
	for(int j = 0;j<8;j++)
	{
		if((board[i][j]>=0)&&piece[16].x[countK1]!=55&&piece[16].y[countK1]!=55&&(i==piece[16].pos_y+1||i==piece[16].pos_y-1||i==piece[16].pos_y)&&(j==piece[16].pos_x+1||j==piece[16].pos_x-1||j==piece[16].pos_x))
		{
			piece[16].x[countK1]=j;
			piece[16].y[countK1]=i;
			countK1++;
		}
	}
 }

// 2) WHITE QUEEN

 for(i = 0;i<25;i++)
 {
	piece[1].x[i]=66;       //All possible positions of Queen becomes == 0
	piece[1].y[i]=66;
 }


 int countQ=0;
 //DIAGONAL MOVEMENT
 for(int m = 1;m<8;m++)
 {
	if((board[piece[1].pos_y+m][piece[1].pos_x+m]<=0)&&(piece[1].pos_y+m<8)&&(piece[1].pos_y+m>=0)&&(piece[1].pos_x+m>=0)&&(piece[1].pos_x+m<8))
	{
		if(board[piece[1].pos_y+m][piece[1].pos_x+m]<0)
		{
			piece[1].x[countQ]=piece[1].pos_x+m;     //DOWN RIGHT
			piece[1].y[countQ]=piece[1].pos_y+m;
			countQ++;
			m=8;
		}
		else
		{
			piece[1].x[countQ]=piece[1].pos_x+m;
			piece[1].y[countQ]=piece[1].pos_y+m;
			countQ++;
		}
	}
	else
		m=8;
 }
 for(m = 1;m<8;m++)
 {
	if((board[piece[1].pos_y-m][piece[1].pos_x-m]<=0)&&(piece[1].pos_y-m<8)&&(piece[1].pos_y-m>=0)&&(piece[1].pos_x-m>=0)&&(piece[1].pos_x-m<8))
	{
		if(board[piece[1].pos_y-m][piece[1].pos_x-m]<0)
		{
			piece[1].x[countQ]=piece[1].pos_x-m;     //UP LEFT
			piece[1].y[countQ]=piece[1].pos_y-m;
			countQ++;
			m=8;
		}
		else
		{
			piece[1].x[countQ]=piece[1].pos_x-m;
			piece[1].y[countQ]=piece[1].pos_y-m;
			countQ++;
		}
	}
	else
		m=8;
 }
 for(m = 1;m<8;m++)
 {
	if((board[piece[1].pos_y+m][piece[1].pos_x-m]<=0)&&(piece[1].pos_y+m<8)&&(piece[1].pos_y+m>=0)&&(piece[1].pos_x-m>=0)&&(piece[1].pos_x-m<8))
	{
		if(board[piece[1].pos_y+m][piece[1].pos_x-m]<0)
		{
			piece[1].x[countQ]=piece[1].pos_x-m;     //DOWN LEFT
			piece[1].y[countQ]=piece[1].pos_y+m;
			countQ++;
			m=8;
		}
		else
		{
			piece[1].x[countQ]=piece[1].pos_x-m;
			piece[1].y[countQ]=piece[1].pos_y+m;
			countQ++;
		}
	}
	else
		m=8;
 }
 for(m = 1;m<8;m++)
 {
	if((board[piece[1].pos_y-m][piece[1].pos_x+m]<=0)&&(piece[1].pos_y-m<8)&&(piece[1].pos_y-m>=0)&&(piece[1].pos_x+m>=0)&&(piece[1].pos_x+m<8))
	{
		if(board[piece[1].pos_y-m][piece[1].pos_x+m]<0)
		{
			piece[1].x[countQ]=piece[1].pos_x+m;     //UP RIGHT
			piece[1].y[countQ]=piece[1].pos_y-m;
			countQ++;
			m=8;
		}
		else
		{
			piece[1].x[countQ]=piece[1].pos_x+m;
			piece[1].y[countQ]=piece[1].pos_y-m;
			countQ++;
		}

	}
	else
		m=8;
 }

 //STRAIGHT MOVEMENTS
 for(m = 1;m<8;m++)
 {
	if((board[piece[1].pos_y-m][piece[1].pos_x]<=0)&&(piece[1].pos_y-m<8)&&(piece[1].pos_y-m>=0)&&(piece[1].pos_x>=0)&&(piece[1].pos_x<8))
	{
		if(board[piece[1].pos_y-m][piece[1].pos_x]<0)
		{
			piece[1].x[countQ]=piece[1].pos_x;     //UP
			piece[1].y[countQ]=piece[1].pos_y-m;
			countQ++;
			m=8;
		}
		else
		{
			piece[1].x[countQ]=piece[1].pos_x;
			piece[1].y[countQ]=piece[1].pos_y-m;
			countQ++;
		}
	}
	else
		m=8;
 }
 for(m = 1;m<8;m++)
 {
	if((board[piece[1].pos_y+m][piece[1].pos_x]<=0)&&(piece[1].pos_y+m<8)&&(piece[1].pos_y+m>=0)&&(piece[1].pos_x>=0)&&(piece[1].pos_x<8))
	{
		if(board[piece[1].pos_y+m][piece[1].pos_x]<0)
		{
			piece[1].x[countQ]=piece[1].pos_x;     //DOWN
			piece[1].y[countQ]=piece[1].pos_y+m;
			countQ++;
			m=8;
		}
		else
		{
			piece[1].x[countQ]=piece[1].pos_x;
			piece[1].y[countQ]=piece[1].pos_y+m;
			countQ++;
		}
	}
	else
		m=8;
 }
 for(m = 1;m<8;m++)
 {
	if((board[piece[1].pos_y][piece[1].pos_x-m]<=0)&&(piece[1].pos_y<8)&&(piece[1].pos_y>=0)&&(piece[1].pos_x-m>=0)&&(piece[1].pos_x-m<8))
	{
		if(board[piece[1].pos_y][piece[1].pos_x-m]<0)
		{
			piece[1].x[countQ]=piece[1].pos_x-m;     //LEFT
			piece[1].y[countQ]=piece[1].pos_y;
			countQ++;
			m=8;
		}
		else
		{
			piece[1].x[countQ]=piece[1].pos_x-m;
			piece[1].y[countQ]=piece[1].pos_y;
			countQ++;
		}
	}
	else
		m=8;
 }
 for(m = 1;m<8;m++)
 {
	if((board[piece[1].pos_y][piece[1].pos_x+m]<=0)&&(piece[1].pos_y<8)&&(piece[1].pos_y>=0)&&(piece[1].pos_x+m>=0)&&(piece[1].pos_x+m<8))
	{
		if(board[piece[1].pos_y][piece[1].pos_x+m]<0)
		{
			piece[1].x[countQ]=piece[1].pos_x+m;     //RIGHT
			piece[1].y[countQ]=piece[1].pos_y;
			countQ++;
			m=8;
		}
		else
		{
			piece[1].x[countQ]=piece[1].pos_x+m;
			piece[1].y[countQ]=piece[1].pos_y;
			countQ++;
		}

	}
	else
		m=8;
 }
 cout<<endl;

// 2.5) BLACK QUEEN

 for(i = 0;i<25;i++)
 {
	piece[17].x[i]=66;      //All possible positions of Queen becomes == 0
	piece[17].y[i]=66;
 }

 int countQ1=0;
 //DIAGONAL MOVEMENT
 for(m = 1;m<8;m++)
 {
	if((board[piece[17].pos_y+m][piece[17].pos_x+m]>=0)&&(piece[17].pos_y+m<8)&&(piece[17].pos_y+m>=0)&&(piece[17].pos_x+m>=0)&&(piece[17].pos_x+m<8))
	{
		if(board[piece[17].pos_y+m][piece[17].pos_x+m]>0)
		{
			piece[17].x[countQ1]=piece[17].pos_x+m;     //DOWN RIGHT
			piece[17].y[countQ1]=piece[17].pos_y+m;
			countQ1++;
			m=8;
		}
		else
		{
			piece[17].x[countQ1]=piece[17].pos_x+m;
			piece[17].y[countQ1]=piece[17].pos_y+m;
			countQ1++;
		}
	}
	else
		m=8;
 }
 for(m = 1;m<8;m++)
 {
	if((board[piece[17].pos_y-m][piece[17].pos_x-m]>=0)&&(piece[17].pos_y-m<8)&&(piece[17].pos_y-m>=0)&&(piece[17].pos_x-m>=0)&&(piece[17].pos_x-m<8))
	{
		if(board[piece[17].pos_y-m][piece[17].pos_x-m]>0)
		{
			piece[17].x[countQ1]=piece[17].pos_x-m;     //UP LEFT
			piece[17].y[countQ1]=piece[17].pos_y-m;
			countQ1++;
			m=8;
		}
		else
		{
			piece[17].x[countQ1]=piece[17].pos_x-m;
			piece[17].y[countQ1]=piece[17].pos_y-m;
			countQ1++;
		}
	}
	else
		m=8;
 }
 for(m = 1;m<8;m++)
 {
	if((board[piece[17].pos_y+m][piece[17].pos_x-m]>=0)&&(piece[17].pos_y+m<8)&&(piece[17].pos_y+m>=0)&&(piece[17].pos_x-m>=0)&&(piece[17].pos_x-m<8))
	{
		if(board[piece[17].pos_y+m][piece[17].pos_x-m]>0)
		{
			piece[17].x[countQ1]=piece[17].pos_x-m;     //DOWN LEFT
			piece[17].y[countQ1]=piece[17].pos_y+m;
			countQ1++;
			m=8;
		}
		else
		{
			piece[17].x[countQ1]=piece[17].pos_x-m;
			piece[17].y[countQ1]=piece[17].pos_y+m;
			countQ1++;
		}
	}
	else
		m=8;
 }
 for(m = 1;m<8;m++)
 {
	if((board[piece[17].pos_y-m][piece[17].pos_x+m]>=0)&&(piece[17].pos_y-m<8)&&(piece[17].pos_y-m>=0)&&(piece[17].pos_x+m>=0)&&(piece[17].pos_x+m<8))
	{
		if(board[piece[17].pos_y-m][piece[17].pos_x+m]>0)
		{
			piece[17].x[countQ1]=piece[17].pos_x+m;     //UP RIGHT
			piece[17].y[countQ1]=piece[17].pos_y-m;
			countQ1++;
			m=8;
		}
		else
		{
			piece[17].x[countQ1]=piece[17].pos_x+m;
			piece[17].y[countQ1]=piece[17].pos_y-m;
			countQ1++;
		}

	}
	else
		m=8;
 }

 //STRAIGHT MOVEMENTS
 for(m = 1;m<8;m++)
 {
	if((board[piece[17].pos_y-m][piece[17].pos_x]>=0)&&(piece[17].pos_y-m<8)&&(piece[17].pos_y-m>=0)&&(piece[17].pos_x>=0)&&(piece[17].pos_x<8))
	{
		if(board[piece[17].pos_y-m][piece[17].pos_x]>0)
		{
			piece[17].x[countQ1]=piece[17].pos_x;     //UP
			piece[17].y[countQ1]=piece[17].pos_y-m;
			countQ1++;
			m=8;
		}
		else
		{
			piece[17].x[countQ1]=piece[17].pos_x;
			piece[17].y[countQ1]=piece[17].pos_y-m;
			countQ1++;
		}
	}
	else
		m=8;
 }
 for(m = 1;m<8;m++)
 {
	if((board[piece[17].pos_y+m][piece[17].pos_x]>=0)&&(piece[17].pos_y+m<8)&&(piece[17].pos_y+m>=0)&&(piece[17].pos_x>=0)&&(piece[17].pos_x<8))
	{
		if(board[piece[17].pos_y+m][piece[17].pos_x]>0)
		{
			piece[17].x[countQ1]=piece[17].pos_x;     //DOWN
			piece[17].y[countQ1]=piece[17].pos_y+m;
			countQ1++;
			m=8;
		}
		else
		{
			piece[17].x[countQ1]=piece[17].pos_x;
			piece[17].y[countQ1]=piece[17].pos_y+m;
			countQ1++;
		}
	}
	else
		m=8;
 }
 for(m = 1;m<8;m++)
 {
	if((board[piece[17].pos_y][piece[17].pos_x-m]>=0)&&(piece[17].pos_y<8)&&(piece[17].pos_y>=0)&&(piece[17].pos_x-m>=0)&&(piece[17].pos_x-m<8))
	{
		if(board[piece[17].pos_y][piece[17].pos_x-m]>0)
		{
			piece[17].x[countQ1]=piece[17].pos_x-m;     //LEFT
			piece[17].y[countQ1]=piece[17].pos_y;
			countQ1++;
			m=8;
		}
		else
		{
			piece[17].x[countQ1]=piece[17].pos_x-m;
			piece[17].y[countQ1]=piece[17].pos_y;
			countQ1++;
		}
	}
	else
		m=8;
 }
 for(m = 1;m<8;m++)
 {
	if((board[piece[17].pos_y][piece[17].pos_x+m]>=0)&&(piece[17].pos_y<8)&&(piece[17].pos_y>=0)&&(piece[17].pos_x+m>=0)&&(piece[17].pos_x+m<8))
	{
		if(board[piece[17].pos_y][piece[17].pos_x+m]>0)
		{
			piece[17].x[countQ1]=piece[17].pos_x+m;     //RIGHT
			piece[17].y[countQ1]=piece[17].pos_y;
			countQ1++;
			m=8;
		}
		else
		{
			piece[17].x[countQ1]=piece[17].pos_x+m;
			piece[17].y[countQ1]=piece[17].pos_y;
			countQ1++;
		}

	}
	else
		m=8;
 }
 cout<<endl;

// 3) WHITE BISHOP

int q = -1;
int countB[2];
for(i = 0;i<2;i++)
	countB[i]=0;
for(int z = 4;z<=5;z++)
{
 q++;
 for(i =0;i<25;i++)
 {
	piece[z].x[i]=66;      //All possible positions of Bishop becomes == 0
	piece[z].y[i]=66;
 }
 for(m = 1;m<8;m++)
 {
	if((board[piece[z].pos_y+m][piece[z].pos_x+m]<=0)&&(piece[z].pos_y+m<8)&&(piece[z].pos_y+m>=0)&&(piece[z].pos_x+m>=0)&&(piece[z].pos_x+m<8))
	{
		if(board[piece[z].pos_y+m][piece[z].pos_x+m]<0)
		{
			piece[z].x[countB[q]]=piece[z].pos_x+m;     //DOWN RIGHT
			piece[z].y[countB[q]]=piece[z].pos_y+m;
			countB[q]++;
			m=8;
		}
		else
		{
			piece[z].x[countB[q]]=piece[z].pos_x+m;
			piece[z].y[countB[q]]=piece[z].pos_y+m;
			countB[q]++;
		}

	}
	else
		m=8;
 }
 for(m = 1;m<8;m++)
 {
	if((board[piece[z].pos_y-m][piece[z].pos_x-m]<=0)&&(piece[z].pos_y-m<8)&&(piece[z].pos_y-m>=0)&&(piece[z].pos_x-m>=0)&&(piece[z].pos_x-m<8))
	{
		if(board[piece[z].pos_y-m][piece[z].pos_x-m]<0)
		{
			piece[z].x[countB[q]]=piece[z].pos_x-m;     //UP LEFT
			piece[z].y[countB[q]]=piece[z].pos_y-m;
			countB[q]++;
			m=8;
		}
		else
		{
			piece[z].x[countB[q]]=piece[z].pos_x-m;     //UP LEFT
			piece[z].y[countB[q]]=piece[z].pos_y-m;
			countB[q]++;
		}
	}
	else
		m=8;
 }
 for(m = 1;m<8;m++)
 {
	if((board[piece[z].pos_y+m][piece[z].pos_x-m]<=0)&&(piece[z].pos_y+m<8)&&(piece[z].pos_y+m>=0)&&(piece[z].pos_x-m>=0)&&(piece[z].pos_x-m<8))
	{
		if(board[piece[z].pos_y+m][piece[z].pos_x-m]<0)
		{
			piece[z].x[countB[q]]=piece[z].pos_x-m;     //DOWN LEFT
			piece[z].y[countB[q]]=piece[z].pos_y+m;
			countB[q]++;
			m=8;
		}
		else
		{
			piece[z].x[countB[q]]=piece[z].pos_x-m;     //DOWN LEFT
			piece[z].y[countB[q]]=piece[z].pos_y+m;
			countB[q]++;
		}
	}
	else
		m=8;
 }
 for(m = 1;m<8;m++)
 {
	if((board[piece[z].pos_y-m][piece[z].pos_x+m]<=0)&&(piece[z].pos_y-m<8)&&(piece[z].pos_y-m>=0)&&(piece[z].pos_x+m>=0)&&(piece[z].pos_x+m<8))
	{
		if(board[piece[z].pos_y-m][piece[z].pos_x+m]<0)
		{
			piece[z].x[countB[q]]=piece[z].pos_x+m;     //UP RIGHT
			piece[z].y[countB[q]]=piece[z].pos_y-m;
			countB[q]++;
			m=8;
		}
		else
		{
			piece[z].x[countB[q]]=piece[z].pos_x+m;     //UP RIGHT
			piece[z].y[countB[q]]=piece[z].pos_y-m;
			countB[q]++;
		}
	}
	else
		m=8;
 }
}

// 3.5) BLACK BISHOP

q = -1;
int countB1[2];
for(i = 0;i<2;i++)
	countB1[i]=0;
for(z = 20;z<=21;z++)
{
 q++;
 for(i =0;i<25;i++)
 {
	piece[z].x[i]=66;      //All possible positions of Bishop becomes == 0
	piece[z].y[i]=66;
 }
 for(m = 1;m<8;m++)
 {
	if((board[piece[z].pos_y+m][piece[z].pos_x+m]>=0)&&(piece[z].pos_y+m<8)&&(piece[z].pos_y+m>=0)&&(piece[z].pos_x+m>=0)&&(piece[z].pos_x+m<8))
	{
		if(board[piece[z].pos_y+m][piece[z].pos_x+m]>0)
		{
			piece[z].x[countB1[q]]=piece[z].pos_x+m;     //DOWN RIGHT
			piece[z].y[countB1[q]]=piece[z].pos_y+m;
			countB1[q]++;
			m=8;
		}
		else
		{
			piece[z].x[countB1[q]]=piece[z].pos_x+m;
			piece[z].y[countB1[q]]=piece[z].pos_y+m;
			countB1[q]++;
		}

	}
	else
		m=8;
 }
 for(m = 1;m<8;m++)
 {
	if((board[piece[z].pos_y-m][piece[z].pos_x-m]>=0)&&(piece[z].pos_y-m<8)&&(piece[z].pos_y-m>=0)&&(piece[z].pos_x-m>=0)&&(piece[z].pos_x-m<8))
	{
		if(board[piece[z].pos_y-m][piece[z].pos_x-m]>0)
		{
			piece[z].x[countB1[q]]=piece[z].pos_x-m;     //UP LEFT
			piece[z].y[countB1[q]]=piece[z].pos_y-m;
			countB1[q]++;
			m=8;
		}
		else
		{
			piece[z].x[countB1[q]]=piece[z].pos_x-m;     //UP LEFT
			piece[z].y[countB1[q]]=piece[z].pos_y-m;
			countB1[q]++;
		}
	}
	else
		m=8;
 }
 for(m = 1;m<8;m++)
 {
	if((board[piece[z].pos_y+m][piece[z].pos_x-m]>=0)&&(piece[z].pos_y+m<8)&&(piece[z].pos_y+m>=0)&&(piece[z].pos_x-m>=0)&&(piece[z].pos_x-m<8))
	{
		if(board[piece[z].pos_y+m][piece[z].pos_x-m]>0)
		{
			piece[z].x[countB1[q]]=piece[z].pos_x-m;     //DOWN LEFT
			piece[z].y[countB1[q]]=piece[z].pos_y+m;
			countB1[q]++;
			m=8;
		}
		else
		{
			piece[z].x[countB1[q]]=piece[z].pos_x-m;     //DOWN LEFT
			piece[z].y[countB1[q]]=piece[z].pos_y+m;
			countB1[q]++;
		}
	}
	else
		m=8;
 }
 for(m = 1;m<8;m++)
 {
	if((board[piece[z].pos_y-m][piece[z].pos_x+m]>=0)&&(piece[z].pos_y-m<8)&&(piece[z].pos_y-m>=0)&&(piece[z].pos_x+m>=0)&&(piece[z].pos_x+m<8))
	{
		if(board[piece[z].pos_y-m][piece[z].pos_x+m]>0)
		{
			piece[z].x[countB1[q]]=piece[z].pos_x+m;     //UP RIGHT
			piece[z].y[countB1[q]]=piece[z].pos_y-m;
			countB1[q]++;
			m=8;
		}
		else
		{
			piece[z].x[countB1[q]]=piece[z].pos_x+m;     //UP RIGHT
			piece[z].y[countB1[q]]=piece[z].pos_y-m;
			countB1[q]++;
		}
	}
	else
		m=8;
 }
}




// 4) WHITE HORSE

 int countH[2];
 for(i = 0;i<2;i++)
 {
	countH[i]=0;
 }
 q = -1;
 for(z =2;z<4;z++)
  {
   for(i =0;i<25;i++)
   {
	piece[z].x[i]=66;       //All possible positions of Horse becomes == 0
	piece[z].y[i]=66;
   }
   q++;

	if((board[piece[z].pos_y+2][piece[z].pos_x+1]<=0)&&(piece[z].pos_y+2>=0)&&(piece[z].pos_x+1>=0)&&(piece[z].pos_x+1<8)&&(piece[z].pos_y+2<8))
	{
		piece[z].x[countH[q]]=piece[z].pos_x +1;
		piece[z].y[countH[q]]=piece[z].pos_y +2;
		countH[q]++;
	}

	if((board[piece[z].pos_y+1][piece[z].pos_x+2]<=0)&&(piece[z].pos_y+1>=0)&&(piece[z].pos_x+2>=0)&&(piece[z].pos_x+2<8)&&(piece[z].pos_y+1<8))
	{
		piece[z].x[countH[q]]=piece[z].pos_x +2;
		piece[z].y[countH[q]]=piece[z].pos_y +1;
		countH[q]++;
	}

	if((board[piece[z].pos_y-1][piece[z].pos_x+2]<=0)&&(piece[z].pos_y-1>=0)&&(piece[z].pos_x+2>=0)&&(piece[z].pos_x+2<8)&&(piece[z].pos_y-1<8))
	{
		piece[z].x[countH[q]]=piece[z].pos_x +2;
		piece[z].y[countH[q]]=piece[z].pos_y -1;
		countH[q]++;
	}

	if((board[piece[z].pos_y-2][piece[z].pos_x+1]<=0)&&(piece[z].pos_y-2>=0)&&(piece[z].pos_x+1>=0)&&(piece[z].pos_x+1<8)&&(piece[z].pos_y-2<8))
	{
		piece[z].x[countH[q]]=piece[z].pos_x +1;
		piece[z].y[countH[q]]=piece[z].pos_y -2;
		countH[q]++;
	}

	if((board[piece[z].pos_y-2][piece[z].pos_x-1]<=0)&&(piece[z].pos_y-2>=0)&&(piece[z].pos_x-1>=0)&&(piece[z].pos_x-1<8)&&(piece[z].pos_y-2<8))
	{
		piece[z].x[countH[q]]=piece[z].pos_x -1;
		piece[z].y[countH[q]]=piece[z].pos_y -2;
		countH[q]++;
	}

	if((board[piece[z].pos_y-1][piece[z].pos_x-2]<=0)&&(piece[z].pos_y-1>=0)&&(piece[z].pos_x-2>=0)&&(piece[z].pos_x-2<8)&&(piece[z].pos_y-1<8))
	{
		piece[z].x[countH[q]]=piece[z].pos_x -2;
		piece[z].y[countH[q]]=piece[z].pos_y -1;
		countH[q]++;
	}

	if((board[piece[z].pos_y+1][piece[z].pos_x-2]<=0)&&(piece[z].pos_y+1>=0)&&(piece[z].pos_x-2>=0)&&(piece[z].pos_x-2<8)&&(piece[z].pos_y+1<8))
	{
		piece[z].x[countH[q]]=piece[z].pos_x -2;
		piece[z].y[countH[q]]=piece[z].pos_y +1;
		countH[q]++;
	}

	if((board[piece[z].pos_y+2][piece[z].pos_x-1]<=0)&&(piece[z].pos_y+2>=0)&&(piece[z].pos_x-1>=0)&&(piece[z].pos_x-1<8)&&(piece[z].pos_y+2<8))
	{
		piece[z].x[countH[q]]=piece[z].pos_x -1;
		piece[z].y[countH[q]]=piece[z].pos_y +2;
		countH[q]++;
	}
  }

// 4.5) BLACK HORSE

 int countH1[2];
 for(i = 0;i<2;i++)
 {
	countH1[i]=0;
 }
 q = -1;
 for(z =18;z<=19;z++)
  {
   for(i =0;i<25;i++)
   {
	piece[z].x[i]=66;       //All possible positions of Horse becomes == 0
	piece[z].y[i]=66;
   }
   q++;

	if((board[piece[z].pos_y+2][piece[z].pos_x+1]>=0)&&(piece[z].pos_y+2>=0)&&(piece[z].pos_x+1>=0)&&(piece[z].pos_x+1<8)&&(piece[z].pos_y+2<8))
	{
		piece[z].x[countH1[q]]=piece[z].pos_x +1;
		piece[z].y[countH1[q]]=piece[z].pos_y +2;
		countH1[q]++;
	}

	if((board[piece[z].pos_y+1][piece[z].pos_x+2]>=0)&&(piece[z].pos_y+1>=0)&&(piece[z].pos_x+2>=0)&&(piece[z].pos_x+2<8)&&(piece[z].pos_y+1<8))
	{
		piece[z].x[countH1[q]]=piece[z].pos_x +2;
		piece[z].y[countH1[q]]=piece[z].pos_y +1;
		countH1[q]++;
	}

	if((board[piece[z].pos_y-1][piece[z].pos_x+2]>=0)&&(piece[z].pos_y-1>=0)&&(piece[z].pos_x+2>=0)&&(piece[z].pos_x+2<8)&&(piece[z].pos_y-1<8))
	{
		piece[z].x[countH1[q]]=piece[z].pos_x +2;
		piece[z].y[countH1[q]]=piece[z].pos_y -1;
		countH1[q]++;
	}

	if((board[piece[z].pos_y-2][piece[z].pos_x+1]>=0)&&(piece[z].pos_y-2>=0)&&(piece[z].pos_x+1>=0)&&(piece[z].pos_x+1<8)&&(piece[z].pos_y-2<8))
	{
		piece[z].x[countH1[q]]=piece[z].pos_x +1;
		piece[z].y[countH1[q]]=piece[z].pos_y -2;
		countH1[q]++;
	}

	if((board[piece[z].pos_y-2][piece[z].pos_x-1]>=0)&&(piece[z].pos_y-2>=0)&&(piece[z].pos_x-1>=0)&&(piece[z].pos_x-1<8)&&(piece[z].pos_y-2<8))
	{
		piece[z].x[countH1[q]]=piece[z].pos_x -1;
		piece[z].y[countH1[q]]=piece[z].pos_y -2;
		countH1[q]++;
	}

	if((board[piece[z].pos_y-1][piece[z].pos_x-2]>=0)&&(piece[z].pos_y-1>=0)&&(piece[z].pos_x-2>=0)&&(piece[z].pos_x-2<8)&&(piece[z].pos_y-1<8))
	{
		piece[z].x[countH1[q]]=piece[z].pos_x -2;
		piece[z].y[countH1[q]]=piece[z].pos_y -1;
		countH1[q]++;
	}

	if((board[piece[z].pos_y+1][piece[z].pos_x-2]>=0)&&(piece[z].pos_y+1>=0)&&(piece[z].pos_x-2>=0)&&(piece[z].pos_x-2<8)&&(piece[z].pos_y+1<8))
	{
		piece[z].x[countH1[q]]=piece[z].pos_x -2;
		piece[z].y[countH1[q]]=piece[z].pos_y +1;
		countH1[q]++;
	}

	if((board[piece[z].pos_y+2][piece[z].pos_x-1]>=0)&&(piece[z].pos_y+2>=0)&&(piece[z].pos_x-1>=0)&&(piece[z].pos_x-1<8)&&(piece[z].pos_y+2<8))
	{
		piece[z].x[countH1[q]]=piece[z].pos_x -1;
		piece[z].y[countH1[q]]=piece[z].pos_y +2;
		countH1[q]++;
	}
  }



// 5) WHITE CASTLE

 q = -1;
 int countC[2];
 for(i = 0;i<2;i++)
	countC[i]=0;
 for(z=6;z<8;z++)
 {
   q++;
   for(i =0;i<25;i++)
   {
	piece[z].x[i]=66;      //All possible positions of Castle becomes == 0
	piece[z].y[i]=66;
   }
   for(m = 1;m<8;m++)
   {
	if((board[piece[z].pos_y-m][piece[z].pos_x]<=0)&&(piece[z].pos_y-m<8)&&(piece[z].pos_y-m>=0)&&(piece[z].pos_x>=0)&&(piece[z].pos_x<8))
	{
		if(board[piece[z].pos_y-m][piece[z].pos_x]<0)
		{
			piece[z].x[countC[q]]=piece[z].pos_x;     //UP
			piece[z].y[countC[q]]=piece[z].pos_y-m;
			countC[q]++;
			m=8;
		}
		else
		{
			piece[z].x[countC[q]]=piece[z].pos_x;     //UP
			piece[z].y[countC[q]]=piece[z].pos_y-m;
			countC[q]++;
		}
	}
	else
		m=8;
   }
   for(m = 1;m<8;m++)
   {
	if((board[piece[z].pos_y+m][piece[z].pos_x]<=0)&&(piece[z].pos_y+m<8)&&(piece[z].pos_y+m>=0)&&(piece[z].pos_x>=0)&&(piece[z].pos_x<8))
	{
		if(board[piece[z].pos_y+m][piece[z].pos_x]<0)
		{
			piece[z].x[countC[q]]=piece[z].pos_x;     //DOWN
			piece[z].y[countC[q]]=piece[z].pos_y+m;
			countC[q]++;
			m=8;
		}
		else
		{
			piece[z].x[countC[q]]=piece[z].pos_x;     //DOWN
			piece[z].y[countC[q]]=piece[z].pos_y+m;
			countC[q]++;
		}
	}
	else
		m=8;
   }
   for(m = 1;m<8;m++)
   {
	if((board[piece[z].pos_y][piece[z].pos_x-m]<=0)&&(piece[z].pos_y<8)&&(piece[z].pos_y>=0)&&(piece[z].pos_x-m>=0)&&(piece[z].pos_x-m<8))
	{
		if(board[piece[z].pos_y][piece[z].pos_x-m]<0)
		{
			piece[z].x[countC[q]]=piece[z].pos_x-m;     //LEFT
			piece[z].y[countC[q]]=piece[z].pos_y;
			countC[q]++;
			m=8;
		}
		else
		{
			piece[z].x[countC[q]]=piece[z].pos_x-m;     //LEFT
			piece[z].y[countC[q]]=piece[z].pos_y;
			countC[q]++;
		}
	}
	else
		m=8;
   }
   for(m = 1;m<8;m++)
   {
	if((board[piece[z].pos_y][piece[z].pos_x+m]<=0)&&(piece[z].pos_y<8)&&(piece[z].pos_y>=0)&&(piece[z].pos_x+m>=0)&&(piece[z].pos_x+m<8))
	{
		if(board[piece[z].pos_y][piece[z].pos_x+m]<0)
		{
			piece[z].x[countC[q]]=piece[z].pos_x+m;     //RIGHT
			piece[z].y[countC[q]]=piece[z].pos_y;
			countC[q]++;
			m=8;
		}
		else
		{
			piece[z].x[countC[q]]=piece[z].pos_x+m;     //RIGHT
			piece[z].y[countC[q]]=piece[z].pos_y;
			countC[q]++;
		}
	}
	else
		m=8;
   }

 }


// 5.5) BLACK CASTLE

 q = -1;
 int countC1[2];
 for(i = 0;i<2;i++)
	countC1[i]=0;
 for(z=22;z<=23;z++)
 {
   q++;
   for(i =0;i<25;i++)
   {
	piece[z].x[i]=66;      //All possible positions of Castle becomes == 0
	piece[z].y[i]=66;
   }
   for(m = 1;m<8;m++)
   {
	if((board[piece[z].pos_y-m][piece[z].pos_x]>=0)&&(piece[z].pos_y-m<8)&&(piece[z].pos_y-m>=0)&&(piece[z].pos_x>=0)&&(piece[z].pos_x<8))
	{
		if(board[piece[z].pos_y-m][piece[z].pos_x]>0)
		{
			piece[z].x[countC1[q]]=piece[z].pos_x;     //UP
			piece[z].y[countC1[q]]=piece[z].pos_y-m;
			countC1[q]++;
			m=8;
		}
		else
		{
			piece[z].x[countC1[q]]=piece[z].pos_x;     //UP
			piece[z].y[countC1[q]]=piece[z].pos_y-m;
			countC1[q]++;
		}
	}
	else
		m=8;
   }
   for(m = 1;m<8;m++)
   {
	if((board[piece[z].pos_y+m][piece[z].pos_x]>=0)&&(piece[z].pos_y+m<8)&&(piece[z].pos_y+m>=0)&&(piece[z].pos_x>=0)&&(piece[z].pos_x<8))
	{
		if(board[piece[z].pos_y+m][piece[z].pos_x]>0)
		{
			piece[z].x[countC1[q]]=piece[z].pos_x;     //DOWN
			piece[z].y[countC1[q]]=piece[z].pos_y+m;
			countC1[q]++;
			m=8;
		}
		else
		{
			piece[z].x[countC1[q]]=piece[z].pos_x;     //DOWN
			piece[z].y[countC1[q]]=piece[z].pos_y+m;
			countC1[q]++;
		}
	}
	else
		m=8;
   }
   for(m = 1;m<8;m++)
   {
	if((board[piece[z].pos_y][piece[z].pos_x-m]>=0)&&(piece[z].pos_y<8)&&(piece[z].pos_y>=0)&&(piece[z].pos_x-m>=0)&&(piece[z].pos_x-m<8))
	{
		if(board[piece[z].pos_y][piece[z].pos_x-m]>0)
		{
			piece[z].x[countC1[q]]=piece[z].pos_x-m;     //LEFT
			piece[z].y[countC1[q]]=piece[z].pos_y;
			countC1[q]++;
			m=8;
		}
		else
		{
			piece[z].x[countC1[q]]=piece[z].pos_x-m;     //LEFT
			piece[z].y[countC1[q]]=piece[z].pos_y;
			countC1[q]++;
		}
	}
	else
		m=8;
   }
   for(m = 1;m<8;m++)
   {
	if((board[piece[z].pos_y][piece[z].pos_x+m]>=0)&&(piece[z].pos_y<8)&&(piece[z].pos_y>=0)&&(piece[z].pos_x+m>=0)&&(piece[z].pos_x+m<8))
	{
		if(board[piece[z].pos_y][piece[z].pos_x+m]>0)
		{
			piece[z].x[countC1[q]]=piece[z].pos_x+m;     //RIGHT
			piece[z].y[countC1[q]]=piece[z].pos_y;
			countC1[q]++;
			m=8;
		}
		else
		{
			piece[z].x[countC1[q]]=piece[z].pos_x+m;     //RIGHT
			piece[z].y[countC1[q]]=piece[z].pos_y;
			countC1[q]++;
		}
	}
	else
		m=8;
   }

 }

// 6) WHITE PAWN

 int countP[8];
 for(i = 0;i<8;i++)
 {
	countP[i]=0;
 }
 q = -1;
 for (z=8;z<16;z++)
 {
   for(i =0;i<25;i++)
   {
	piece[z].x[i]= 66;       //All possible positions of Pawn becomes == 0
	piece[z].y[i]= 66;
   }
   q++;
   if ((board[piece[z].pos_y+2][piece[z].pos_x]==0)&&(piece[z].move2!=1))
   {
	piece[z].y[countP[q]] = piece[z].pos_y+2;
	piece[z].x[countP[q]] = piece[z].pos_x;
	countP[q]++;
   }
   if (board[piece[z].pos_y+1][piece[z].pos_x]==0)
   {
	piece[z].y[countP[q]] = piece[z].pos_y+1;
	piece[z].x[countP[q]] = piece[z].pos_x;
	countP[q]++;
   }
   if (board[piece[z].pos_y+1][piece[z].pos_x-1]<0)
   {
	piece[z].y[countP[q]] = piece[z].pos_y+1;
	piece[z].x[countP[q]] = piece[z].pos_x-1;
	countP[q]++;
   }

   if (board[piece[z].pos_y+1][piece[z].pos_x+1]<0)
   {
	piece[z].x[countP[q]] = piece[z].pos_x+1;
	piece[z].y[countP[q]] = piece[z].pos_y+1;
	countP[q]++;
   }
 }

// 6.5) BLACK PAWN

 int countP1[8];
 for(i = 0;i<8;i++)
	countP1[i]=0;
 q = -1;
 for (z=24;z<=31;z++)
 {
   for(i =0;i<25;i++)
   {
	piece[z].x[i]=66;        //All possible positions of Pawn becomes == 0
	piece[z].y[i]=66;
   }
   q++;
   if ((board[piece[z].pos_y-2][piece[z].pos_x]==0)&&(piece[z].move2!=1))
   {
	piece[z].y[countP[q]] = piece[z].pos_y-2;
	piece[z].x[countP[q]] = piece[z].pos_x;
	countP[q]++;
   }
   if (board[piece[z].pos_y-1][piece[z].pos_x]==0)
   {
	piece[z].y[countP1[q]] = piece[z].pos_y-1;
	piece[z].x[countP1[q]] = piece[z].pos_x;
	countP1[q]++;
   }
   if (board[piece[z].pos_y-1][piece[z].pos_x-1]>0)
   {
	piece[z].y[countP1[q]] = piece[z].pos_y-1;
	piece[z].x[countP1[q]] = piece[z].pos_x-1;
	countP1[q]++;
   }

   if (board[piece[z].pos_y-1][piece[z].pos_x+1]>0)
   {
	piece[z].x[countP1[q]] = piece[z].pos_x+1;
	piece[z].y[countP1[q]] = piece[z].pos_y-1;
	countP1[q]++;
   }
 }

}

void CHESSBOARD(int board[8][8])
{
	clrscr();
	int col= 0;
	cout<<"                       ";
	for (int p=0;p<1;p++)
	{
//PRINTING CHESS BOARD

		for(int i = 0;i<8;i++)
		{
			for(int j = 0;j<8;j++)
			{
				if(col%2==0)
				{
					textbackground(BLACK);
					col++;
				}
				else
				{
					textbackground(WHITE);
					col++;
				}
				switch(board[i][j])
				{
					case 5:
					{
						textcolor(WHITE);
						cprintf(" ");
						textcolor(GREEN);
						cprintf("C");
						textcolor(WHITE);
						cprintf(" ");
						break;
					}
					case 4:
					{
						textcolor(WHITE);
						cprintf(" ");
						textcolor(GREEN);
						cprintf("B");
						textcolor(WHITE);
						cprintf(" ");
						break;
					}
					case 3:
					{
						textcolor(WHITE);
						cprintf(" ");
						textcolor(GREEN);
						cprintf("H");
						textcolor(WHITE);
						cprintf(" ");
						break;
					}
					case 20:
					{
						textcolor(WHITE);
						cprintf(" ");
						textcolor(GREEN);
						cprintf("K");
						textcolor(WHITE);
						cprintf(" ");
						break;
					}
					case 10:
					{
						textcolor(WHITE);
						cprintf(" ");
						textcolor(GREEN);
						cprintf("Q");
						textcolor(WHITE);
						cprintf(" ");
						break;
					}
					case 1:
					{
						textcolor(WHITE);
						cprintf(" ");
						textcolor(GREEN);
						cprintf("P");
						textcolor(WHITE);
						cprintf(" ");
						break;
					}
					case -5:
					{
						textcolor(WHITE);
						cprintf(" ");
						textcolor(YELLOW);
						cprintf("c");
						textcolor(WHITE);
						cprintf(" ");
						break;
					}
					case -4:
					{
						textcolor(WHITE);
						cprintf(" ");
						textcolor(YELLOW);
						cprintf("b");
						textcolor(WHITE);
						cprintf(" ");
						break;
					}
					case -3:
					{
						textcolor(WHITE);
						cprintf(" ");
						textcolor(YELLOW);
						cprintf("h");
						textcolor(WHITE);
						cprintf(" ");
						break;
					}
					case -20:
					{
						textcolor(WHITE);
						cprintf(" ");
						textcolor(YELLOW);
						cprintf("k");
						textcolor(WHITE);
						cprintf(" ");
						break;
					}
					case -10:
					{
						textcolor(WHITE);
						cprintf(" ");
						textcolor(YELLOW);
						cprintf("q");
						textcolor(WHITE);
						cprintf(" ");
						break;
					}
					case -1:
					{
						textcolor(WHITE);
						cprintf(" ");
						textcolor(YELLOW);
						cprintf("p");
						textcolor(WHITE);
						cprintf(" ");
						break;
					}
					case 0:
					{
						textcolor(WHITE);
						cprintf("   ");
						break;
					}

				}
			}
			cout<<" "<<i;
			if(i==0)
				cout<<"   Y VALUES";
			else if(i==7)
				cout<<"   V";
			else
				cout<<"   +";
			col++;
			cout<<endl;
			cout<<"                       ";
		}
	}
	cout<<" ";
	for(int i = 0;i<8;i++)
		cout<<i<<"  ";
	cout<<endl<<"                        X VALUES+ + + + + + + +>";

}


void main()
{



//Values for Pieces

//WHITE
piece[0].priority = 20;
piece[1].priority = 10;
piece[2].priority = 3;
piece[3].priority = 3;
piece[4].priority = 4;
piece[5].priority = 4;
piece[6].priority = 5;
piece[7].priority = 5;
piece[8].priority =  1;
piece[9].priority =  1;
piece[10].priority = 1;
piece[11].priority = 1;
piece[12].priority = 1;
piece[13].priority = 1;
piece[14].priority = 1;
piece[15].priority = 1;


//BLACK
piece[16].priority = -20;
piece[17].priority = -10;
piece[18].priority = -3;
piece[19].priority = -3;
piece[20].priority = -4;
piece[21].priority = -4;
piece[22].priority = -5;
piece[23].priority = -5;
piece[24].priority = -1;
piece[25].priority = -1;
piece[26].priority = -1;
piece[27].priority = -1;
piece[28].priority = -1;
piece[29].priority = -1;
piece[30].priority = -1;
piece[31].priority = -1;



//Positions

//WHITE
piece[0].pos_y = 0;
piece[0].pos_x = 3;
piece[1].pos_y = 0;
piece[1].pos_x = 4;
piece[2].pos_y = 0;
piece[2].pos_x = 1;
piece[3].pos_y = 0;
piece[3].pos_x = 6;
piece[4].pos_y = 0;
piece[4].pos_x = 2;
piece[5].pos_y = 0;
piece[5].pos_x = 5;
piece[6].pos_y = 0;
piece[6].pos_x = 0;
piece[7].pos_y = 0;
piece[7].pos_x = 7;
//WHITE-pawns
piece[8].pos_y = 1;
piece[8].pos_x = 0;
piece[9].pos_y = 1;
piece[9].pos_x = 1;
piece[10].pos_y = 1;
piece[10].pos_x = 2;
piece[11].pos_y = 1;
piece[11].pos_x = 3;
piece[12].pos_y = 1;
piece[12].pos_x = 4;
piece[13].pos_y = 1;
piece[13].pos_x = 5;
piece[14].pos_y = 1;
piece[14].pos_x = 6;
piece[15].pos_y = 1;
piece[15].pos_x = 7;

//BLACK
piece[16].pos_y = 7;
piece[16].pos_x = 3;
piece[17].pos_y = 7;
piece[17].pos_x = 4;
piece[18].pos_y = 7;
piece[18].pos_x = 1;
piece[19].pos_y = 7;
piece[19].pos_x = 6;
piece[20].pos_y = 7;
piece[20].pos_x = 2;
piece[21].pos_y = 7;
piece[21].pos_x = 5;
piece[22].pos_y = 7;
piece[22].pos_x = 0;
piece[23].pos_y = 7;
piece[23].pos_x = 7;
//BLACK pawns
piece[24].pos_y = 6;
piece[24].pos_x = 0;
piece[25].pos_y = 6;
piece[25].pos_x = 1;
piece[26].pos_y = 6;
piece[26].pos_x = 2;
piece[27].pos_y = 6;
piece[27].pos_x = 3;
piece[28].pos_y = 6;
piece[28].pos_x = 4;
piece[29].pos_y = 6;
piece[29].pos_x = 5;
piece[30].pos_y = 6;
piece[30].pos_x = 6;
piece[31].pos_y = 6;
piece[31].pos_x = 7;



 //building

 int board[8][8];
 for(int i = 0;i<8;i++)
 {
	for(int j=0;j<8;j++)
	{
		board[i][j]=0;  //i == y coordinate,j == x coordinate
	}

 }


 //initializing chess board

 //BLACK
 board[7][0]=-5;
 board[7][1]=-3;
 board[7][2]=-4;
 board[7][3]=-20;
 board[7][4]=-10;
 board[7][5]=-4;
 board[7][6]=-3;
 board[7][7]=-5;
 board[6][0]=-1;
 board[6][1]=-1;
 board[6][2]=-1;
 board[6][3]=-1;
 board[6][4]=-1;
 board[6][5]=-1;
 board[6][6]=-1;
 board[6][7]=-1;

 //WHITE
 board[0][0]=5;
 board[0][1]=3;
 board[0][2]=4;
 board[0][3]=20;
 board[0][4]=10;
 board[0][5]=4;
 board[0][6]=3;
 board[0][7]=5;
 board[1][0]=1;
 board[1][1]=1;
 board[1][2]=1;
 board[1][3]=1;
 board[1][4]=1;
 board[1][5]=1;
 board[1][6]=1;
 board[1][7]=1;


//INFINITE LOOP
for(int infi = 0;i>=0;i++)
{
clrscr();

 CHESSBOARD(board);
 MOVES(board);
//Taking Input from the USER



 int xval;
 int yval;
 int xcom;
 int ycom;

 cout<<endl;
 cout<<endl;
 cout<<endl;

 int flag =0;
 static int turn =0;
 int turnval1 = 0,turnval2 = 0,t1,t2;
 int check = 0,mate = 1,mate1 = 1;

 if(turn%2==0)
 {
	for(int k = 16;k<32;k++)
	{
		for(int j = 0;j<25;j++)
		{
			if(piece[k].x[j]==piece[0].pos_x&&piece[k].y[j]==piece[0].pos_y)
			{
				cout<<"CHECK"<<endl<<endl;
				check++;
			}
		}
	}
 }
 else if(turn%2!=0)
 {
	for(int k = 0;k<16;k++)
	{
		for(int j = 0;j<25;j++)
		{
			if(piece[k].x[j]==piece[16].pos_x&&piece[k].y[j]==piece[16].pos_y)
			{
				cout<<"CHECK"<<endl<<endl;
				check++;
			}
		}
	}
 }


 if(check!=0)
 {
	if(turn%2==0)
	{
		for(int c = 0;c<25;c++)
		{
			int lastx,lasty;
			lastx = piece[0].pos_x;
			lasty = piece[0].pos_y;
			piece[0].pos_x = piece[0].x[c];
			piece[0].pos_y = piece[0].y[c];
			MOVES(board);
			for(int v = 0;v<16;v++)
			{
				for(int a = 0;a<25;a++)
				{
					if(piece[v].x[a] == piece[0].pos_x&&piece[v].y[a]==piece[0].pos_y)
					{
						piece[0].pos_x = lastx;
						piece[0].pos_y = lasty;
						MOVES(board);
						piece[0].x[c] = 55;
						piece[0].y[c] = 55;
						break;
					}
				}
			}
		}
	}
	else if(turn%2!=0)
	{
		for(int c = 0;c<25;c++)
		{
			int lastx,lasty;
			lastx = piece[16].pos_x;
			lasty = piece[16].pos_y;
			piece[16].pos_x = piece[16].x[c];
			piece[16].pos_y = piece[16].y[c];
			MOVES(board);
			for(int v = 0;v<16;v++)
			{
				for(int a = 0;a<25;a++)
				{
					if(piece[v].x[a] == piece[16].pos_x&&piece[v].y[a]==piece[16].pos_y)
					{
						piece[16].pos_x = lastx;
						piece[16].pos_y = lasty;
						MOVES(board);
						piece[16].x[c] = 55;
						piece[16].y[c] = 55;
						break;
					}
				}
			}
		}

	}
 }

 if(check!=0&&turn%2!=0)
 {
	for(mate = 0;mate<25;mate++)
	{
		if(piece[16].x[mate]!=55&&piece[16].y[mate]!=55&&piece[16].x[mate]!=66)
		{
			break;
		}
	}
 }
 else if(check!=0&&turn%2==0)
 {
	for(mate1 = 0;mate1<25;mate1++)
	{
		if(piece[0].x[mate1]!=55&&piece[0].y[mate1]!=55&&piece[0].x[mate1]!=66)
		{
			break;
		}
	}
 }

 if(mate==25||mate1==25)
 {
	clrscr();
	CHESSBOARD(board);
	textcolor(RED + BLINK);
	cout<<endl<<endl<<endl<<"                                ";
	cprintf("CHECKMATE");
	getch();
	exit(0);
 }

 COMP(board);

 if(turn%2==0)
 {
	turnval1 = 0;
	turnval2 = 16;
	cout<<"CAPITAL'S TURN"<<endl;
 }
 else
 {
	turnval1 = 16;
	turnval2 = 32;
	cout<<"villager's turn"<<endl;
 }
 cout<<"What is X value of Piece to move?: ";
 cin>>xval;
 if(xval==66)
	exit(0);
 cout<<"What is Y value of Piece to move?: ";
 cin>>yval;
 if(yval==66)
	exit(0);
 cout<<"What is X position to move to?: ";
 cin>>xcom;
 if(xcom==66)
	exit(0);
 cout<<"What is Y position to move to?: ";
 cin>>ycom;
 if(ycom==66)
	exit(0);

 for (i=turnval1;i<turnval2;i++)
 {
	if (xcom<8&&ycom<8&&(piece[i].pos_x == xval)&&(piece[i].pos_y == yval)&&(board[piece[i].pos_y][piece[i].pos_x]==piece[i].priority))
	{
	      for (int j=0;j<25;j++)
	      {
		  for(int o = 0;o<32;o++)
		  {
			if(turn%2==0&&board[ycom][xcom]<0&&(piece[o].pos_x==xcom&&piece[o].pos_y==ycom))
			{
				piece[o].dead = 1;
				break;
			}
			if(turn%2!=0&&board[ycom][xcom]>0&&(piece[o].pos_x==xcom&&piece[o].pos_y==ycom))
			{
				piece[o].dead = 1;
				break;
			}
		  }
		  if((piece[i].x[j]==xcom)&&(piece[i].y[j]==ycom))
		  {
			board[yval][xval]=0;
			piece[i].pos_x = xcom;
			piece[i].pos_y = ycom;
			board[ycom][xcom] = piece[i].priority;
			flag = 1;
			MOVES(board);
			if(turn%2==0)
			{
				t1 = 16;
				t2 = 32;
			}
			else
			{
				t1 = 0;
				t2 = 16;
			}
			for(int m = t1;m<t2&&flag == 1;m++)
			{
				for(int n = 0;n<25&&flag == 1;n++)
				{
						for(int w = 0;w<25;w++)
						{
							if(m!=0&&m!=16&&turn%2==0&&piece[m].x[n]!=66&&piece[m].dead!=1)
							{
								if((piece[m].x[n]==piece[0].pos_x&&piece[m].y[n]==piece[0].pos_y))
								{
									board[ycom][xcom]=0;
									piece[i].pos_x = xval;
									piece[i].pos_y = yval;
									board[yval][xval] = piece[i].priority;
									if(piece[o].dead==1)
									{
										piece[o].dead = 0;
										piece[o].pos_x = xcom;
										piece[o].pos_y = ycom;
										board[ycom][xcom] = piece[o].priority;
									}
									if(check!=0)
										check--;
									flag = 0;
									break;
								}

							}
							else if(turn%2!=0&&m!=0&&m!=16&&piece[m].x[n]!=66&&piece[m].dead!=1)
							{
								if((piece[m].x[n]==piece[16].pos_x&&piece[m].y[n]==piece[16].pos_y))
								{
									board[ycom][xcom]=0;
									piece[i].pos_x = xval;
									piece[i].pos_y = yval;
									board[yval][xval] = piece[i].priority;
									if(piece[o].dead==1)
									{
										piece[o].pos_x = xcom;
										piece[o].pos_y = ycom;
										board[ycom][xcom] = piece[o].priority;
										piece[o].dead=0;
									}
									flag = 0;
									break;
								}

							}
						}
				}
			}
			break;
		  }
	      }

	}
 }


 for(i = 8;i<16;i++)
 {
	if((xcom==piece[i].pos_x)&&(ycom==piece[i].pos_y))
	{
		piece[i].move2 = 1;
	}
 }
 for(i = 16;i<32;i++)
 {
	if((xcom==piece[i].pos_x)&&(ycom==piece[i].pos_y))
	{
		piece[i].move2 = 1;
	}
 }

 turn++;
 if (flag==0)
 {
	turn--;
	cout<<endl<<"Input Invalid"<<endl<<"PRESS ANY KEY TO REDO";
	getch();
	CHESSBOARD(board);
 }
 else
	CHESSBOARD(board);
}
getch();
}
