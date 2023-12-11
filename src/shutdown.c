#include <stdio.h>
#include <unistd.h>

#include "server.h"
#include "./logging/logging.h"

void shutdown_server(int server_socket)
{
    log_stdout("INFO", "Shutting down server.");

    if (close(server_socket) == -1)
    {
        log_stdout("ERROR", "Error closing server socket.");
    }
    else
    {
        log_stdout("INFO", "Server socket closed successfully.");
    }
}
