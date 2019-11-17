#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>

// Need to link with Ws2_32.lib
#pragma comment(lib, "ws2_32.lib"
 
int main()
{
    WSADATA WSAData;
    WORD wVersionRequested;
    SOCKET server;
    SOCKADDR_IN addr;
    int error;
    
    wVersionRequested = MAKEWORD(2, 2);
	WSAStartup(wVersionRequested, &WSAData);
	//error = WSAStartup(wVersionRequested, &WSAData);
    /*if (error != 0) {
        printf("WSAStartup failed with error...");
        return 1;
    }*/
    /*server = socket(AF_INET, SOCK_STREAM, 0);
 
    addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // replace the ip with your futur server ip address. If server AND client are running on the same computer, you can use the local ip 127.0.0.1
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8080);
 
    connect(server, (SOCKADDR *)&addr, sizeof(addr));
    printf("Connected to server!");
 
    char buffer[1024]={'h', 'e', 'l', 'l', 'o', '.'};
    send(server, buffer, sizeof(buffer), 0);
    printf("Message sent!");
 
    closesocket(server);
    WSACleanup();*/
    printf("Socket closed.");
}
