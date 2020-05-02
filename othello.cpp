class  square
{ 	int	c_x,c_y;
	int 	col;
   public: void fill();
		   void plot();
		   void play(int game=3);
		   void draw_circle(int ,int , int );
		   int check_YELLOW();
		   int check(int, int, int, int);
		   int check_chance(int ,int );
		   int load_game(char *);
		   void load_fill();
		   void save_game(int);
		   void write_score(int , int );
		   void save_option(char * st);
		   void print_rules();
		   char * get_input(int , int , int , int ,int = 30,int=80);
		   void Menu();
} ob[8][8];

mouse m;
int player[2]={2,2};
int pos_i, pos_j,player_check;

void square ::fill()// Filling the array ob with center x,y coodinates and YELLOW colour
{       int	x=125,color;
		int	y=100;
		for(int i=0;i<8;i++)
		{	x=125;
			for(int j=0;j<8;j++,x = x+50)
			{	ob[i][j].c_x=x;
				ob[i][j].c_y=y;
				ob[i][j].col = YELLOW;
			}
			y+=40;
		}
		// Filling the the center 4 boxes with BLUE and RED colour
		ob[3][3].col= BLUE; ob[3][4].col= RED;
		ob[4][3].col= BLUE; ob[4][4].col= RED;
		for (i = 3; i<=4; i++)
		{	for (int j = 3; j<=4; j++)
			{
				setcolor(WHITE);
				setfillstyle(1,ob[i][j].col);
				circle(ob[i][j].c_x, ob[i][j].c_y,15);
				floodfill(ob[i][j].c_x, ob[i][j].c_y,WHITE);
			}
		}
}
void square ::load_fill()
{       int	x=125,color;
	int	y=100;
		for(int i=0;i<8;i++)
		{	x=125;
			for(int j=0;j<8;j++,x = x+50)
			{	ob[i][j].c_x=x;
				ob[i][j].c_y=y;
				ob[i][j].col = getpixel(x,y);
			}
			y+=40;
		}
}

void square::draw_circle(int i, int j, int d_c)
{
  int  x,y;
	   m.hide_mouse();
	   x = 100+j*50; y = 80+i*40;
	   setfillstyle(1,YELLOW);
	   bar(x+2,y+2,x+48,y+38);
	   setcolor(WHITE);
	   circle(x+25, y+20,15);
	   setfillstyle(1,d_c);
	   floodfill(x+25,y+20,WHITE);
	   m.show_mouse();
}
int square::check(int x,int y, int c, int oc)
{
	int flag,s,p,i,j;
		i = pos_i; j = pos_j;
		flag = 0; s= 0;
		do
		{
			 i= i+x; j = j+y;
			 if ((i<0 || i>7)|| ( j <0 || j >7)) flag= 1;
			 else
			 {
				p = ob[i][j].col;
				if (p==c || p==YELLOW) flag=1;
					else if(p==oc) s++;
			}
		} while (flag==0);
		if (s !=0 && p==c)
		{
			i = pos_i; j = pos_j;  player_check=1;
			draw_circle(i,j,c);
			ob[i][j].col=c;
			for (int k = 1; k <= s; k++)
			{
				i = i+x; j = j+y;
				ob[i][j].col=c;
				draw_circle(i,j,c);
			 }
			return s;
		}
		else return 0;
}
int square::check_chance(int color,int op_c)
{
	int	flag=0;
		for (int i=0; i<8&&flag==0;i++)
		{
			for (int j=0; j<8&&flag==0;j++)
			{
				if (ob[i][j].col==YELLOW)
				{
					for (int k = -1,m=1; m<=9&&flag==0; m++)
					{   if (m%3==0) k++;
					    if (ob[i+k][j+k].col==op_c)flag=1;
					}
				}
			}
		}
		return flag;
}
int square::check_YELLOW()
{
	int s = 0;
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			       if (ob[i][j].col==YELLOW) s++;
	       }
	       return s;
}
// load already saved  game back
int  square::load_game(char fname[])
{
	int	player_no;
		ifstream f(fname);
		f>>player[0]>>player[1]>>player_no;
		for(int i=0;i<getmaxx();i++)
		{	for(int j=0;j<getmaxy();j++)
			{ 	int p;
				f>>p;
				putpixel(i,j,p);
			}
		}
		f.close();
		return player_no;
}
// write the score n of the player in the position x,210
void square::write_score(int x, int n)
{
	char st[10];
		setfillstyle(1,0);
		bar(x-10,200,x+30,250);
		settextstyle(3,0,3);
		setcolor(WHITE);
		itoa(n, st,10);
		outtextxy(x,210,st);
}
// displaying the options save
void square::save_option(char * st)
{
	setfillstyle(1,BLUE);
	bar(10,420,100,450);
	setcolor(WHITE);
	outtextxy(20,430,st);
}
// Get input from user in x,y coordinate
char * square::get_input(int x, int y, int bc, int col,int inc,int barcord)
{
	char string[100]="\0",ch;
	int	i =0;
		ch = getch();
		while(ch!='\r')
		{
		      if (ch!='\b') string[i]= ch;
			   else i=i-2;
			string[i+1]= '\0';
			setfillstyle(1,bc);
			bar(x,y,x+barcord,y+inc);
			setcolor(col);
			outtextxy(x,y+10,string);
			i++;
			ch = getch();
		}
		return string;
}
// Write the game pixel by pixel in the hard disk
void file_write(char f_name[],int player_no)
{
	ofstream f(f_name);
		 f <<player[0]<<" " << player[1]<< " "
		   <<player_no<<" ";
		for(int i=0;i<getmaxx();i++)
		{	for(int j=0;j<getmaxy();j++)
			{ int p=getpixel(i,j);
				f<<p<<" ";
			}
		}
		f.close();
}
// Printing the Rules
void square::print_rules()
{
	char 	st[100];
	int	y=10;
	ifstream   	f("rules.txt");
		settextstyle(3,0,2);
		while(f.getline(st,100,'\n'))
		{	outtextxy(10,y,st);
			y=y+40;
			if(y>=440)
			{	getch();
				cleardevice();
				y=10;
			}
		}
}
// displaying the option Main Menu
void return_option()
{
	setfillstyle(1,BLUE);
	bar(300,420,380,450);
	setcolor(WHITE);
	outtextxy(303,430,"MAIN MENU");
}
// displaying the option Quit
void quit_option()
{
	setfillstyle(1,BLUE);
	bar(580,420,640,450);
	setcolor(WHITE);
	outtextxy(590,430,"QUIT");
}
// displaying the Save
void square::save_game(int player_no)
{
	char	f_name[20];
		setfillstyle(1,BLUE);
		bar(10,420,200,450);
		setcolor(WHITE);
		settextstyle(0,0,1);
		outtextxy(10,430,"File Name : ");
		strcpy(f_name,get_input(100,420,BLUE,WHITE));
		settextstyle(0,0,1);
		setfillstyle(1,BLUE);
		bar(10,420,200,450);
		save_option("SAVING GAME...");
		delay(1000);
		setfillstyle(1,BLACK);
		bar(10,420,200,450);
		save_option("SAVE GAME");
		file_write(f_name,player_no);
}
// Play the Game
void square::play(int game)
{
	int 	color,opp_col,points,pl_chance,pl,k;
	char 	st[10];
	char  	name[2][50];
		if(game==3)
		{
			settextstyle(3,0,3);
			outtextxy(10,100,"Enter Player Name 1 : ");
			strcpy(name[0],get_input(270,90,0,WHITE,60,400));
			outtextxy(10,200,"Enter Player Name 2 : ");
			strcpy(name[1],get_input(270,190,0,WHITE,60,400));
			cleardevice();
			setcolor(LIGHTCYAN);
			settextstyle(3,0,4);
			outtextxy(200,20,"O T H E L L O");
			setfillstyle(1,YELLOW);
			setcolor(GREEN);
			setfillstyle(1,YELLOW);
			setcolor(YELLOW);
			bar(100,80,8*50+100,80+8*40);
			setcolor(GREEN);
			for(int x=100;x<=500;x+=50)
				line(x,80,x,400);
			for( int y=80;y<=400;y+=40)
				line(100,y,500,y);
			setcolor(4);
			settextstyle(0,0,1);
			fill();
			save_option("SAVE GAME");
			return_option();
			quit_option();
			settextstyle(1,0,2);
			setcolor(LIGHTBLUE);
			outtextxy(10,100,name[0]);
			setcolor(LIGHTRED);
			outtextxy(575,100,name[1]);
			write_score(10,player[0]);
			write_score(550,player[1]);
			game = 0;
		}
		m.show_mouse();
       int 	flag = 1,pos;
		for (k = game; flag!=0; k++)
		{       flag = check_YELLOW();
			if (flag==0) continue;
			switch(k%2)
			{
				case 0 : color = BLUE;
					 opp_col= RED;pos = 5;
					 pl=1;break;
				case 1 : color = RED;
					 opp_col= BLUE;pos = 550;
					 pl=0;
					 break;
			}
			pl_chance= check_chance(color,opp_col);
			if (pl_chance==0)
			{
				cout<<"no chance"; flag=0;
				player[pl]+= (64-k+1);
				continue;
			}
			settextstyle(1,0,2);
			setcolor(color);
			outtextxy(pos,250,"Your");
			outtextxy(pos,280,"chance");
			m.get_status(); delay(500);
			pos_j = (cx-100)/50;
			pos_i = (cy-80)/40;
		if ((cx >= 580 && cx <=640) && (cy >= 420 && cy <= 450) ) exit(0);
			if ((cx >= 10 && cx <=200) && (cy >= 420 && cy <= 450) )
			{
					m.hide_mouse();
					save_game(k%2);
					m.show_mouse();k--;
					setfillstyle(1,0);
					bar(pos,250,pos+90,300);
					continue;
			}
			if ((cx >= 300 && cx <=380) && (cy >= 420 && cy <= 450) )
			{
				flag=0;
				continue;
			}
			if (ob[pos_i][pos_j].col==YELLOW)
			{
			     int  sum = 0,kk; kk = 0;
				  player_check = 0;
				  for (int pos =1; pos <=8; pos++)
				  {
					switch (pos)
					{
				    case 1 : points= check(0,1,color,opp_col);  break;
				    case 2 : points= check(-1,1,color,opp_col); break;
				    case 3 : points= check(-1,0,color,opp_col); break;
				    case 4 : points= check(-1,-1,color,opp_col);break;
				    case 5 : points= check(0,-1,color,opp_col); break;
				    case 6 : points= check(1,-1,color,opp_col); break;
				    case 7 : points= check(1,0,color,opp_col);  break;
				    case 8 : points= check(1,1,color,opp_col);  break;
					}
					if (points >0) kk++;
					sum = sum+points;
				  }

				  if (kk>0) kk=1; else kk = 0;
				  if (kk==1)
				  {
				switch(k%2&& sum!=0)
				{
				case 0 : player[0] += sum+kk; player[1]-= sum;break;
				case 1 : player[1] += sum+kk; player[0]-= sum;break;
				}
				write_score(10,player[0]);
				write_score(560,player[1]);
			  }
			  else k--;
			}
			delay(100);
			setfillstyle(1,0);
			bar(pos,250,pos+90,300);
		      }
		      //setcolor();
		      write_score(10,player[0]);
		      write_score(600,player[1]);
		      if(player[0] >player[1])
		      {
			  outtextxy(420,400,"Winner ");
			  outtextxy(400,250,name[0]);

		      }
		      else
		      if(player[1] >player[0])
		      {
			  outtextxy(420,400,"Winner ");
			  outtextxy(400,250,name[1]);

		      }
		      else outtextxy(400,400,"TIE ");

}
void square::Menu()
{
	char	st[][20] = {"1.New Game", "2.Load Game", "3.Help", 
                                  "4.Back to Main"};
	char 	f_name[20];
	int	a,b,k;
	char ch[5]="\0";
	    do
	    {
		a = 9; b = 2;
		initgraph(&a,&b,"f:\\TC\\bgi");
		setfillstyle(1,BLUE);
		bar(0,0,getmaxx(),getmaxy());
		setcolor(WHITE);
		settextstyle(4,0,3);
		b = 100;
		for (int i = 0; i <=3;i++)
		{
			outtextxy(250,b,st[i]);
			b = b+50;
		}
		outtextxy(200,b,"Enter Option : ");
		ch[0] = getche();
		//getch();
		ch[1] = '\0';
		outtextxy(360,b,ch);
		//delay(1000);
		getch();
		cleardevice();
		switch(ch[0])
		{
			case '1' :play(); break;
			case '2' :outtextxy(10,100,"Enter File Name : ");
				  strcpy(f_name,get_input(270,90,0,WHITE));
				  k = load_game(f_name);load_fill();
				  play(k);break;
			case '3' :print_rules();break;
			case '4' :;//exit(0);
		}
		//getch();
		closegraph();
	    }while(ch[0]!='4');
}
void othello()
{
	square x;
	x.Menu();
}
