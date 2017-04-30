#define NO_OF_CARS 20

typedef struct CAR
{
	//arrival_time,service_time,waiting_time,departure_time
	int arrtime,servtime,waittime,depttime;
}CAR;
CAR car[NO_OF_CARS];
typedef struct TOLLSERVER
{
	int iwt,ql,cdt;			//idle waiting time,queue_length,cummulative_departure_time
}tollserver;
tollserver toll[3];
void init()
{
	int i,tat,at=0,st;
	for(i=0;i<3;i++)
	{
		toll[i].iwt=toll[i].ql=toll[i].cdt=0;
	}
	randomize();
	for(i=0;i<NO_OF_CARS;i++)
	{
		tat=random(5)+1;
		st=random(15)+1;
		at=at+tat;
		car[i].arrtime=at;
		car[i].servtime=st;
	}
}

int decision(CAR obj)
{
	int M,MNDT;
	if(toll[0].cdt<toll[1].cdt)
	{
		if(toll[0].cdt<toll[2].cdt)
			M=0;
		else
			M=2;
	}
	else
	{
		if(toll[1].cdt<toll[2].cdt)
			M=1;
		else
			M=2;
	}
 //	MNDT=toll[M].cdt;
	if(toll[M].cdt<obj.arrtime)
	{
		toll[M].iwt = obj.arrtime-toll[M].cdt;
		toll[M].ql=1;
		obj.waittime=0;
	}
	else if(toll[M].cdt>obj.arrtime)
	     {
		obj.waittime = toll[M].cdt-obj.arrtime;
		toll[M].ql+=1;
		toll[M].iwt=0;
	     }
	     else
	     {
		toll[M].iwt=0;
		obj.waittime=0;
		toll[M].ql=1;
	     }
	     toll[M].cdt=toll[M].cdt+obj.servtime+toll[M].iwt;
	return M;
}

void updatequeuelen(CAR i20)
{
	if(i20.arrtime>toll[0].cdt)
	{
		toll[0].ql=0;
		toll[0].iwt=0;
	}
	if(i20.arrtime>toll[1].cdt)
	{
		toll[1].ql=0;
		toll[1].iwt=0;
	}
	if(i20.arrtime>toll[2].cdt)
	{
		toll[2].ql=0;
		toll[2].iwt=0;
	}
}
