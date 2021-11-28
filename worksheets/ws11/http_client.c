#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>

#include "http.h"

int main(int argc, char *argv[])
{

	int sockfd, num_bytes;
	struct sockaddr_in serv_addr;
	struct hostent *url;
	char buffer[BUFFER_SIZE] = {0};
	char *domain = "localhost";

	/* Create a socket */
	sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (sockfd < 0)
	{
		fprintf(stderr, "ERROR: Failed to open socket\n");
		return 1;
	}

	/* get the url address */
	url = gethostbyname(domain); /* does not support IP6 */
	if (url == NULL)
	{
		fprintf(stderr, "ERROR: Host not found\n");
		return 2;
	}

	/* Initialize socket structure (sockarrd_in) */
	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	memcpy(&serv_addr.sin_addr, url->h_addr, url->h_length);
	serv_addr.sin_port = htons(HTTP_PORT);

	/* Connect to the server */
	if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
	{
		fprintf(stderr, "ERROR: Connection failed\n");
		return 3;
	}

	for (;;)
	{
		printf("Enter a line of text: ");
		scanf("%1023s", buffer);

		/* Send message to the server */
		num_bytes = send(sockfd, buffer, strlen(buffer), 0);
		if (num_bytes < 0)
		{
			fprintf(stderr, "ERROR: Failed writing to socket\n");
			return 4;
		}

		/* Now read server response (may require multiple reads)*/
		memset(buffer, 0, BUFFER_SIZE);
		num_bytes = recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
		if (num_bytes == -1)
		{
			printf("recv() failed\n");
			return -4;
		}
		printf("Response: %s\n", buffer);
	}

	close(sockfd);
	return 0;
}
