#include<stdio.h>
#include<graphics.h>
#include<stdlib.h>

int main()
{
	int gd,gm;
	int remove[6000],topr=0,add[6000],topa=0;
	int i,j,total,k;
	char ask=0;
	gd=DETECT;
	printf("Welcome to Conway's GAME of LIFE : press any key to continue(starts with an initial state and shows evolution of the life form) ");
	printf("\n1.Any live cell with fewer than two live neighbours dies, as if by underpopulation");
	printf("\n2.Any live cell with two or three live neighbours lives on to the next generation.");
	printf("\n3.Any live cell with more than three live neighbours dies, as if by overpopulation.");
	printf("\n4.Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.\n");

	printf("\n1:press key to get to next state\n2:press and hold to go on \n3:press 'e' to exit");
	ask=getche();
	initgraph(&gd,&gm,"C:/TURBOC3/BGI");

	//make_box(245,325,WHITE);
	//make_box(235,325,WHITE);
	make_box(255,325,WHITE);
	make_box(245,315,WHITE);
	make_box(245,335,WHITE);
	make_box(235,345,WHITE);
	make_box(255,345,WHITE);
	make_box(245,345,WHITE);
	make_box(255,355,WHITE);
	make_box(235,355,WHITE);

	make_box(275,375,WHITE);
	make_box(275,385,WHITE);
	make_box(275,395,WHITE);
	make_box(275,335,WHITE);
	make_box(275,355,WHITE);
	make_box(275,365,WHITE);
	make_box(255,345,WHITE);
	make_box(265,345,WHITE);
	make_box(275,345,WHITE);
	make_box(285,345,WHITE);
	make_box(295,345,WHITE);
	make_box(295,335,WHITE);
	make_box(295,325,WHITE);
	make_box(295,315,WHITE);
	make_box(295,305,WHITE);
	make_box(295,355,WHITE);

	make_box(325,245,WHITE);
	make_box(315,245,WHITE);
	make_box(335,245,WHITE);
	make_box(325,255,WHITE);
	make_box(325,235,WHITE);

	ask=getche();
	while(ask!='e')
	{
	for(i=5;i<=645;i=i+10)
	{
		for(j=5;j<=465;j=j+10)
		{
			total = getnum(i,j);

			if(check_box(i,j)==1)//is white
			{

				if(total<2||total>3)
				{
					remove[topr++]=i;
					remove[topr++]=j;
				}

			}
			else
			{
				if(total==3)
				{
					add[topa++]=i;
					add[topa++]=j;
				}

			}
			total = 0;
		}
	}

	total = 0;
	while(topr>0)
	{
	   j=remove[--topr];
	   i=remove[--topr];
	   make_box(i,j,BLACK);
	}
	topr=0;
	while(topa>0)
	{
		j=add[--topa];
		i=add[--topa];
		make_box(i,j,WHITE);
	}
	topa=0;
	ask=getche();
	}//end of while loop

	closegraph();
}

make_box(int x,int y,int color)
{
	int i,j;
	for(i=y-5;i<y+5;i++)
	{
		for(j=x-5;j<=x+5;j++)
		{
			putpixel(j,i,color);
		}
	}
}

int check_box(int x,int y)
{
	if(getpixel(x,y)==WHITE)
	return(1);
	return(0);
}

int getnum(int x,int y)
{
    int total=0;
    int i,j;
    for(i=x-10;i<=x+10;i=i+10)
    {
	for(j=y-10;j<=y+10;j=j+10)
	{       if(getpixel(i,j)==WHITE)
			total = total + 1;
	}
    }
    if(getpixel(x,y)==WHITE)
	total = total-1;
    return(total);
}
