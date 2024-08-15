# Socket-Programming-in-C
TCP Client-Server Implementation in C
# Overview
This repository contains code for a simple TCP client-server communication implemented in C. The codes are provided for both Windows and Linux environments. The client sends a message to the server, and the server responds.
<br>
Note: client1.c & server1.c files: For Windows version
client.c & server.c files:For Linux version
<br>

# Windows Version
<br>
Description
The Windows version of the code uses the Winsock2 library for socket programming, which provides the necessary functions for network communication. Below are some key functions and modifications specific to the Windows environment:
<br>
WSAStartup(): This function initializes the Winsock library and must be called before any Winsock functions can be used. It takes the version of Winsock as an argument and returns 0 on success.
<br>
WSACleanup(): This function is used to terminate the use of the Winsock library. It should be called after all socket operations are done.
<br>
closesocket(): This function closes an open socket in Windows. Unlike Unix-like systems, where the close() function is used, Windows uses closesocket() to ensure proper cleanup of socket resources.
<br>
Include Headers:
#include <winsock2.h>: Main header for Winsock functions.
#include <ws2tcpip.h>: Additional header for functions like inet_addr().
<br>

# Linux Version
<br>
Description
The Linux version of the code uses standard POSIX libraries for socket programming. This version should run on most Unix-like systems without modification. Below are some key functions used in the Linux environment:
<br>
socket(): This function creates a socket for communication. It takes three arguments: the domain (e.g., AF_INET for IPv4), the type (e.g., SOCK_STREAM for TCP), and the protocol (usually 0 for the default protocol).
<br>
bind(): This function binds the socket to an IP address and port number, allowing the server to listen for incoming connections.
<br>
listen(): This function sets the socket to listen for incoming connection requests.
<br>
accept(): This function blocks the server until a client attempts to connect. Upon connection, it returns a new socket dedicated to the client, allowing the server to continue accepting other connections.
<br>
close(): This function closes an open socket in Linux, freeing up the resources associated with it.
<br>
Include Headers:
#include <arpa/inet.h>: Provides functions for manipulating IP addresses and ports.
#include <unistd.h>: Provides access to the POSIX operating system API.
<br>

# Commands to Compile and Run (Linux & Windows)
1. Compile the Server:
gcc server.c -o server
gcc server1.c -o server -lws2_32

2. Compile the Client:
gcc client.c -o client
gcc client1.c -o client -lws2_32

3. Run the Server:
./server

4. Run the Client:
./client

Note: Ensure server is running before starting client to establish connection else connection wont be successfull.