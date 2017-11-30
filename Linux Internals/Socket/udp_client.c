
#include<stdio.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netinet/ip.h> 

#define SERVER_IP_ADDRESS "127.0.0.1"
#define SERVER_PORT 5000
#define SERVER_LENGTH 10
#define CLIENT_BUFF_SIZE 20

int main()
{
	int sock_fd  , c_size;
	struct sockaddr_in serv_addr;
	char client_buffer[CLIENT_BUFF_SIZE];
	//create a client socket..
	if((sock_fd = socket(AF_INET , SOCK_DGRAM , 0)) < 0)
	{
		printf("ERROR : couldnot create a socket\n");
		return 1;
	}
	//binding with client  socket is optional here..

	//populate it with server's address details..


	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(SERVER_PORT);
	serv_addr.sin_addr.s_addr = inet_addr(SERVER_IP_ADDRESS);//converts the string to IP(Bytes form)
	//get the message from client...
	printf("Enter the message u want to send to server:\n");
	gets(client_buffer);
/*
	if(connect(sock_fd , (struct sockaddr *)&serv_addr ,sizeof(serv_addr)) != 0)//this request is sent to accept() on server side.
		printf("Error connecting to server\n");
	else
		printf("Connection Succesfull\n");
				//FOR UDP CONNECT SYSTEM CALL IS NOT REQUIRED.
*/
	//send the message to server..

	//SENDTO  ==  CONNECT + SEND 
	c_size = sendto(sock_fd , (void *)client_buffer ,CLIENT_BUFF_SIZE , 0,(struct sockaddr *)&serv_addr, sizeof(serv_addr));
	if(c_size)
		printf("Message sent to server successfully...\n");
	else
		printf("Error: Message send\n");

	close(sock_fd);
	return 0;
}

