void	circle1(int a , int b, int c)
{
			circle(a,b,20);
			setfillstyle(1,c);
			floodfill(a,b,WHITE);
			setcolor(WHITE);
}
void	disp(char a[],char b[], int c ,int d)
{
			settextstyle(3,0,2);
			outtextxy(c,d,a);
			settextstyle(3,0,1);
			outtextxy(c-10,d-10,b);
			delay(500);
}
void	disp2(int b , int c , char a[])
{
			settextstyle(3,0,1);
			outtextxy(b,c,a);
			delay(500);
}
void	disp3(int b , int c , char a[])
{
			settextstyle(0,0,1);
			outtextxy(b,c,a);
			delay(500);
}
void	circle2(int a,int b,int c)
{
			circle(a,b,10);
			setfillstyle(1,c);
			floodfill(a,b,WHITE);
			setcolor(WHITE);
}
void	fusion()
{
		int	a=9,b=2;
			initgraph(&a,&b,"c:\\turboc3\\bgi");
			circle1(30,30,RED);// Hydrogen 1 //
			disp(" H "," 1 ",55,30);
			circle1(530,30,RED);
			disp(" H "," 1 ",565,30);// Hydrogen 4 //
			line(30,50,50,110);
			delay(500);
			line(530,50,490,110);
			circle1(100,30,RED);//Hydrogen 2 //
			disp(" H "," 1 ",125,30);
			circle1(470,30,RED);//Hydrogen 3 //
			disp(" H "," 1 ",425,30);
			line(100,50,50,110);
			delay(500);
			line(470,50,490,110);
			delay(500);
			line(50,110,10,170);
			delay(500);
			line(490,110,360,153);
			delay(500);
			circle2(10,180,LIGHTCYAN); // Positron 1 //
			disp2(0,200," Positron ");
			circle2(350,160,LIGHTCYAN);// Positron 2 //
			disp2(300,110," Positron ");
			line(50,110,70,175);
			delay(500);
			circle1(50,180,GREEN);// H2 //
			circle1(90,180,RED);
			disp(" H "," 2 ",115,180);
			line(490,110,550,173);
			delay(500);
			circle1(530,180,GREEN);// H2 //
			circle1(570,180,RED);
			disp(" H "," 2 ",595,180);
			line(50,110,160,140);
			delay(500);
			disp3(160,140," Neutrino ");
			line(490,110,590,140);
			delay(500);
			disp3(560,140," Neutrino ");
			settextstyle(3,0,2);
			outtextxy(140,170," + ");
			delay(500);
			settextstyle(3,0,2);
			outtextxy(470,170," + ");
			delay(500);
			circle1(200,180,RED);// H1 //
			disp(" H "," 1 ",235,180);
			circle1(410,180,RED);// H1 //
			disp(" H "," 1 ",440,180);
			line(70,180,90,250);
			delay(500);
			line(550,173,540,250);
			delay(500);
			line(185,195,90,250);
			delay(500);
			line(420,200,540,250);
			delay(500);
			line(90,250,50,300);
			delay(500);
			line(540,250,600,300);
			delay(500);
			disp3(20,300," Gamma Rays ");
			disp3(560,300," Gamma Rays ");
			line(90,250,130,300);
			delay(500);
			line(540,250,460,300);
			delay(500);
			circle1(140,320,RED);// Helium 3 //
			circle1(120,355,GREEN);
			circle1(160,355,RED);
			disp(" He "," 3 ",70,355);
			circle1(450,320,RED); // Helium 3 //
			circle1(430,355,GREEN);
			circle1(470,355,RED);
			setfillstyle(1,RED);
			disp(" He "," 3 ",495,355);
			line(180,355,290,375);
			delay(500);
			line(290,375,410,350);
			delay(500);
			line(290,375,330,395);
			delay(500);
			circle1(350,400,GREEN);// Helium 4 //
			circle1(390,400,RED);
			circle1(350,440,GREEN);
			circle1(390,440,RED);
			disp(" He "," 4 ",420,440);
			line(290,375,290,435);
			delay(500);
			circle1(290,455,RED);
			disp(" H "," 1 ",315,455);
			line(290,375,200,425);
			delay(500);
			circle1(190,445,RED);
			disp(" H "," 1 ",215,445);
			getch();

}
