
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
	int sock_fd  , data_sock_fd  , buffer_len, cli_len;
	struct sockaddr_in serv_addr;//man 7 ip
	struct sockaddr_in  cli_addr;
	char serv_buffer[SERVER_BUFF];

	printf(" server is waiting.....\n");
	//create a tcp socket..
	sock_fd = socket(AF_INET , SOCK_DGRAM , 0);
	//BIND it to a particular ip address and port..

	serv_addr.sin_family = AF_INET;		//man 7 ip AF_INET is ipv4
	serv_addr.sin_addr.s_addr = inet_addr(SERVER_IP);	//man 7 ip
	serv_addr.sin_port = htons(SERVER_PORT);	//man 7 ip

	bind(sock_fd ,  (struct sockaddr*)&serv_addr , sizeof(serv_addr));	//2nd parameter is type-casted.
	//binding ip-addr and Port NO.
	//wait and listen for incoming connection..

	/*Try to get some actual data from client*/
	cli_len = sizeof(struct sockaddr_in);//difference is here.

	//recvfrom == recv + accept.	listen is not required So can accept any no of connections.
//just the client address (i.e IP address is enough.) Since it will accept all the Inputs and no need of Port Number.

	recvfrom(sock_fd, (void *)serv_buffer , SERVER_BUFF , 0, (struct sockaddr *)&cli_addr, &cli_len);//Diff revcfrom 
	//recvfrom 1st Parameter in UDP is sock_fd instead of data_sock_fd like TCP we just send the server address of "fd".
	//in tcp we send each data like "data_sock_fd".

	/* recvfrom(int sockfd, void *buf, size_t len, int flags,	//the next line we add the info of the client.
	   struct sockaddr *src_addr, socklen_t *addrlen); */

	printf("%s\n" , serv_buffer);
	//	printf("HERE is the client data : %s\n" , serv_buffer);
	//close the sockets now..

//	close(data_sock_fd );
	close(sock_fd);

	return 0;
}

