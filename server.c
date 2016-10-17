#include<stdio.h>
#include<string.h>    //strlen
#include<sys/socket.h>
#include<arpa/inet.h> //inet_addr
#include<unistd.h>    //write
#include <time.h>
int main(int argc , char *argv[])
{
 
time_t mytime;
mytime=time(NULL);

int socket_desc , new_socket , c;
struct sockaddr_in server , client;
char message[100];
//Create socket
socket_desc = socket(AF_INET , SOCK_STREAM , 0);
if (socket_desc == -1)
{
printf("Could not create socket");
}
//Prepare the sockaddr_in structure
server.sin_family = AF_INET;
server.sin_addr.s_addr = INADDR_ANY;
server.sin_port = htons( 8787 );
//Bind
if( bind(socket_desc,(struct sockaddr *)&server , sizeof(server)) < 0)
{
puts("bind failed");
return 1;
}
puts("bind done");
//Listen
listen(socket_desc , 3);
//Accept and incoming connection
puts("Waiting for incoming connections...");
c = sizeof(struct sockaddr_in);
while( (new_socket = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c)) )
{
puts("Connection accepted");
//Reply to the client
while(1)
{
	bzero(message,100);
	read(new_socket,message,100);
	printf("Echoing back - %s",message);
	write(new_socket , message, strlen(message)+1);
}
//message = ctime(&mytime);
//write(new_socket , message , strlen(message));
}
if (new_socket<0)
{
perror("accept failed");
return 1;
}
return 0;
}
