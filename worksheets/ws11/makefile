all: clean http_client http_server

http_client:
	gcc -Wall -o http_client http_client.c

http_server:
	gcc -Wall -o http_server http_server.c

clean:
	-rm http_client http_server