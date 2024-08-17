//has functions for address manipulation:
#include <arpa/inet.h>
//Best Error lib ever:
#include <errno.h>
//Duh:
#include <stdio.h>
//Lets me use sockets:
#include <sys/socket.h>


#define PORT 8080

int main() {
    //Makes a socket:
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    //supposedly, the 0 makes it TCP

    if (sockfd == -1){
        //fail state
        perror("webserver socket fail");
        return 1;
    }
    printf("socket created successfully\n");

    // Create the address to bind the socket to
    struct sockaddr_in host_addr;
    int host_addrlen = sizeof(host_addr);

    host_addr.sin_family = AF_INET;

    host_addr.sin_port = htons(PORT);
    
    host_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    //Bind the socket to the address
    if (bind(sockfd, (struct sockaddr *)&host_addr, host_addrlen) != 0) {
        //fail state
        perror("webserver bind fail");
        return 1;
    }
    printf("socket successfully bound to address\n");

    return 0;
}