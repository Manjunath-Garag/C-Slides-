#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<netdb.h>

#define PORT 5555
#define MAXMSG 512

int read_from_client (int filedes)
{
	char buffer[MAXMSG];
	int nbytes;
	nbytes = read(filedes, buffer, MAXMSG);
	if(nbytes < 0)
	{
		perror("read");
		exit(EXIT_FAILURE);
	}
	else if( nbytes == 0)
		return -1;
	else
		printf("Server: got message : %s\n",buffer);
}

int make_socket(short port)
{
	int sock;
	struct sockaddr_in name;
	//create a socket
	sock = socket(AF_INET, SOCK_STREAM, 0);
	if(sock < 0)
		perror("socket");

	name.sin_family = AF_INET;
	name.sin_port = htons(port);
	name.sin_addr.s_addr=inet_addr("127.0.0.1");
	if( bind(sock, (struct sockaddr *)&name, sizeof(name)) < 0) 
	{
		perror("bind");
		exit(EXIT_FAILURE);
	}
	return sock;
}

int main()
{
	int sock;
	fd_set active_fd_set, read_fd_set;
	int i;
	struct sockaddr_in clientname;
	size_t size;

	sock = make_socket(PORT);
	if(listen(sock, 1) <0)
	{
		perror("listen");
		exit(EXIT_FAILURE);
	}

	FD_ZERO (&active_fd_set);//buffer is cleared.
	FD_SET (sock, &active_fd_set);//sock is added to buffer.
	while(1)
	{
		read_fd_set = active_fd_set;
		//
		if(select(FD_SETSIZE, &read_fd_set, NULL, NULL, NULL) < 0)
		{
			perror("select");
			exit(EXIT_FAILURE);
		}
		/* */
		for(i = 0; i < FD_SETSIZE; ++i)
		{
			if(FD_ISSET (i, &read_fd_set))	//checks if i is a Part of the Socket.
			{
				if(i == sock)
				{
					int new;
					size = sizeof(clientname);
					new = accept(sock, (struct sockaddr *)&clientname, &size );
					if(new < 0)
					{
						perror("accept");
						exit(EXIT_FAILURE);
					}
					printf("Server : connect from host %s , port %d\n",inet_ntoa(clientname.sin_addr), ntohs(clientname.sin_port));
					FD_SET (new , &active_fd_set);
				}
				else
				{
					if( read_from_client (i) < 0)
					{
						close(i);
						FD_CLR (i, &active_fd_set);
					}
				}
			}
		}
	}
}
