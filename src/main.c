#include <stdio.h>
#include <stdlib.h>

#include <sys/socket.h>
#include <unistd.h>

#include "server.h"
#include "./logging/logging.h"

#define PORT 5000
#define MAX_CONNECTIONS 10

int main()
{
    int server_socket = initialize_server(PORT, MAX_CONNECTIONS);
    if (server_socket == -1)
    {
        log_stdout("ERROR", "Failed to initialize the server. Exiting.");
        return 1;
    }

    log_stdout("INFO", "Server listening on port %d.", PORT);

    while (1)
    {
        int connection = accept(server_socket, (struct sockaddr *)NULL, NULL);
        if (connection == -1)
        {
            log_stdout("ERROR", "Error accepting connection.");
            continue;
        }

        log_stdout("INFO", "Accepted connection %d.", connection);
        char hello_message[] = "HTTP/1.1 200 OK\nContent-Type: text/html\n\n"
                               "<html>Hello World!</html>";
        send(connection, hello_message, sizeof(hello_message), 0);
        close(connection);
    }

    log_stdout("INFO", "Server shutdown.");
    return 0;
}
