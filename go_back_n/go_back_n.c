#include<stdio.h>
#include<stdlib.h>
void main()
{
	int temp1,temp2,temp3,temp4,i,winsize=8, noframes,moreframes;
	int receives(int);
	int simulate(int);
	temp4=0, temp1=0, temp2=0, temp3=0;
	noframes= 5;
	winsize =8;
	moreframes =noframes;
	printf("no of frames=%d\n",noframes);
	while(moreframes >0)
	{
		temp1 =simulate(winsize);
		winsize -=temp1;
		temp4 += temp1;
		if(temp4 > noframes)
		{
			temp4 =noframes;
		}
		for(i=temp3+1; i<=temp4;i++)
			printf("\nsending frame %d",i);
		temp2= receives(temp1);
		temp3 +=temp2;
		if(temp3 > noframes)
			temp3 =noframes;
		printf("\n acknowledgement for frame upto %d",temp3);
		moreframes -=temp2;
		temp4=temp3;
		if(winsize <=0)
			winsize=8;
	}
}
int receives(int temp1)
{
	int i;
 	for(i=0;i<100;i++)
		rand();
	i=rand() % temp1;
	return i;
}
int simulate(int winsize)
{
	int temp1,i;
	for(i=0;i<50;i++)
		temp1=rand();
	if( temp1==0)
		temp1=simulate(winsize);
	i=temp1% winsize;
	if(i==0)
		return winsize;
	else
		return temp1 % winsize;
}


