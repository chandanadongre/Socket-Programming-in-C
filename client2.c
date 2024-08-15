#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>
#include <ws2tcpip.h>

#pragma comment(lib, "ws2_32.lib") // Link with Winsock library

int main(){

    char *ip = "127.0.0.1";
    int port = 5566;

    WSADATA wsa;
    SOCKET sock;
    struct sockaddr_in addr;
    char buffer[1024];

    // Initialize Winsock
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
        printf("Failed. Error Code: %d\n", WSAGetLastError());
        return 1;
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == INVALID_SOCKET){
        printf("Socket creation failed. Error Code: %d\n", WSAGetLastError());
        return 1;
    }
    printf("[+]TCP server socket created.\n");

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(ip);

    if (connect(sock, (struct sockaddr*)&addr, sizeof(addr)) < 0){
        printf("Connection failed. Error Code: %d\n", WSAGetLastError());
        return 1;
    }
    printf("Connected to the server.\n");

    memset(buffer, 0, 1024);
    strcpy(buffer, "HELLO, THIS IS CLIENT.");
    printf("Client: %s\n", buffer);
    send(sock, buffer, strlen(buffer), 0);

    memset(buffer, 0, 1024);
    recv(sock, buffer, sizeof(buffer), 0);
    printf("Server: %s\n", buffer);

    closesocket(sock);
    printf("Disconnected from the server.\n");

    // Clean up Winsock
    WSACleanup();

    return 0;
}
