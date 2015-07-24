/* 
 * File:   main.c
 * Author: James
 * Socket server
 * Created on July 24, 2015, 10:49 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>          
#include <sys/socket.h>
#include <netinet/in.h>


/*
 * 
 */
int main(int argc, char** argv) {
    int listener = socket(AF_INET, SOCK_STREAM, 0);
    
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(2015);
    
    bind(listener, (struct sockaddr *)&server, sizeof(server));
    
    listen(listener, 5);
    struct sockaddr_in client_info;
    socklen_t client_length = sizeof(client_info);
    int client = accept(listener, (struct sockaddr *)&client_info, 
            &client_length);
    
    write(client, "Hello World\n", 12);
    printf("Exit\n");
    
    close(client);
    close(listener);
    return (EXIT_SUCCESS);
}

