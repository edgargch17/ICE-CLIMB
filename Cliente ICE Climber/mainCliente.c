#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>
#include <conio.h>
// Need to link with Ws2_32.lib
#pragma comment(lib, "ws2_32.lib")

#define MAXSIZEBUFFER 1024
#define IP "127.0.0.1"
#define PUERTO 8080

//////////// Buffer Para Enviar Datos //////////////
char* sendBuffer;
char recvBuffer[MAXSIZEBUFFER];
char* ptRB;
int respuesta;


int main()
{
    WSADATA WSAData;
    WORD wVersionRequested;
    SOCKET server;
    SOCKADDR_IN addr;
    int error;
    
    wVersionRequested = MAKEWORD(2, 2);
	error = WSAStartup(wVersionRequested, &WSAData);
    if (error != 0) {
        printf("WSAStartup failed with error...");
        return 1;
    }
    server = socket(AF_INET, SOCK_STREAM, 0);
 
    addr.sin_addr.s_addr = inet_addr(IP); // replace the ip with your futur server ip address. If server AND client are running on the same computer, you can use the local ip 127.0.0.1
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PUERTO);
 
    connect(server, (SOCKADDR *)&addr, sizeof(addr));
    printf("\n Connected to server!");
    
    
    /////////////// Aqui meteria el while //////////////////
    
    /////////////// Limpia los buffers ///////////////////
    memset(&sendBuffer,0,MAXSIZEBUFFER);
    
    ////////////// Envio de Datos /////////////
    sendBuffer = "cerrar Server";
    respuesta = send(server, sendBuffer, MAXSIZEBUFFER, 0);
    if (respuesta == SOCKET_ERROR){
    	printf("\n Error al enviar el dato...");
    }
    else { printf("\n Dato enviado...");}

    ////////////// Recibo de Datos /////////////
    ptRB=recvBuffer;
    respuesta = recv(server, &ptRB, MAXSIZEBUFFER, 0);
    if (respuesta == SOCKET_ERROR){
    	printf("\n Error sin respuesta...");
    }
    else { 
   		printf("\n Respuesta del Server: %s",recvBuffer);
	}  
    

    ///////////// Se cierra el socket creado ///////////////
    closesocket(server);
    WSACleanup();
    printf("\n Socket closed.");
}
