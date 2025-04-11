#include<stdio.h>
#include<stdlib.h>
int ack()
{
	int k;
	k=rand();
	if(k%2==0)
		return 1;
	else
		return 0;
}

void main() 
{
	int n,i,test;
	printf("enter the no of packts you nee to stimulate: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		x:test=ack();
		printf("%d\n",test);
		if(test==1) {
			printf("Success ack received for packet-%d-sending next packet again \n",i);
		}
		else{
			printf("failed ack not received for packet-%d=sending packet again \n",i);
			goto x;
		}
	}
}
