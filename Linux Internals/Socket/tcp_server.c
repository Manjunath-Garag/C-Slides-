#include<stdio.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netinet/ip.h> 

#define SERVER_IP "127.0.0.1"
//#define SERVER_IP "10.0.2.15"
#define SERVER_PORT 5000
#define SERVER_LENGTH 10
#define SERVER_BUFF 20

int main()
{
	int sock_fd  , data_sock_fd  , buffer_len;

	struct sockaddr_in serv_addr;//man 7 ip
	char serv_buffer[SERVER_BUFF];

	printf(" server is waiting.....\n");
	//create a tcp socket..
	sock_fd = socket(AF_INET , SOCK_STREAM , 0);
	//BIND it to a particular ip address and port..

	serv_addr.sin_family = AF_INET;		//man 7 ip AF_INET is ipv4
	serv_addr.sin_addr.s_addr = inet_addr(SERVER_IP);	//man 7 ip
	serv_addr.sin_port = htons(SERVER_PORT);	//man 7 ip	5000

	bind(sock_fd ,  (struct sockaddr*)&serv_addr , sizeof(serv_addr));	//2nd parameter is type-casted.
	//binding ip-addr and Port NO.		to the Socket.
	//wait and listen for incoming connection..

	//sock_fd refers the type of socket tcp or udp.
	listen(sock_fd   ,  SERVER_LENGTH);//lenght is nothing but no of connections.
	//SERVER_LENGHT	will tell us how many a socket can have.

	//if there are any accept and create new data  socket...
	data_sock_fd = accept(sock_fd , (struct sockaddr*)NULL , NULL);
	//listening for the connection after listen.
	//accepts the connection for sock_fd and in-return a new file-descriptor(data_sock_fd)

	//data_sock_fd2 = accept(sock_fd , (struct sockaddr*)NULL , NULL);
	//we can have any no of connectoin for the clients.

	// try to get some actual data from client...
	recv(data_sock_fd, (void *)serv_buffer , SERVER_BUFF , 0);


	//print the data recieved from client..
	printf("%s\n" , serv_buffer);

	//close the sockets now..

	close(data_sock_fd );
	close(sock_fd);

	return 0;
}

