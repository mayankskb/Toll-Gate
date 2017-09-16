/*..........funtion to display information about developer..........*/


void about()
{  	char *dev ="Developed By",*name="Mayank Mishra";
	setbkcolor(5);
	settextjustify(CENTER_TEXT, CENTER_TEXT);
	/* select the text style */
	settextstyle(style, HORIZ_DIR, 4);
	outtextxy(midx, 100, dev);
	settextstyle(style, HORIZ_DIR, 2);
	outtextxy(midx, 160, name);

}
