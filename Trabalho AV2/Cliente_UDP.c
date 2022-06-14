
#include <winsock2.h>
#include <windows.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>

#define TAMANHO_BUFFER 512
#define DEFAULT_PORT 27015
#define IP_SERVIDOR "127.0.0.1"

int main(void) 
{
    
    WSADATA wsaData;
    SOCKET sockete;

    struct sockaddr_in si_other;
    int slen=sizeof(si_other);
          
    char sendbuf[TAMANHO_BUFFER];     
    char recvbuf[TAMANHO_BUFFER];     
    int iResult;

    iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
    if (iResult != 0) {
        printf("WSAStartup falhou com o erro: %d\n", iResult);
        system("pause"); exit(EXIT_FAILURE);
    }

    char hostname[NI_MAXHOST];
    gethostname(hostname,NI_MAXHOST);
    printf("*************\nCliente: Meu nome: %s\n",hostname);

    PHOSTENT phe = gethostbyname(hostname);     
    int i;
    for (i = 0; phe->h_addr_list[i] != 0; ++i) {
        struct in_addr addr;
        memcpy(&addr, phe->h_addr_list[i], sizeof(struct in_addr));
        printf("Cliente: Meu endereco IP (%d): %s\n",i,inet_ntoa(addr));
    }

    sockete = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (sockete == SOCKET_ERROR)
    {
        printf("Nao pode criar o socket. Erro: %d" , WSAGetLastError());
        system("pause"); exit(EXIT_FAILURE);
    }

    memset((char *) &si_other, 0, sizeof(si_other));
    si_other.sin_family = AF_INET;
    si_other.sin_port = htons(DEFAULT_PORT);
    si_other.sin_addr.S_un.S_addr = inet_addr(IP_SERVIDOR);

    while(1)
    {
        printf("*************\n");
        printf("Digite uma mensagem : ");
        gets(sendbuf);

        iResult = sendto(sockete, sendbuf, strlen(sendbuf) , 0 , (struct sockaddr *) &si_other, slen);
        if (iResult == SOCKET_ERROR)
        {
            printf("sendto() falhou com o erro : %d\n" , WSAGetLastError());
            system("pause"); exit(EXIT_FAILURE);
        }

        memset(recvbuf,'\0', TAMANHO_BUFFER);

        iResult = recvfrom(sockete, recvbuf, TAMANHO_BUFFER, 0, (struct sockaddr *) &si_other, &slen);
        if (iResult == SOCKET_ERROR)
        {
            printf("recvfrom() falhou com o erro : %d\n" , WSAGetLastError());
            system("pause"); exit(EXIT_FAILURE);
        }

        printf("Servidor enviou: %s\n",recvbuf);
    }

    printf("Encerrando socket...");
    closesocket(sockete);
    WSACleanup();
    system("pause");
    return 0;
}
