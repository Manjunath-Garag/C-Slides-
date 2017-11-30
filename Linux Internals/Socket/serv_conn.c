
#include<stdio.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netinet/ip.h> 

#define SERVER_IP "127.0.0.1"
//#define SERVER_IP "10.0.2.15"
#define SERVER_PORT 5000
#define CLIENT_PORT 6000
#define CLIENT_IP "127.0.0.1"
#define SERVER_LENGTH 10
#define SERVER_BUFF 20

int main()
{
	int sock_fd  , data_sock_fd  , buffer_len, sock_fd1;

	struct sockaddr_in serv_addr;//man 7 ip

	struct sockaddr_in client_addr;

	char serv_buffer[SERVER_BUFF];
	char client_buffer[SERVER_BUFF];

	printf(" server is waiting.....\n");
	//create a tcp socket..
	sock_fd = socket(AF_INET , SOCK_STREAM , 0);
	//BIND it to a particular ip address and port..

	serv_addr.sin_family = AF_INET;		//man 7 ip AF_INET is ipv4
	serv_addr.sin_addr.s_addr = inet_addr(SERVER_IP);	//man 7 ip
	serv_addr.sin_port = htons(SERVER_PORT);	//man 7 ip	5000

	sock_fd1 = socket(AF_INET , SOCK_STREAM , 0);
	client_addr.sin_family = AF_INET;		//man 7 ip AF_INET is ipv4
	client_addr.sin_addr.s_addr = inet_addr(CLIENT_IP);	//man 7 ip
	client_addr.sin_port = htons(CLIENT_PORT);

	bind(sock_fd ,  (struct sockaddr*)&serv_addr , sizeof(serv_addr));	//2nd parameter is type-casted.
	//binding ip-addr and Port NO.
	//wait and listen for incoming connection..

	//sock_fd refers the type of socket tcp or udp.
	listen(sock_fd   ,  SERVER_LENGTH);//lenght is nothing but no of connections.

	while(1)
	{	
	data_sock_fd = accept(sock_fd , (struct sockaddr*)NULL , NULL);
		recv(data_sock_fd, (void *)serv_buffer , SERVER_BUFF , 0);


		printf("%s\n" , serv_buffer);
		printf("Enetr the msg you want to send\n");
		scanf("%s", client_buffer);

		int c_size = send(sock_fd,(void *)client_buffer, sizeof(client_buffer), 0 );
		printf("%d",c_size);
		if(c_size)
			printf("Msg was sent\n");
		else
			printf("Msg not sent\n");
	}//while
	close(data_sock_fd );
	close(sock_fd);

	return 0;
}

