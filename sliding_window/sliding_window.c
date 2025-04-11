#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void main()
{
	char sender[50],receiver[50];
	int i,winsize;
	printf("enter the window size ");
	scanf("%d",&winsize);
	printf("\nSender: window is expected to store message\n");
	printf("enter the data to be sent:\n");
	fflush(stdin);
	scanf("%s",sender);
	for(i=0;i<winsize;i++)
		receiver[i] =sender[i];
	receiver[i]= NULL;
	printf("\n window size of receiver is expanded\n");
	printf("\nAcknowledgement from receiver \n");
	for(i=0;i<winsize;i++)
		printf("\n ack: %d",i);
	printf("\n msg received is %s \n",receiver);
	printf("\n window size of receiver shrinked\n");
	}

