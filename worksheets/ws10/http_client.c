#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>

#include "http.h"

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		fprintf(stderr, "No domain was passed.\n");
		return -1;
	}

	int sockfd, num_bytes;
	struct sockaddr_in serv_addr;
	struct hostent *url;
	char buffer[BUFFER_SIZE] = {0};
	char *domain = argv[1];

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

	/* Prepare request */
	snprintf(buffer, sizeof(buffer), "GET http://www.%s HTTP/1.0\r\n\r\n", domain);

	/* Send message to the server */
	num_bytes = send(sockfd, buffer, strlen(buffer), 0);
	if (num_bytes < 0)
	{
		fprintf(stderr, "ERROR: Failed writing to socket\n");
		return 4;
	}

	/* make sure that all the request was sent */
	assert(num_bytes == strlen(buffer));

	/* Now read server response (may require multiple reads)*/
	do {
	
		memset(buffer, 0, BUFFER_SIZE);
		num_bytes = recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
		if (num_bytes > 0)
		{
			char *statusCode = (char *)malloc(4 * sizeof(char));
			strncpy(statusCode, buffer + 9, 3);

			printf("Status Code: %s\n", statusCode);
			printf("Size of response: %d\n", num_bytes);
		}

	} while (num_bytes > 0);

	if (num_bytes < 0)
	{
		fprintf(stderr, "ERROR: Failed reading from socket\n");
		return 5;
	}

	close(sockfd);
	return 0;
}
