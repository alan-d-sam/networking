#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char **argv)
{
	char *ip = "127.0.0.1";
	int port = 4455;
	int sockid;
	struct sockaddr_in server_addr, client_addr;
	char buffer[1024];
	socklen_t addr_size;
	int n;
	sockid = socket(AF_INET, SOCK_DGRAM, 0);
	if (sockid < 0)
	{
		perror("[-]Socket error");
		exit(1);
	}

	memset(&server_addr, '\0', sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(port);
	server_addr.sin_addr.s_addr = inet_addr(ip);
	n = bind(sockid, (struct sockaddr *)&server_addr, sizeof(server_addr));
	if (n < 0)
	{
		perror("[-] bind error");
		exit(1);
	}
	bzero(buffer, 1024);
	addr_size = sizeof(client_addr);
	recvfrom(sockid, buffer, 1024, 0, (struct sockaddr *)&client_addr, &addr_size);
	printf("[+] Data recv: %s\n", buffer);
	bzero(buffer, 1024);
	strcpy(buffer, "welcome to the udp server");
	sendto(sockid, buffer, 1024, 0, (struct sockaddr *)&client_addr, sizeof(client_addr));
	printf("[+] Data send: %s \n", buffer);
	return 0;
	// pclose(sockid);
}
