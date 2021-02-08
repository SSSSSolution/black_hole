#include "r_log/rlog.h"

#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    int server_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET; // use IPv4 address
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_addr.sin_port = htons(1234);
    bind(server_sock, (struct sockaddr*)&server_addr, sizeof(server_addr));

    listen(server_sock, 20);

    struct sockaddr_in client_addr;
    socklen_t client_addr_size = sizeof(client_addr);
    int client_sock = accept(server_sock, (struct sockaddr*)&client_addr, &client_addr_size);

    char str[] = "Hello World!";
    write(client_sock, str, sizeof(str));

    close(client_sock);
    close(server_sock);

    return 0;
}
