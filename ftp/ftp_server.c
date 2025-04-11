#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <arpa/inet.h>
int main(int argc, char *argv[])
{
    int socket_desc, new_socket, c;
    char message[2000], filename[2000];
    FILE *fp;
    struct sockaddr_in server, client;
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1)
    {
        printf("Could not create socket");
    }
    printf("Socket created\n");
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(8888);
    if (bind(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0)
    {
        puts("Bind Failed");
        return 1;
    }
    puts("Bind Done");
    listen(socket_desc, 3);
    puts("Waiting for incoming connections.......");
    c = sizeof(struct sockaddr_in);
    new_socket = accept(socket_desc, (struct sockaddr *)&client, (socklen_t *)&c);
    if (new_socket < 0)
    {
        perror("Accept failed");
    }
    puts("Connection accepted");
    while (1)
    {
        recv(new_socket, filename, 2000, 0);
        fp = fopen("Hello.txt", "r");
        if (fp == NULL)
        {
            strcpy(message, "File not found \n\n");
            send(new_socket, message, 2000, 0);
            puts(message);
        }
        else
        {
            while (fgets(message, 2000, fp))
            {
                send(new_socket, message, 2000, 0);
                puts(message);
            }
            fclose(fp);
        }
        strcpy(message, "EOF");
        send(new_socket, message, 2000, 0);
    }
    return 0;
}
