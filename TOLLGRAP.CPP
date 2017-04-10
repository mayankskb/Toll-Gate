#include"auxil.cpp"

int j,ql1,ql2,ql3;
int l,b,t,h;
//checking condition for queue length
void check_queue_length(int ch)
{
	if(ch==0)
	{
	    ql1=toll[0].ql-1;
	    ql2=toll[1].ql;
	    ql3=toll[2].ql;
	}
	if(ch==1)
	{
		ql1=toll[0].ql;
		ql2=toll[1].ql-1;
		ql3=toll[2].ql;
	}
	if(ch==2)
	{
		ql1=toll[0].ql;
		ql2=toll[1].ql;
		ql3=toll[2].ql-1;
	}
	else
	{
		ql1=toll[0].ql;
		ql2=toll[1].ql;
		ql3=toll[2].ql;
	}
	int v;
	if(ql1>0)
	{
		for(v=0;v<ql1;v++)
		{
			l=68+v*20;
			t=98+v*20;
			b=88+v*20;
			h=118+v*20;
			rectangle(l,t,b,h);
		}
	}
	if(ql2>0)
	{
		for(v=0;v<ql2;v++)
		{
			l=210;
			t=98+v*20;
			b=230;
			h=118+v*20;
			rectangle(l,t,b,h);
		}
	}
	if(ql3>0)
	{
		for(v=0;v<ql3;v++)
		{
			l=352-v*20;
			t=98+v*20;
			b=372-v*20;
			h=118+v*20;
			rectangle(l,t,b,h);
		}
	}
}

//function making layout of a toll plaza
void makegraph()
{
	line(60,65,60,115);
	rectangle(100,65,190,95);	//booth1
	rectangle(250,65,330,95);	//booth2
	rectangle(380,65,460,95);     line(380,65,380,115);   //booth3
	line(60,115,180,250);   	//line 1
	line(100,95,190,185);           //line 2
	line(190,95,190,185);   	//line 3
	line(250,95,250,185);   	//line 4
	line(330,95,250,185);    	//line 5
	line(380,115,260,250);   	//line 6
	line(180,250,180,350);
	line(260,250,260,350);
	gotoxy(16,6);		printf("booth1");
	gotoxy(34,6);		printf("booth2");
	gotoxy(50,6);           printf("booth3");
	gotoxy(16,2);           printf("cdt :%d",toll[0].cdt);
	gotoxy(34,2);           printf("cdt :%d",toll[1].cdt);
	gotoxy(50,2);		printf("cdt :%d",toll[2].cdt);
	gotoxy(16,3);           printf("waiting :%d",toll[0].iwt);
	gotoxy(34,3);           printf("waiting :%d",toll[1].iwt);
	gotoxy(50,3);		printf("waiting :%d",toll[2].iwt);
	gotoxy(16,4);           printf("q-len :%d",toll[0].ql);
	gotoxy(34,4);           printf("q-len :%d",toll[1].ql);
	gotoxy(50,4);		printf("q-len :%d",toll[2].ql);
	gotoxy(50,23);	printf("Arrival Time :%d",car[j].arrtime);
	gotoxy(50,24);	printf("Service Time :%d",car[j].servtime);
}

//function for moving a car for booth1
void booth1(int left,int top,int right,int bottom)
{
	 for(int i=0;i<142-20*toll[0].ql+20;i++)
	 {
		cleardevice();
		makegraph();
		check_queue_length(0);
		gotoxy(50,20);		printf("Join Booth: %d",1);
		top=top-1;
		bottom=bottom-1;
		left=left-1;
		right=right-1;
		rectangle(left,top,right,bottom);
		delay(20);
	 }
}

//function for moving a car for booth2
void booth2(int left,int top,int right,int bottom)
{
	for(int i=0;i<150-20*toll[1].ql+20;i++)
	{
		cleardevice();
		makegraph();
		check_queue_length(1);
		gotoxy(50,20);	printf("Join Booth: %d",2);
		top=top-1;
		bottom=bottom-1;
		rectangle(left,top,right,bottom);
		delay(20);
	}
}

//function for moving a car for booth3
void booth3(int left,int top,int right,int bottom)
{
	for(int i=0;i<142-20*toll[2].ql+20;i++)
	{
		cleardevice();
		makegraph();
		check_queue_length(2);
		gotoxy(50,20);	printf("Join Booth: %d",3);
		top=top-1;
		bottom=bottom-1;
		left=left+1;
		right=right+1;
		rectangle(left,top,right,bottom);
		delay(20);
	}
}

//toll graphics controller function
void maketoll()
{
	int k,gdriver = EGA, gmode = EGAHI, errorcode,bkcol;

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
	init();
	randomize();
	for(j=1;j<20;j++)
	{
		int left=210,top=340,right=230,bottom=360;
		for(int i=0;i<100;i++)
		{
			cleardevice();
			makegraph();
			check_queue_length(3);
			top=top-1;
			bottom=bottom-1;
			rectangle(left,top,right,bottom);
			delay(20);
		}
		k = decision(car[j]);
		gotoxy(50,20);		printf("Join Booth: %d",k+1);
		updatequeuelen(car[j]);

		switch(k)
		{
			case 0: booth1(left,top,right,bottom);
				break;
			case 1: booth2(left,top,right,bottom);
				break;
			case 2: booth3(left,top,right,bottom);
				break;
		}
	}
	getch();
	cleardevice();
	closegraph();
}
