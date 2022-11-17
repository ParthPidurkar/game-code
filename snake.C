//#include <graphics.h>
#include <stdlib.h>
#include <dos.h>
#include <conio.h>
#include <stdio.h>
#include <time.h>

check();
end();
win();
int m[500],n[500],con=20;
clock_t start,stop;
void main()
{

int gd=DETECT,gm,ch,maxx,maxy,x=13,y=14,p,q,spd=100;
int temp=p%13;
int a=0,i=0,j,t;

initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

setcolor(WHITE);//STARTING TEXT COLOR
settextstyle(3,0,6);//TEXT STYLE OF SNAKE GAME TEXT
outtextxy(200,2,"SNAKE GAME ");
settextstyle(6,0,2);//TEXT STYLE FOR LINES BELOW BELOW
outtextxy(20,80," Use Arrow Keys To Direct The Snake ");
outtextxy(20,140," Avoid The Head Of Snake Not To Hit Any Part Of Snake");
outtextxy(20,160," Pick The Beats Untill You Win The Game ");
outtextxy(20,200," Press 'Esc' Anytime To Exit ");
outtextxy(20,220," Press Any Key To Continue ");
ch=getch();
if(ch==27) exit(0);
cleardevice();
maxx=getmaxx();//FOR SNAKE DIRECTION
maxy=getmaxy();//FOR BALL'S POSITIONING
randomize();

p=random(maxx);
p=p-temp;
q=random(maxy);
temp=q%14;
q=q-temp;

start=clock();
while(1)
{
setcolor(WHITE);//color of ball
setfillstyle(SOLID_FILL,con+5);//size of ball
circle(p,q,5);
floodfill(p,q,WHITE);

if( kbhit() )//joystick
{
ch=getch();
if(ch==0)ch=getch();
if(ch==72&& a!=2) a=1;
if(ch==80&& a!=1) a=2;
if(ch==75&& a!=4) a=3;
if(ch==77&& a!=3) a=4;
}

else

{//action of escape
if(ch==27)
break;
}

if(i<20)//displaing the snake
{
m[i]=x;
n[i]=y;
i++;
}

if(i>=20)//movement of snake
{
for(j=con;j>=0;j--)
{
m[1+j]=m[j];
n[1+j]=n[j];
}
m[0]=x;
n[0]=y;

setcolor(WHITE);//color of screen
setfillstyle(SOLID_FILL,con);
circle(m[0],n[0],8);
floodfill(m[0],n[0],WHITE);
setcolor(WHITE);//color of screen
for(j=1;j<con;j++)
{
setfillstyle(SOLID_FILL,con+j%3);
circle(m[j],n[j],5);
floodfill(m[j],n[j],WHITE);
}

delay(spd);//speed of snake

setcolor(BLACK);//boundary around snake
setfillstyle(SOLID_FILL,BLACK);
circle(m[0],n[0],8);
floodfill(m[0],n[0],BLACK);

setcolor(BLACK);//boundary around ball
setfillstyle(SOLID_FILL,BLACK);
circle(m[j],n[j],5);
floodfill(m[j],n[j],BLACK);
}
stop=clock();//checks if you are out
t=(stop-start)/CLK_TCK;
check();

if(x==p&&y==q)
{
con=con+5;
if(spd>=5)
spd=spd-5;
else
spd=5;
if(con>490)
win();
p=random(maxx);
temp=p%13;
p=p-temp;
q=random(maxy);
temp=q%14;
q=q-temp;
				    }
if(a==1)  y =  y-14; if(y<0) { temp=maxy%14;y=maxy-temp;}
if(a==2)  y =  y+14; if(y>maxy) y=0;
if(a==3)  x =  x-13; if(x<0) { temp=maxx%13;x=maxx-temp;}
if(a==4)  x =  x+13; if(x>maxx) x=0;
if(a==0){  y = y+14 ;  x=x+13; }
}
}

//---------------------------------------------------------------------------

check()//IF YOU LOSE
{
int a;
for(a=1;a<con;a++)
if(m[0]==m[a] && n[0]==n[a]) end();
else continue;
}

//---------------------------------------------------------------------------

end()//LOSE
{
int j,i;
setcolor(WHITE);//END SCREEN

for(i=0;i<5;i++)
{
delay(10);
cleardevice();
delay(100);
}
settextstyle(3,0,4);//FONT AND SIZE
outtextxy(150,150," ****GAME OVER****");
delay(200);
getch();
exit(0);
}

//---------------------------------------------------------------------------

win()//WIN
{
int j,i;
setcolor(WHITE);//END SCREEN
for(i=0;i<5;i++)
{
delay(10);
cleardevice();
delay(100);
}
settextstyle(3,0,4);//FONT AND SIZE
outtextxy(150,150," ****YOU WIN****");
delay(200);
getch();
exit(0);
}
