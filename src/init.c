#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#include "server.h"
#include "./logging/logging.h"

int initialize_server(int port, int max_connections)
{
    log_stdout("INFO", "Initializing Server.");

    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1)
    {
        log_stdout("ERROR", "Error creating server socket.");
        return -1;
    }

    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(port);

    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1)
    {
        log_stdout("ERROR", "Error binding server socket.");
        close(server_socket);
        return -1;
    }

    if (listen(server_socket, max_connections) == -1)
    {
        log_stdout("ERROR", "Error listening for connections.");
        close(server_socket);
        return -1;
    }

    log_stdout("INFO", "Socket Bound and Listening.");
    return server_socket;
}
