void myopia()
{
		outtextxy(320,30,"MYOPIA");
		arc(450,100,270,450,75);
		arc(500,100,150,210,75);
		arc(370,100,330,390,75);
		outtextxy(340,110,"F");
		outtextxy(240,110,"2F");
		outtextxy(350,310,"F");
		outtextxy(250,310,"2F");
		outtextxy(410,340,"EYE LENS");
		outtextxy(290,370,"CORRECTIVE LENS");
		outtextxy(410,140,"EYE LENS");
		line(200,100,480,100);//center pt
		line(200,65,435,65);//far pt to top of lens
		line(435,65,480,100);//top left connecting line
		line(200,135,435,135);
		line(435,135,480,100);
		arc(450,300,270,450,75);
		arc(500,300,150,210,75);
		arc(370,300,330,390,75);
		arc(475,300,150,210,110);
		arc(225,300,330,390,110);
		line(200,300,525,300);
		line(350,280,435,265);
		line(200,280,350,280);
		line(350,320,435,335);
		line(200,320,350,320);
		line(435,335,525,300);
		line(435,265,525,300);
		line(320,245,380,245);
		line(320,355,380,355);

}
void normal()
{
		outtextxy(340,260,"F");
		outtextxy(240,260,"2F");
		outtextxy(300,130,"NORMAL EYE");
		outtextxy(410,290,"EYE LENS");
		arc(450,250,270,450,75);   
		arc(500,250,150,210,75);
		arc(370,250,330,390,75);   
		line(200,250,525,250);
		line(200,225,435,225);   	
		line(435,225,525,250);
		line(200,275,435,275);	
		line(435,275,525,250);
}
void metropia()
{
		outtextxy(320,30,"HYPERMETROPIA");
		outtextxy(340,110,"F");   	
		outtextxy(240,110,"2F");
		outtextxy(350,310,"F");	
		outtextxy(250,310,"2F");
		outtextxy(410,340,"EYE LENS");
		outtextxy(290,370,"CORRECTIVE LENS");
		outtextxy(410,140,"EYE LENS");
		arc(450,100,270,450,75);   
		arc(500,100,150,210,75);
		arc(370,100,330,390,75);	
		arc(450,300,270,450,75);
		arc(500,300,150,210,75);	
		arc(370,300,330,390,75);
		line(200,100,555,100);	
		line(200,75,435,75);
		line(435,75,555,100);  	
		line(200,125,435,125);
		line(435,125,555,100);  	
		arc(450,300,150,210,110);
		arc(260,300,330,390,110);  
		line(200,300,525,300);
		line(355,255,435,265);  	
		line(355,345,435,335);
		line(435,335,525,300); 	
		line(435,265,525,300);
		line(200,255,355,255); 	
		line(200,345,355,345);
}
void eye_lens()
{
		setcolor(7);
		myopia();
		delay(500);
		cleardevice();
		normal();
		delay(500);
		cleardevice();
		metropia();
		getch();
}
