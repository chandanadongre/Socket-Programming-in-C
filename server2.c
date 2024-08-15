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
    SOCKET server_sock, client_sock;
    struct sockaddr_in server_addr, client_addr;
    int addr_size;
    char buffer[1024];

    // Initialize Winsock
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
        printf("Failed. Error Code: %d\n", WSAGetLastError());
        return 1;
    }

    server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock == INVALID_SOCKET){
        printf("Socket creation failed. Error Code: %d\n", WSAGetLastError());
        return 1;
    }
    printf("[+]TCP server socket created.\n");

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(ip);

    if (bind(server_sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0){
        printf("Bind failed. Error Code: %d\n", WSAGetLastError());
        return 1;
    }
    printf("[+]Bind to the port number: %d\n", port);

    listen(server_sock, 5);
    printf("Listening...\n");

    while(1){
        addr_size = sizeof(client_addr);
        client_sock = accept(server_sock, (struct sockaddr*)&client_addr, &addr_size);
        if (client_sock == INVALID_SOCKET){
            printf("Accept failed. Error Code: %d\n", WSAGetLastError());
            continue;
        }
        printf("[+]Client connected.\n");

        memset(buffer, 0, 1024);
        recv(client_sock, buffer, sizeof(buffer), 0);
        printf("Client: %s\n", buffer);

        memset(buffer, 0, 1024);
        strcpy(buffer, "HI, THIS IS SERVER. HAVE A NICE DAY!!!");
        printf("Server: %s\n", buffer);
        send(client_sock, buffer, strlen(buffer), 0);

        closesocket(client_sock);
        printf("[+]Client disconnected.\n\n");
    }

    // Clean up Winsock
    closesocket(server_sock);
    WSACleanup();

    return 0;
}
