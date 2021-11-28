#define BUFFER_SIZE		1024
#define HTTP_PORT 		80
#define MAX_CONNECTIONS 5

#define RESPONSE 	"HTTP/1.0 301 Moved Permanently\r\n\
Server: LLP2 Server (1.0)\r\n\
Location: http://kurtagius.com\r\n\
Content-Length: 0\r\n\
Connection: close\r\n\
Content-Type: text/html; charset=UTF-8\r\n\
\r\n"
