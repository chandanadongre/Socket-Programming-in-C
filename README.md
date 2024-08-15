# Socket-Programming-in-C
**TCP Client-Server Implementation in C**
## Overview
This repository contains code for a simple TCP client-server communication implemented in C. The codes are provided for both Windows and Linux environments. The client sends a message to the server, and the server responds.
Note: 
- `client1.c` & `server1.c` files: For Windows version  
- `client.c` & `server.c` files: For Linux version  
## Windows Version
### Description
The Windows version of the code uses the **Winsock2** library for socket programming, which provides the necessary functions for network communication. Below are some key functions and modifications specific to the Windows environment:
- **`WSAStartup()`**: This function initializes the Winsock library and must be called before any Winsock functions can be used. It takes the version of Winsock as an argument and returns `0` on success.
- **`WSACleanup()`**: This function is used to terminate the use of the Winsock library. It should be called after all socket operations are done.
- **`closesocket()`**: This function closes an open socket in Windows. Unlike Unix-like systems, where the `close()` function is used, Windows uses `closesocket()` to ensure proper cleanup of socket resources. 
**Include Headers:**
- `#include <winsock2.h>`: Main header for Winsock functions.
- `#include <ws2tcpip.h>`: Additional header for functions like `inet_addr()`.

## Linux Version
### Description
The Linux version of the code uses standard **POSIX** libraries for socket programming. This version should run on most Unix-like systems without modification. Below are some key functions used in the Linux environment:
- **`socket()`**: This function creates a socket for communication. It takes three arguments: the domain (e.g., `AF_INET` for IPv4), the type (e.g., `SOCK_STREAM` for TCP), and the protocol (usually `0` for the default protocol).
- **`bind()`**: This function binds the socket to an IP address and port number, allowing the server to listen for incoming connections.
- **`listen()`**: This function sets the socket to listen for incoming connection requests.
- **`accept()`**: This function blocks the server until a client attempts to connect. Upon connection, it returns a new socket dedicated to the client, allowing the server to continue accepting other connections.
- **`close()`**: This function closes an open socket in Linux, freeing up the resources associated with it.
**Include Headers:**
- `#include <arpa/inet.h>`: Provides functions for manipulating IP addresses and ports.
- `#include <unistd.h>`: Provides access to the POSIX operating system API.

## Commands to Compile and Run
1. **Compile the Server:**
   - Linux:
     ```bash
     gcc server.c -o server
     ```
   - Windows:
     ```bash
     gcc server1.c -o server -lws2_32
     ```
2. **Compile the Client:**
   - Linux:
     ```bash
     gcc client.c -o client
     ```
   - Windows:
     ```bash
     gcc client1.c -o client -lws2_32
     ```
3. **Run the Server:**
   ```bash
   ./server
4. **Run the Client:**
   ```bash
   ./client
   
# Summary of Differences
1. **Socket Initialization:**
Windows: Requires WSAStartup() to initialize Winsock.
Linux: No explicit initialization function needed.
2. **Socket Closure:**
Windows: Uses closesocket().
Linux: Uses close().
3. **Library Linking:**
Windows: Requires linking with -lws2_32.
Linux: No special library is needed; the standard C library is sufficient.

# Conclusion
This repository provides a simple example of TCP socket communication between a client and server, demonstrating the necessary platform-specific changes between Windows and Linux. These examples serve as a foundation for more complex socket programming tasks.
