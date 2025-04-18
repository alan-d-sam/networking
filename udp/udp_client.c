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
	struct sockaddr_in addr;
	char buffer[1024];
	socklen_t addr_size;
	int n;
	sockid = socket(AF_INET, SOCK_DGRAM, 0);

	// printf("running....");

	memset(&addr, '\0', sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);
	addr.sin_addr.s_addr = inet_addr(ip);

	bzero(buffer, 1024);
	strcpy(buffer, "Hello world!!");
	sendto(sockid, buffer, 1040, 0, (struct sockaddr *)&addr, sizeof(addr));
	printf("[+] Data send: %s\n", buffer);
	bzero(buffer, 1024);
	addr_size = sizeof(addr);
	recvfrom(sockid, buffer, 1024, 0, (struct sockaddr *)&addr, &addr_size);
	printf("[+] Data recv: %s \n", buffer);
	return 0;
}
