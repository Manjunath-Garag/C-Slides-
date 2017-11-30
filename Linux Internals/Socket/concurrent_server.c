#include<stdlib.h>
#include<stdio.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netinet/ip.h> 

#define SERVER_IP "127.0.0.1"
//#define SERVER_IP "192.168.225.50"
#define SERVER_PORT 5000
#define SERVER_LENGTH 10
#define SERVER_BUFF 20

int main()
{
	unsigned int pid;
	int sock_fd  , data_sock_fd  , buffer_len;
	struct sockaddr_in serv_addr;//man 7 ip
	char serv_buffer[SERVER_BUFF];

	printf(" server is waiting.....\n");
	//create a tcp socket..
	sock_fd = socket(AF_INET , SOCK_STREAM , 0);
	//BIND it to a particular ip address and port..

	serv_addr.sin_family = AF_INET;		//man 7 ip AF_INET is ipv4
	serv_addr.sin_addr.s_addr = inet_addr(SERVER_IP);	//man 7 ip
	serv_addr.sin_port = htons(SERVER_PORT);	//man 7 ip


	bind(sock_fd ,  (struct sockaddr*)&serv_addr , sizeof(serv_addr));	//2nd parameter is type-casted.
	//binding ip-addr and Port NO.
	//wait and listen for incoming connection..


	listen(sock_fd   ,  SERVER_LENGTH);//lenght is nothing but no of connections.
	//if there are any accept and create new data  socket...

	while(1)//concurrent - server
	{
		/* id there are any , accept amd create a new data socket
		   accept returns means 3-way handshake successfuly
		   the new socket(2nd socket) is data connection, For client we need to fork the child in order to handle seprate connections		 */
		//accept is a terminating statement will proceed only if it is true.
		data_sock_fd = accept(sock_fd , (struct sockaddr*)NULL , NULL);
		pid =fork();

		if(pid == 0 )
		{
			printf("New Child forked ... awaiting for IP from Child\n");
			/*Each client passes different type of data*/
			recv(data_sock_fd, (void *)serv_buffer, SERVER_BUFF, 0);	
			printf("Here is the client data :: %s\n", serv_buffer);
			close(data_sock_fd );
			/* Lets the child exit , its done it job now.*/
			exit(0);
		}//if
	}//while
	close(sock_fd);


	return 0;
}
//sudo ifconfig eth0 192.168.255.60
//we are fourcfully changing the ip in the above line. to 192.168.255.60
