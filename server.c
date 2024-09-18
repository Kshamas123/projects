#include<stdio.h>
#include<winsock2.h>
#include<stdlib.h>

//note for windows socket programming winsock header file is necessary.there are winsock.h and winsock2.h 
// the more modern header for socket programming is winsock2.h. winsock.h is an older header and generally, you should use winsock2.h for newer applications.
#define PORT 8080

int main()
{
    SOCKET server_soc,client_soc;  //here server_soc and client_soc are socket descriptors.
    WSADATA wsa; 
    struct sockaddr_in server_addr,client_addr;
    int addr_len=sizeof(client_addr);
    // printf("%d",addr_len);  here printing the size of client_addr
    
    if(WSAStartup(MAKEWORD(2,2),&wsa)!=0)
    {
        printf("winsock library initialization failed");
        return 1;
    }
    printf("winsock library initialized successfully\n");

}