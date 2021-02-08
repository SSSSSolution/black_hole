#include "r_log/rlog.h"

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main(int argc, char **argv)
{
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_addr.sin_port = htons(1234);
    connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr));

    char buffer[40] = {0};
    read(sock, buffer, sizeof(buffer) - 1);

    RLOG(INFO, "recevie: %s", buffer);

    close(sock);

    return 0;
}
