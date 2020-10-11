#include<stdio.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<netdb.h>
int main(int argc,char* argv[])
{
	int sock,rval;
	char DATA[50];
	struct sockaddr_in server;
	struct hostent *hp;
	sock = socket(AF_INET,SOCK_STREAM,0);
	if(sock<0)
	{
		perror("\n[-]Socket connection failed\n");
		exit(1);//Unseccessfull exit
	}
	server.sin_family = AF_INET;
	hp = gethostbyname(argv[1]);
	memcpy(&server.sin_addr,hp->h_addr,hp->h_length);
	server.sin_port = htons(5000);
	if(connect(sock,(struct sockaddr*)&server,sizeof(server))<0)

	{
		perror("\n[-]connection failed\n");
		close(sock);
		exit(1);
	}
	while(1)
	{
		memset(DATA,0,sizeof(DATA));

		printf("\nSend Message:\n");
		scanf("%s",DATA);
		if(send(sock,DATA,sizeof(DATA),0)<0)
		{
			perror("\n[-]Send Failed\n");
			close(sock);
			exit(1);
		}
		//printf("\nSend Message: %s\n",DATA);

		memset(DATA,0,sizeof(DATA));

		if(rval=recv(sock,DATA,sizeof(DATA),0)<0)
		{
			perror("\n[-]Error\n");
		}
		printf("\nReceived message: %s\n",DATA);
		memset(DATA,0,sizeof(DATA));

	}


}
