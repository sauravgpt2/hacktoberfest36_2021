#include<stdio.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<netdb.h>

//int reverse()

int child_process(int mysock)
	{
		int l,i;
		char DATA2[20];
		char ch;
		while(1)
		{
			recv(mysock,DATA2,sizeof(DATA2),0);
			//printf("\nsizeofdata: %d\n",DATA);
			printf("\nReceived: %s\n",DATA2);
			//memset(DATA,0,sizeof(DATA));
			l = strlen(DATA2);
			//printf("sizeof:%d",l);
			for(i=0;i<l/2;i++)
			{
				ch = DATA2[i];
				DATA2[i] = DATA2[l-1-i];
				DATA2[l-1-i] = ch;

			}
			printf("\nSend: %s",DATA2);
			//scanf("%s",DATA);
			send(mysock,DATA2,strlen(DATA2),0);

			memset(DATA2,0,sizeof(DATA2));

		}
	}

int main()
{
	int sock,child;
	struct sockaddr_in server;
	int mysock;
	//char DATA[60];
	int rval;
	sock = socket(AF_INET,SOCK_STREAM,0);
	if(sock<0)
	{
		perror("\n[-]Socket connection failed\n");
		exit(1);
	}
	else
	{
		perror("\n[+]Socket Established\n");
	}

	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons(5000);

	if(bind(sock, (struct sockaddr*)&server, sizeof(server)))
	{
		perror("\n[-]Bind Failed\n");
		exit(1);
	}
	else
	{
		printf("\n[+]Bind Established\n");
	}

	//listen
	listen(sock,10);
	do
	{
		mysock = accept(sock,(struct sockadd*)0,0);

		if((child=fork())==0)
		{
			close(sock);
			//size = sizeof(DATA);
			child_process(mysock);
		}

	}while(1);
	return 0;
}
