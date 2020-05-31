#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>
#include<iostream>
#include<fstream>
#include<thread>
#include<vector>
#include "Client.hpp"



int main()
{
	
	int socket_fd = socket(AF_INET,SOCK_STREAM,0); 
    if(socket_fd == -1)
    {
        cout<<" Erreur  !"<<endl;
        exit(-1);
    }
    
    struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(8888);
	addr.sin_addr.s_addr = INADDR_ANY;
	
	int res = bind(socket_fd,(struct sockaddr*)&addr,sizeof(addr));
    if(res == -1)
    {
        cout<<"Perdu de construire bind"<<endl;
        exit(-1);        
    }
    cout<<"bind avec succés !"<<endl;
    
while(1)
{

    listen(socket_fd,30);
    
    struct sockaddr_in clnt;
    socklen_t len = sizeof(clnt);
    int fd = accept(socket_fd,(struct sockaddr*)&clnt,&len);
    if(fd == -1)
    {
        printf("accept error\n");
        exit(-1);
    }
	
	char p[500];
	char ph[500];
	
	recv(fd,p,sizeof(p),0);
    cout << p << endl;
    
    recv(fd,ph,sizeof(ph),0);
    cout << ph << endl;
    close(fd);
   }
	
	
    
}
