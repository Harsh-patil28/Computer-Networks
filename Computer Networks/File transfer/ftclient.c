#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define CHUNK 1024  //read 1024 bytes at a time

void writefile(int sd)
{
char buf[CHUNK];
int n,i;
FILE *file;
file = fopen("temp.txt","w");

if(file == NULL)
{
printf("\n Error in opening a file");
}

while((read(sd,buf,sizeof(buf)))>0)
{
fputs(buf,file);
bzero(buf,sizeof(buf));
}
}

int main(int argc, char**argv)
{
int n;
int sd,port;
char buf[1024];
struct sockaddr_in server;
port = atoi(argv[1]);

//create stream socket
if((sd=socket(AF_INET,SOCK_STREAM,0)) == -1)
{
fprintf(stderr,"cant create a socket\n");
exit(1);
}

server.sin_family = AF_INET;
server.sin_port = port;
server.sin_addr.s_addr = inet_addr("127.0.01");

//connecting to the server
if(connect(sd,(struct sockaddr*)&server,sizeof(server)) == -1)
{
fprintf(stderr,"cant connect\n");
exit(1);
}

printf("\n Enter the command:");
scanf("%s",buf);   //get user text
write(sd,buf,sizeof(buf));   //send it out
writefile(sd);
close(sd);
return(0);
}

