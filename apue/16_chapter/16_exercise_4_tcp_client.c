/*
 * author:	luo feng
 * date:	2014/5/9
 * source:	APUE
 * title:	exercise 4(TCP client) of chapter 16
 * language:	C
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>

int main(int argc, char const *argv[])
{
	int cnt = 0;
	struct sockaddr_in addr;
	int sockfd;

	if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		perror("socket");
		exit(EXIT_FAILURE);
	}

	addr.sin_family = AF_INET;
	addr.sin_port = htons(9003);
	inet_pton(AF_INET, "127.0.0.1", &(addr.sin_addr));
	if(connect(sockfd, (struct sockaddr*)&addr, sizeof(struct sockaddr)) < 0) {
		perror("connect");
		exit(EXIT_FAILURE);
	}

	if(recv(sockfd, &cnt, sizeof(cnt), 0) < 0) {
		perror("recv");
		exit(EXIT_FAILURE);
	}

	printf("%d\n", cnt);

	if(close(sockfd) < 0) {
		perror("close");
		exit(EXIT_FAILURE);
	}

	exit(EXIT_SUCCESS);
}