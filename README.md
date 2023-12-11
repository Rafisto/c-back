## `C` Backend template

This is a simple C program for a basic server with logging capabilities and HTTP handling.

### Project Structure

- **build/:** Directory for compiled object files and the final executable.
- **init.c:** Initialization logic for the server.
- **logging/:** Directory for logging-related files.
  - `logging.c`: Implementation of logging functions.
  - `logging.h`: Header file for logging function declarations.
- **main.c:** Main logic for the server, including the server loop.
- **Makefile:** Configuration file for building the project.
- **server.h:** Header file with declarations for server-related functions.
- **shutdown.c:** Shutdown logic for the server.

### Building and Running

To build the project, run the following commands in the project root directory:

```bash
make
```