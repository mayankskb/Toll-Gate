#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include<dos.h>

//Included cpp files
#include"basic.cpp"
#include"about.cpp"
#include"tollgraph.cpp"

int main(void)
{
	int gdriver = EGA, gmode = EGAHI, errorcode,bkcol;

	char *fname = "TOLL GATE",*dev="DEVELOPED BY : MAYANK MISHRA";

	/* initialize graphics and local variables */
	initgraph(&gdriver, &gmode, "C:\\TC\\bgi");
	/* read result of initialization */
	errorcode = graphresult();
	if (errorcode != grOk)  /* an error occurred */
	{
		printf("Graphics error: %s\n", grapherrormsg(errorcode));
		printf("Press any key to halt:");
		getch();
		exit(1); /* terminate with an error code */
	}

	/* for centering text messages */
	settextjustify(CENTER_TEXT, CENTER_TEXT);
	midx = getmaxx() / 2;
	midy = getmaxy() / 2;

	cleardevice();

	/* select a new background color */
	setbkcolor(4);
	settextjustify(CENTER_TEXT, CENTER_TEXT);
	/* select the text style */
	settextstyle(style, HORIZ_DIR, size);
	/* output a message */
	outtextxy(midx, 160, fname);
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t a toll gate simulation");
	printf("\n\n\n\n\n\t\t\t\t   ");
	for(int i=0;i<10;i++)
	{
		printf(".");
		delay(200);
	}
	cleardevice();
	about();
	delay(4000);
	cleardevice();
	maketoll();
	rectangle(150,340,210,350);
	getch();
	/* clean up */
	closegraph();
	return 0;
}

