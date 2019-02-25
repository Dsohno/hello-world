#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <process.h>
#include <windows.h>
#include <time.h>


//Draw squares of different shape At the specified location
void drawsq(int i,int j)
{
	POINT poly[8]={20,20,20,40,40,40,40,20};
	poly[0].x=20;poly[0].y=20;poly[1].x=20;poly[1].y=40;
	poly[2].x=40;poly[2].y=40;poly[3].x=40;poly[3].y=20;
	poly[0].x=poly[0].x+j*20;
	poly[0].y=poly[0].y+i*20;
	poly[1].x=poly[1].x+j*20;
	poly[1].y=poly[1].y+i*20;
	poly[2].x=poly[2].x+j*20;
	poly[2].y=poly[2].y+i*20;
	poly[3].x=poly[3].x+j*20;
	poly[3].y=poly[3].y+i*20;
	setpolyfillmode(WINDING);
	setfillcolor(BLUE);
	fillpolygon(poly,4); 
}

//Determine the type of image
void drawtu(int i ,int *p, int *zw, int mvy, int mvx)
{
	int	tk[19][4][4]={{{1,1,1,0},{0,1,0,0},{0,0,0,0},{0,0,0,0}},
						{{0,1,0,0},{1,1,0,0},{0,1,0,0},{0,0,0,0}},
						{{0,1,0,0},{1,1,1,0},{0,0,0,0},{0,0,0,0}},
						{{0,1,0,0},{0,1,1,0},{0,1,0,0},{0,0,0,0}},
						{{1,1,1,1},{0,0,0,0},{0,0,0,0},{0,0,0,0}},
						{{0,1,0,0},{0,1,0,0},{0,1,0,0},{0,1,0,0}},
						{{1,1,0,0},{1,1,0,0},{0,0,0,0},{0,0,0,0}},
						{{1,0,0,0},{1,1,0,0},{0,1,0,0},{0,0,0,0}},
						{{0,1,1,0},{1,1,0,0},{0,0,0,0},{0,0,0,0}},
						{{0,1,0,0},{1,1,0,0},{1,0,0,0},{0,0,0,0}},
						{{1,1,0,0},{0,1,1,0},{0,0,0,0},{0,0,0,0}},
						{{1,0,0,0},{1,0,0,0},{1,1,0,0},{0,0,0,0}},
						{{1,1,1,0},{1,0,0,0},{0,0,0,0},{0,0,0,0}},
						{{1,1,0,0},{0,1,0,0},{0,1,0,0},{0,0,0,0}},
						{{0,0,1,0},{1,1,1,0},{0,0,0,0},{0,0,0,0}},
						{{0,1,0,0},{0,1,0,0},{1,1,0,0},{0,0,0,0}},
						{{1,0,0,0},{1,1,1,0},{0,0,0,0},{0,0,0,0}},
						{{1,1,0,0},{1,0,0,0},{1,0,0,0},{0,0,0,0}},
						{{1,1,1,0},{0,0,1,0},{0,0,0,0},{0,0,0,0}}};
	int a,b,c=0,d=0,e=0;
	for(a=0;a<4;a++)
	{
		for(b=0;b<4;b++)
			if(tk[i][a][b]==1)
			{		                     
				*(p+(mvy+a)*10+b+mvx) = tk[i][a][b];      
				d=mvy+a;e=mvx+b;
				*(zw+c)=a;
				*(zw+c+1)=b;
				c=c+2;
			}
	}
}

//Determine the type of next image
void dtn(int i ,int *p)
{
	int	tk[19][4][4]={{{1,1,1,0},{0,1,0,0},{0,0,0,0},{0,0,0,0}},
						{{0,1,0,0},{1,1,0,0},{0,1,0,0},{0,0,0,0}},
						{{0,1,0,0},{1,1,1,0},{0,0,0,0},{0,0,0,0}},
						{{0,1,0,0},{0,1,1,0},{0,1,0,0},{0,0,0,0}},
						{{1,1,1,1},{0,0,0,0},{0,0,0,0},{0,0,0,0}},
						{{0,1,0,0},{0,1,0,0},{0,1,0,0},{0,1,0,0}},
						{{1,1,0,0},{1,1,0,0},{0,0,0,0},{0,0,0,0}},
						{{1,0,0,0},{1,1,0,0},{0,1,0,0},{0,0,0,0}},
						{{0,1,1,0},{1,1,0,0},{0,0,0,0},{0,0,0,0}},
						{{0,1,0,0},{1,1,0,0},{1,0,0,0},{0,0,0,0}},
						{{1,1,0,0},{0,1,1,0},{0,0,0,0},{0,0,0,0}},
						{{1,0,0,0},{1,0,0,0},{1,1,0,0},{0,0,0,0}},
						{{1,1,1,0},{1,0,0,0},{0,0,0,0},{0,0,0,0}},
						{{1,1,0,0},{0,1,0,0},{0,1,0,0},{0,0,0,0}},
						{{0,0,1,0},{1,1,1,0},{0,0,0,0},{0,0,0,0}},
						{{0,1,0,0},{0,1,0,0},{1,1,0,0},{0,0,0,0}},
						{{1,0,0,0},{1,1,1,0},{0,0,0,0},{0,0,0,0}},
						{{1,1,0,0},{1,0,0,0},{1,0,0,0},{0,0,0,0}},
						{{1,1,1,0},{0,0,1,0},{0,0,0,0},{0,0,0,0}}};
	int a,b,c=0,d=0,e=0;
	for(a=0;a<4;a++)
		for(b=0;b<4;b++)
			*(p+a*4+b) = tk[i][a][b];      
}


//Draw pictures at the bottom
void drawd(int *q)
{
	int i,j;
	for(i=0;i<21;i++)
		for(j=0;j<10;j++)
			if(*(q+i*10+j)==1)
				drawsq(i,j);
}

//drawd next pictures
void dnp(int *q)
{
	int i,j,a=NULL,b=NULL;
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			if(*(q+i*4+j)==1)
			{
				a=i+6;
				b=j+12;
				drawsq(a,b);
			}
}

//Determine the type of image 
int pdi(int i)
{
	int a=0;
	if(i==1||i==7||i==3||i==9||i==11||i==13||i==15||i==17)
		a=1;
	if(i==2||i==6||i==8||i==10||i==0||i==12||i==14||i==16||i==18)
		a=2;
	if(i==4)
		a=3;
	return a;
}


//Determine if the image can continue to move down 
int pdfg(int *fg, int mvy, int i,int *zw, int mvx)
{
	int pdc=0;
	int x1=*zw,y1=*(zw+1)+mvx,x2=*(zw+2),y2=*(zw+3)+mvx,x3=*(zw+4),y3=*(zw+5)+mvx,x4=*(zw+6),y4=*(zw+7)+mvx;
	if(i==4)
		if(*(fg+(mvy+x1+1)*10+y1)==1||*(fg+(mvy+x2+1)*10+y2)==1||*(fg+(mvy+x3+1)*10+y3)==1||*(fg+(mvy+x4+1)*10+y4)==1)
			pdc=1;
	if(i==0||i==10)
		if(*(fg+(mvy+x1+1)*10+y1)==1||*(fg+(mvy+x3+1)*10+y3)==1||*(fg+(mvy+x4+1)*10+y4)==1)
			pdc=1;
	if(i==2||i==8||i==12||i==14||i==16)
		if(*(fg+(mvy+x2+1)*10+y2)==1||*(fg+(mvy+x3+1)*10+y3)==1||*(fg+(mvy+x4+1)*10+y4)==1)
			pdc=1;
	if(i==18)
		if(*(fg+(mvy+x2+1)*10+y2)==1||*(fg+(mvy+x1+1)*10+y1)==1||*(fg+(mvy+x4+1)*10+y4)==1)
			pdc=1;	if(i==3||i==9||i==6||i==11||i==15)
		if(*(fg+(mvy+x3+1)*10+y3)==1||*(fg+(mvy+x4+1)*10+y4)==1)
			pdc=1;
	if(i==1||i==7||i==17)
		if(*(fg+(mvy+x2+1)*10+y2)==1||*(fg+(mvy+x4+1)*10+y4)==1)
			pdc=1;
	if(i==13)
		if(*(fg+(mvy+x1+1)*10+y1)==1||*(fg+(mvy+x4+1)*10+y4)==1)
			pdc=1;	if(i==5)
		if(*(fg+(mvy+x4+1)*10+y4)==1)
			pdc=1;
	return pdc;
}


//Determine if the image can move left 
int pdl(int *fg,int *zw,int i,int mvy,int mvx)
{
	int pdil=0;
	int x1=*zw,y1=*(zw+1)+mvx,x2=*(zw+2),y2=*(zw+3)+mvx,x3=*(zw+4),y3=*(zw+5)+mvx,x4=*(zw+6),y4=*(zw+7)+mvx;
	if(y1!=0&&y2!=0&&y3!=0&&y4!=0)
	{
		if(i==5)
			if(*(fg+(mvy+x1)*10+y1-1)==1||*(fg+(mvy+x2)*10+y2-1)==1||*(fg+(mvy+x3)*10+y3-1)==1||*(fg+(mvy+x4)*10+y4-1)==1)
				pdil=1;
		if(i==1||i==3||i==7||i==9)
			if(*(fg+(mvy+x1)*10+y1-1)==1||*(fg+(mvy+x2)*10+y2-1)==1||*(fg+(mvy+x4)*10+y4-1)==1)
				pdil=1;
		if(i==17||i==13)
			if(*(fg+(mvy+x1)*10+y1-1)==1||*(fg+(mvy+x3)*10+y3-1)==1||*(fg+(mvy+x4)*10+y4-1)==1)
				pdil=1;
		if(i==11||i==15)
			if(*(fg+(mvy+x1)*10+y1-1)==1||*(fg+(mvy+x2)*10+y2-1)==1||*(fg+(mvy+x3)*10+y3-1)==1)
				pdil=1;
		if(i==6||i==8||i==10)
			if(*(fg+(mvy+x1)*10+y1-1)==1||*(fg+(mvy+x3)*10+y3-1)==1)
				pdil=1;
		if(i==0||i==12||i==18)
			if(*(fg+(mvy+x1)*10+y1-1)==1||*(fg+(mvy+x4)*10+y4-1)==1)
				pdil=1;
		if(i==2||i==14||i==16)
			if(*(fg+(mvy+x1)*10+y1-1)==1||*(fg+(mvy+x2)*10+y2-1)==1)
				pdil=1;
		if(i==4)
			if(*(fg+(mvy+x1)*10+y1-1)==1)
				pdil=1;
	}
	if(y1==0||y2==0||y3==0||y4==0)
		pdil=1;
	return pdil;
}

//Determine if the image can move right
int pdr(int *fg,int *zw,int i,int mvy, int mvx)
{
	int pdir=0;
	int x1=*zw,y1=*(zw+1)+mvx,x2=*(zw+2),y2=*(zw+3)+mvx,x3=*(zw+4),y3=*(zw+5)+mvx,x4=*(zw+6),y4=*(zw+7)+mvx;
	if(y1!=9&&y2!=9&&y3!=9&&y4!=9)
	{
		if(i==5)
			if(*(fg+(mvy+x1)*10+y1+1)==1||*(fg+(mvy+x2)*10+y2+1)==1||*(fg+(mvy+x3)*10+y3+1)==1||*(fg+(mvy+x4)*10+y4+1)==1)
				pdir=1;
		if(i==1||i==3||i==7||i==9)
			if(*(fg+(mvy+x1)*10+y1+1)==1||*(fg+(mvy+x3)*10+y3+1)==1||*(fg+(mvy+x4)*10+y4+1)==1)
				pdir=1;
		if(i==11||i==15)
			if(*(fg+(mvy+x1)*10+y1+1)==1||*(fg+(mvy+x2)*10+y2+1)==1||*(fg+(mvy+x4)*10+y4+1)==1)
				pdir=1;
		if(i==13||i==17)
			if(*(fg+(mvy+x2)*10+y2+1)==1||*(fg+(mvy+x3)*10+y3+1)==1||*(fg+(mvy+x4)*10+y4+1)==1)
				pdir=1;
		if(i==6||i==8||i==10)
			if(*(fg+(mvy+x2)*10+y2+1)==1||*(fg+(mvy+x4)*10+y4+1)==1)
				pdir=1;
		if(i==0||i==12||i==18)
			if(*(fg+(mvy+x3)*10+y3+1)==1||*(fg+(mvy+x4)*10+y4+1)==1)
				pdir=1;
		if(i==2||i==14||i==16)
			if(*(fg+(mvy+x1)*10+y1+1)==1||*(fg+(mvy+x4)*10+y4+1)==1)
				pdir=1;
		if(i==4)
			if(*(fg+(mvy+x4)*10+y4+1)==1)
				pdir=1;
	}
	if(y1==9||y2==9||y3==9||y4==9)
		pdir=1;
	return pdir;
}


//Pass array data to the next line 
void pan(int *p, int mvy, int *zw, int mvx)
{
	int x1=*zw,y1=*(zw+1)+mvx,x2=*(zw+2),y2=*(zw+3)+mvx,x3=*(zw+4),y3=*(zw+5)+mvx,x4=*(zw+6),y4=*(zw+7)+mvx;
	*(p+(mvy+1+x4)*10+y4)=*(p+(mvy+x4)*10+y4);
	*(p+(mvy+x4)*10+y4)=0;
	*(p+(mvy+1+x3)*10+y3)=*(p+(mvy+x3)*10+y3);
	*(p+(mvy+x3)*10+y3)=0;
	*(p+(mvy+1+x2)*10+y2)=*(p+(mvy+x2)*10+y2);
	*(p+(mvy+x2)*10+y2)=0;
	*(p+(mvy+1+x1)*10+y1)=*(p+(mvy+x1)*10+y1);
	*(p+(mvy+x1)*10+y1)=0;

}


 //adjust array data to left
void aal(int *p, int mvy, int *zw,int *mvx)
{
	int i=0,j;
	j=*mvx;
	int x1=*zw,y1=*(zw+1)+j,x2=*(zw+2),y2=*(zw+3)+j,x3=*(zw+4),y3=*(zw+5)+j,x4=*(zw+6),y4=*(zw+7)+j;
	*(p+(mvy+x1)*10+y1-1)=*(p+(mvy+x1)*10+y1);
	*(p+(mvy+x1)*10+y1)=0;
	*(p+(mvy+x2)*10+y2-1)=*(p+(mvy+x2)*10+y2);
	*(p+(mvy+x2)*10+y2)=0;
	*(p+(mvy+x3)*10+y3-1)=*(p+(mvy+x3)*10+y3);
	*(p+(mvy+x3)*10+y3)=0;
	*(p+(mvy+x4)*10+y4-1)=*(p+(mvy+x4)*10+y4);
	*(p+(mvy+x4)*10+y4)=0;
	*mvx=*mvx-1;
}


 //adjust array data to right
void aar(int *p, int mvy, int *zw, int *mvx)
{
	int i=0,j;
	j=*mvx;
	int x1=*zw,y1=*(zw+1)+j,x2=*(zw+2),y2=*(zw+3)+j,x3=*(zw+4),y3=*(zw+5)+j,x4=*(zw+6),y4=*(zw+7)+j;
	*(p+(mvy+x4)*10+y4+1)=*(p+(mvy+x4)*10+y4);
	*(p+(mvy+x4)*10+y4)=0;
	*(p+(mvy+x3)*10+y3+1)=*(p+(mvy+x3)*10+y3);
	*(p+(mvy+x3)*10+y3)=0;
	*(p+(mvy+x2)*10+y2+1)=*(p+(mvy+x2)*10+y2);
	*(p+(mvy+x2)*10+y2)=0;
	*(p+(mvy+x1)*10+y1+1)=*(p+(mvy+x1)*10+y1);
	*(p+(mvy+x1)*10+y1)=0;
	*mvx=*mvx+1;
}

//Rotating image and determine whether to rotate 
int ri(int i, int mvy, int mvx, int *fg, int *zw)
{	
	int j=NULL;
	j=i;
	//将原有图形清零；
	int x1=*zw+mvy,y1=*(zw+1)+mvx,x2=*(zw+2)+mvy,y2=*(zw+3)+mvx,x3=*(zw+4)+mvy,y3=*(zw+5)+mvx,x4=*(zw+6)+mvy,y4=*(zw+7)+mvx;
	*(fg+x1*10+y1)=0;
	*(fg+x2*10+y2)=0;
	*(fg+x3*10+y3)=0;
	*(fg+x4*10+y4)=0;
	//改变i的值
	if(i==0||i==1||i==2||i==11||i==12||i==13||i==15||i==16||i==17)
	    i=i+1;
	else if(i==3)
		i=0;
	else if(i==4)
		i=5;
	else if(i==5)
		i=4;
	else if(i==7)
		i=8;
	else if(i==8)
		i=7;
	else if(i==9)
		i=10;
	else if(i==10)
		i=9;
	else if(i==14)
		i=11;
	else if(i==18)
		i=15;
	//获取新的图形
    int fg1[21][10],*zfg1;
	zfg1=fg1[0];
	drawtu(i,zfg1,zw,mvy,mvx);                          //Determine the type of image 
	x1=*zw+mvy;y1=*(zw+1)+mvx;x2=*(zw+2)+mvy;y2=*(zw+3)+mvx;x3=*(zw+4)+mvy;y3=*(zw+5)+mvx;x4=*(zw+6)+mvy;y4=*(zw+7)+mvx;
	if((*(fg+x1*10+y1)==1)||(*(fg+x2*10+y2)==1)||(*(fg+x3*10+y3)==1)||(*(fg+x4*10+y4)==1))
		i=j;
	return i;
}

//Eliminate a whole line and calculate the score 
int  ec(int score, int *fg)
{
	int s=0,a,b,c=0,d=0,e=0;
	for(a=20;a>0;a--)
	{
		c=0;
		for(b=0;b<10;b++)
			if(*(fg+a*10+b)==0)
			{
				c=1;
				break;
			} 
		if(c==0)
		{
			for(d=a;d>0;d--)
				for(b=0;b<10;b++)
				{
					e=*(fg+(d-1)*10+b);
					*(fg+(d-1)*10+b)=0;
					*(fg+d*10+b)=e;
				}
			s++;
			a++;
		}
	}
	if(s==1)
		score=score-10;
	if(s==2||s==3||s==4)
		score=score+10*2^(s-2);
	return score;
}

//Determine if the game is over 
int dig(int *fg)
{
	int di=0,b;
	for(b=0;b<10;b++)
		if(*(fg+b)==1)
			di=1;
	return di;
}

//Output score 

int main(void)
{
	int getmouse=0,d,key1,key2,i,ii;
	int gdriver,gmode;
	gdriver=DETECT;                               //Set the graphics drive for automatic detection
	initgraph(&gdriver, &gmode, "c:\\tc");           //Initialize logical variables 
	setbkcolor(000000);
	cleardevice();
	while(1)
	{
		int fg[21][10]={0},zw[8]={0},*zzw,*zfg,score=0,nfg[4][4]={0},*znfg;
		znfg=nfg[0];
		zfg=fg[0];
		zzw=zw;
		srand(time(0));
		i=rand()%19;
		for(d=0;d<1000;d++)
		{
	lood:	int ce=16,xv=500,mvx=0,*zmvx,mvy=0,pdc=0,a=0;
			xv=xv-score*2;
			zmvx=&mvx;
			srand(time(0));
			ii=rand()%19;
			dtn(ii,znfg);		       //Determine the type of next image
			dnp(znfg);                   //drawd next pictures
			a=pdi(i);                      
			ce=a+ce;
			drawtu(i,zfg,zzw,mvy,mvx);                          //Determine the type of image 
			//Move the image down
			BeginBatchDraw();//开始批量绘图
			for(mvy=0;mvy<ce;mvy++)
			{	
				//Output score 
				char buffer[50];
				sprintf(buffer, "%s%d","score: ", score);
				outtextxy(250,100,buffer);
				outtextxy(250,120,"next picture:");
				rectangle(20,20,220,420);
				dnp(znfg);                  //drawd next pictures
			    loop:drawd(zfg);                //draw image
				//Move the elements from array fg[mvy] to fg[mvy+i] down one unit
				pdc=pdfg(zfg,mvy,i,zzw,mvx);              //Determine if the image can continue to move down 
				if(pdc==1)
					break;
				FlushBatchDraw();//执行未完成的绘制任务
				Sleep(xv);//挂起5毫秒
				cleardevice();
		    	EndBatchDraw();//结束批量绘制
                if(kbhit()!=0)
				{
					outtextxy(250,100,buffer);
					outtextxy(250,120,"next picture:");
					dnp(znfg);                   //drawd next pictures


					key1=getch();
					key2=getch();	
					int pdir=0,pdil=0;
					if(key1==0xe0)
					{
						if(key2==0x4b)
						{
							pdil=pdl(zfg,zzw,i,mvy,mvx);
							if(pdil==0)
								aal(zfg,mvy,zzw,zmvx);	//adjust array data to left
						}
						if(key2==0x4d)
						{
							pdir=pdr(zfg,zzw,i,mvy,mvx);
							if(pdir==0)
								aar(zfg,mvy,zzw,zmvx);	//adjust array data to right
						}
						if(key2==0x50)
							xv=xv/2;
						if(key2==0x48)
						{
							i=ri(i,mvy,mvx,zfg,zzw);          //Rotating image and determine whether to rotate  
							drawtu(i,zfg,zzw,mvy,mvx);                          //Determine the type of image 
							ce=16;
							a=pdi(i);                      
     						ce=a+ce;
						}
					}	
					rectangle(20,20,220,420);
					if((pdir==1)||(pdil==1))
						goto loob;
					 goto loop;
				}
			loob: pan(zfg,mvy,zzw,mvx);                //Pass array data to the next line 
				  if(dig(zfg)==1)                       //Determine if the game is over 
						goto lood;
			}
			score=ec(score,zfg);             //Eliminate a whole line and calculate the score 
			i=ii;
		}
	}
	closegraph() ;
	return 0 ;
}