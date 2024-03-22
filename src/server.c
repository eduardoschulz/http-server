#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/un.h>
#include <sys/socket.h>
#include <errno.h>


#define PORT 30000
int main(int argc, char *argv[]){
	
	int socket_fd, client_fd;

	struct sockaddr_un my_addr, peer_addr;
	socklen_t peer_addr_size;

	memset(&my_addr, 0, sizeof(struct sockaddr_un));

	socket_fd = socket(AF_INET, SOCK_STREAM, 0);

	if (socket_fd == -1) {
		perror("socket fail");
		return -1;
	}

	else
		printf("Successfully created socket\n");

	int resp = bind (socket_fd, &my_addr, sizeof(my_addr));
	printf("Socket binded to port sucessfully \n", resp);	
	
	return 0;

}
