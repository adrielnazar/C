
#include <winsock2.h>
#include <windows.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>

#define TAMANHO_BUFFER 512
#define DEFAULT_PORT 27015

int main() 
{
    
    WSADATA wsaData;
    SOCKET sockete;
    
    struct sockaddr_in server, si_other;
    int slen = sizeof(si_other);
    int iResult;  
    char recvbuf[TAMANHO_BUFFER];

    iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
    if (iResult != 0) {
        printf("WSAStartup falhou com o erro: %d\n", iResult);
        system("pause"); exit(EXIT_FAILURE);
    }

    char hostname[NI_MAXHOST];        
    gethostname(hostname,NI_MAXHOST); 
    printf("*************\nServidor: Meu nome: %s\n",hostname);

    PHOSTENT phe = gethostbyname(hostname);     
    int i;
    for (i = 0; phe->h_addr_list[i] != 0; ++i) {
        struct in_addr addr;
        memcpy(&addr, phe->h_addr_list[i], sizeof(struct in_addr));
        printf("Servidor: Meu endereco IP (%d): %s\n",i, inet_ntoa(addr));        
        
    }

    sockete = socket(AF_INET , SOCK_DGRAM , 0);
    if (sockete == INVALID_SOCKET) {
        printf("socket falhou com erro: %ld\n", WSAGetLastError());
        system("pause"); exit(EXIT_FAILURE);
    }

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons( DEFAULT_PORT );

    iResult = bind(sockete ,(struct sockaddr *)&server , sizeof(server));
    if (iResult == SOCKET_ERROR) {
        printf("bind falhou com erro: %d\n", WSAGetLastError());
        system("pause"); exit(EXIT_FAILURE);
    }

    while (1) 
    {
        printf("*************\n");
        printf("Servidor: Esperando por dados de clientes...\n");

        memset(recvbuf,'\0', TAMANHO_BUFFER);

        iResult = recvfrom(sockete, recvbuf, TAMANHO_BUFFER, 0, (struct sockaddr *) &si_other, &slen);
        if (iResult == SOCKET_ERROR) {
            printf("recvfrom() falhou com o erro : %d\n" , WSAGetLastError());
            system("pause"); exit(EXIT_FAILURE);
        }

        printf("Pacote recebido de %s:%d\n", inet_ntoa(si_other.sin_addr), ntohs(si_other.sin_port));
        printf("Dados recebidos: %s\n", recvbuf);
         
        iResult = sendto(sockete, recvbuf, strlen(recvbuf), 0, (struct sockaddr*) &si_other, slen);
        if (iResult == SOCKET_ERROR)
        {
            printf("sendto() falhou com o erro : %d" , WSAGetLastError());
            system("pause"); exit(EXIT_FAILURE);
        }

    }

    printf("Encerrando socket...");
    closesocket(sockete);
    WSACleanup();

    system("pause");
    return 0;
}
