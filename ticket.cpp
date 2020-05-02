#include<iostream.h>
#include<dos.h>
#include<conio.h>
#include<string.h>
#include<fstream.h>
#include<graphics.h>
#include<stdlib.h>
#include"mouse-1.cpp"
#include"fusion.cpp"
#include"othello.cpp"
#include"eye-lens.cpp"

struct tick
{
		int  	x,y, pos,col;
		char 	row;
		long  	ph_no;
}t_ob[9][24]= {0};
int seat_N=0;
void box(int ltx,int lty,int rbx,int rby,int colr)
{
	setcolor(colr);
	line(ltx,lty,rbx,lty);//-------
	line(rbx,lty,rbx,rby);//right line
	line(rbx,rby,ltx,rby);//-------
	line(ltx,rby,ltx,lty);//left line
}
void layoutdetails()
{
	void seat_print(int,int,int);
	setfillstyle(1,9);
	setcolor(15);
	seat_print(90,95,8);
	outtextxy(105,95,"Available Seats");
	seat_print(270,95,BLUE);
	outtextxy(290,95,"Selected Seats");
	//***screen
	setcolor(10);
	ellipse(330,420,185,357,250,30);
	outtextxy(262,430,"SCREEN THIS WAY");
	setlinestyle(0,0,3);
	for(int arrow=230;arrow<430;arrow+=16)
	{
		line(arrow,425,arrow,436);
		putpixel(arrow,437,10);
		putpixel(arrow,439,10);
		if(arrow==246)arrow+=136;
	}
	setlinestyle(0,0,1);
	outtextxy(227,432,"v v");
	outtextxy(395,432,"v v");
		//***confirm button
	setfillstyle(1,11);
	bar(560,447,630,467);
	setcolor(9);
	outtextxy(568,453,"CONFIRM");
		//******** layout over
}
void websiteoutline()
{
		//  **** Website outline
		setcolor(8);
		//setrgbpalette(12,0,250,50);
		setfillstyle(1,CYAN);
		bar(0,0,getmaxx(),getmaxy());//setbkcolor(3);
		setlinestyle(0,0,3);
		rectangle(0,0,639,28);
		setfillstyle(1,8);
		floodfill(5,5,1);
		setfillstyle(1,15);
		bar(70,3,600,25);      //bg-wh , unav-red , avail-grey , sele-bl
		//***lhs buttons
		setcolor(3);
		outtextxy(10,10,"<");
		//outtextxy(42,10,">");
		setlinestyle(0,0,2);
		line(10,13,20,13);
		//line(36,13,46,13);
		setlinestyle(0,0,2);
		box(6,5,24,21,15);
		//box(32,5,50,21,15);
		//**close button
		setcolor(3);
		setlinestyle(0,0,1);
		line(615,8,625,20);
		line(615,20,625,8);
		setlinestyle(0,0,2);
		box(610,5,630,23,15);
		//*******
}
void loadscreen(int numofload=4,int redirect=0)
{
	cleardevice();
	setcolor(8);
	setlinestyle(0,0,3);
	delay(150);
	if(redirect==0)outtextxy(355,240,"Loading");
		else outtextxy(355,240,"Redirecting");
	delay(300);
	arc(320,240,5,85,25);
	delay(300);
	settextstyle(0,0,1);
	outtextxy(280,280,"Please Wait");
	arc(320,240,277,355,25);
	delay(300);
	switch(numofload)
	{
		case 4: arc(320,240,187,263,25);
			delay(300);
			arc(320,240,95,173,25);
			delay(300);
			break;
		case 3:	arc(320,240,187,263,25);
			delay(300);
	}
	setlinestyle(0,0,1);
	delay(1000);
	cleardevice();
}
void create_seats()
{
	char 	k = 'A';
	int 	m, n = 140;
		for (int i = 0; i <9; i++, n+= 25)
		{
			m = 60;
			for (int j = 0; j < 24; j++,m+= 20)
			{
				t_ob[i][j].x = m;
				t_ob[i][j].y=  n;
				t_ob[i][j].pos=0;
				t_ob[i][j].col = 8;
				t_ob[i][j].row=k;
				t_ob[i][j].ph_no=0;
				if (j==6||j==18) m= m+13;
			}
			k++;
		}
}
void seat_print(int st, int rows, int colr)
{
  int 	  end = st+13;
	  for(int i=0;i<5;i++)
	      for(int j=0;j<14;j++)
		  putpixel(st+j,rows+i,colr);
			for(i=0;i<4;i++)
				for(j=0;j<8;j++)
					putpixel(st+3+j,rows-5+i,colr);
			for(i=0;i<3;i++)
				for(j=0;j<14;j++)
					putpixel(st+j,rows-8+i,colr);
			for(i=0;i<3;i++)
				for(j=0;j<3;j++)
				{
					putpixel(st+j,rows-11+i,colr);
					putpixel(end-j,rows-11+i,colr);
				}
			for(i=0;i<2;i++)
				for(j=0;j<6;j++)
					putpixel(st+4+j,rows-11+i,colr);
			for(i=0;i<3;i++)
				for(j=0;j<4;j++)
				{
					putpixel(st-2+j,rows-4+i,colr);
					putpixel(end-1+j,rows-4+i,colr);
				}
			for(i=0;i<3;i++)
			{
				putpixel(st-2,rows-1+i,colr);
				putpixel(end+2,rows-1+i,colr);
			}
}
void seat()
{
		create_seats();
		setcolor(10);
		setlinestyle(0,0,2);
		setfillstyle(1,2);
	char 	k[2]="\0";
		k[0]='A';
		for (int i = 0; i <9; i++,k[0]++)
		{
			outtextxy(t_ob[i][0].x-50,t_ob[i][0].y-10,k);
			for (int j = 0; j <24; j++)
			{
			      seat_print(t_ob[i][j].x, t_ob[i][j].y,8);
			}
		}
}
int gx(int cx)
{
	for(int x=60;x<=cx;x+=21)
	{
		if(x==186||x==463)x+=25;
	}
	if(x!=60)return x-21; else return x;
}
int gy(int cy)
{
	for(int y=140;y<=cy;y+=25);//strt ycor-space,xcor-space,seat
	return y-5;//y+20-25       160-25 , 60-21 ,6-12-6 ; formation
}
int exitpage()
{
		websiteoutline();
		setcolor(7);
		outtextxy(78,10,"Secure:https://www.huliz.com/exit-page");
		setcolor(12);
		settextstyle(1,0,1);
		outtextxy(135,165,"Thank You for choosing the huliz website.");
		delay(2000);
		exit(0);
}

int check_home_selection(int x,int y)
{
	int 	ret=0;
		if(x>=55&&x<=160&&y>=145&&y<=170)ret=1;
		  else if(x>=610&&x<=630&&y>=5&&y<=23)ret=1;
		return ret;
}
void screen_write()
{
		ofstream f("screen.txt");
		for(int i=0;i<getmaxx();i++)
		{	for(int j=0;j<getmaxy();j++)
			{ int p=getpixel(i,j);
				f<<p<<" ";
			}
		}
		f.close();
}
void load_game()
{
		ifstream f("screen.txt");
		for(int i=0;i<getmaxx();i++)
		{	for(int j=0;j<getmaxy();j++)
			{ 	int p;
				f>>p;
				putpixel(i,j,p);
			}
		}
		f.close();
}
void file_write(char fname[])
{
	ofstream f(fname,ios::binary);
	for (int i = 0; i <9; i++)
	{
		for (int j = 0; j <24; j++)
		{
			if (t_ob[i][j].pos==1) t_ob[i][j].pos = 2;
			f.write((char*)&t_ob[i][j],sizeof(t_ob[i][j]));
		}
	}
	f.close();
}
void file_read(char fname[])
{
	ifstream f(fname,ios::binary);
	for (int i = 0; i <9; i++)
	{
		for (int j = 0; j <24; j++)
			f.read((char*)&t_ob[i][j],sizeof(t_ob[i][j]));
	}
	f.close();
}
void check(int cx, int cy, int mob, int num)
{
	int 	flag=0;
		layoutdetails();
		for (int i = 0; i <9&&flag==0; i++)
		   for (int j = 0; j <24&&flag==0; j++)
		   {
			int 	x, y;
				x = t_ob[i][j].x; y = t_ob[i][j].y;
			if((cx>=x-2 && cx<=x+15) && (cy >= y-15 &&  cy <=y+5))
				{
				    if (t_ob[i][j].pos!=2)
				     {
					 if (t_ob[i][j].pos==0 && seat_N <num)
					 {
						t_ob[i][j].col = BLUE;
						t_ob[i][j].pos=1; seat_N++;
						t_ob[i][j].ph_no=mob;
					 }
					 else if (t_ob[i][j].pos==1 && seat_N<=num)
					 {
						t_ob[i][j].col = 8;
						t_ob[i][j].pos=0; seat_N--;
						t_ob[i][j].ph_no=0;
					 }
					 seat_print(x,y,t_ob[i][j].col);
					 flag=1;
				    }
			     }
		   }
}
void moviebook()
{
		restorecrtmode();
int	     	nofseats,zero=0,date,mn;
long	mobno;
char 	m_name[5][60]= {"SPIDER MAN","ROBO","FIST OF FURY",
		       "IRON MAN","ROCKY III"};
		cout << endl << endl;
		for (int i = 0; i < 5; i++)
		{
			cout << "\n"<<i+1 <<" : " << m_name[i]<< endl;
		}
		do
		{
			cout << "\n\nEnter the number  : " ;
			cin >> mn;
		} while(mn<1 || mn > 5);
char	st[10];
		itoa(mn-1,st,10);
char	fname[20];
		strcpy(fname, m_name[mn-1]);
		fname[3]='\0';
		strcat(fname,st);
		strcat(fname,".dat");
		cout << fname;
		seat_N=0;
		do
		{
			clrscr();gotoxy(2,3);
			cout<<"Enter No. of tickets(1-10) : ";	cin>>nofseats;
		}while(nofseats<1||nofseats>10);
		gotoxy(2,6);
		cout <<"Enter Contact Phone number : ";
		cin>>mobno;
		gotoxy(2,8);
		cout << "Cost of each Ticket        : Rs 200" ;
		gotoxy(2,10);
		cout << "Total cost to be paid      : Rs " << 200*nofseats;
		gotoxy(2,12);
long 	card,code;
		cout <<"Enter the card Number      : ";	cin >> card;
		gotoxy(2,14);
		cout << "Enter the Password         : ";	cin >> code;
int 	gdriver=9,gmode=2;
		initgraph(&gdriver,&gmode,"f:\\tc\\BGI");
int 	flag;
		cleardevice();
		ifstream f(fname,ios::binary);
		if (!f)
		{
			loadscreen(2);
			delay(200);
			websiteoutline();
			setcolor(7);
			outtextxy(78,10,"Secure:https://www.huliz.com/movie-ticket");
			layoutdetails();
			seat();
		}
		else
		{
			setcolor(7);
			cleardevice();
			load_game();
			file_read(fname);
		}
 int 	fl=0;
		while(seat_N<=nofseats && fl==0)
		{
			  m.show_mouse();
			  m.get_status();
			  delay(300);
  			  if (cx >=560 && cx <= 630 && cy>=447 && cy <=467 &&  
                                            seat_N==nofseats) fl=1;
 			  m.hide_mouse();
			  if (fl==0) check(cx,cy,mobno,nofseats);
			  delay(300);
		}
		m.hide_mouse();
		screen_write();
		cleardevice();
		websiteoutline();
		setcolor(7);
		outtextxy(78,10,"Secure:https://www.huliz.com/ticket-booked");
		settextstyle(0,0,2);
		setcolor(15);
		outtextxy(50,65,"Thank You for using Huliz.");
		settextstyle(0,0,1);
		outtextxy(50,90,"You have sucessfully booked your ticket(s).");
		outtextxy(50,115,"Do visit us again.");
		delay(1000);
		file_write(fname);
}
void homepage()
{
		//**** Website outline
		websiteoutline();
		setcolor(7);
		outtextxy(78,10,"Secure:https://www.huliz.com/home-page");

		setcolor(12);
		settextstyle(0,0,2);
		outtextxy(135,65,"Welcome to huliz website");
		settextstyle(0,0,1);
		setcolor(15);

		box(55,145,160,170,15);
		outtextxy(60,150,"Movie Ticket");
		outtextxy(78,161,"Booking");
		box(470,145,585,170,15);
		outtextxy(500,155,"OTHELLO");
		box(470,320,585,345,15);
		outtextxy(500,330,"FUSIONS");
		box(60,320,170,345,15);
		outtextxy(71,330,"EYE - OPTICS");

}
void main()
{
	int	gdriver=9,gmode=2,res;
	mouse 	ch;
		do
		{
			initgraph(&gdriver,&gmode,"f:\\tc\\BGI");
			homepage();
			ch.show_mouse();
			ch.get_status();
			delay(100);
	if(cx>= 55 && cx <= 160&& cy >= 145 && cy <= 170) moviebook();
 	else if(cx>= 470 && cx <= 585&& cy >= 145 && cy <= 170)othello();
	else if(cx>= 470 && cx <= 585&& cy >= 320 && cy <= 345)fusion();
	else if(cx>= 60 && cx <= 170&& cy >= 320 && cy <= 345)
			{
				ch.hide_mouse();
				cleardevice();
				eye_optics();
			}
			else if(cx>= 610 && cx <= 630&& cy >= 5 && cy <= 23)
			{
				ch.show_mouse();
				cleardevice();
				exitpage();
			}
		 }while(7);
}

