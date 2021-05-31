/*
** EPITECH PROJECT, 2021
** test
** File description:
** test
*/

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>

static void connection(int listenfd, int *connfd)
{
    printf("Awaiting connection...\n");
     while (1) {
        connfd[0] = accept(listenfd, (struct sockaddr *)NULL, NULL);
        if (connfd[0] == -1) {
            printf("First connection failed\n");
            continue;
        } else
            printf("First connection succed\n");
        connfd[1] = accept(listenfd, (struct sockaddr *)NULL, NULL);
        if (connfd[1] == -1) {
            printf("Second connection failed\n");
            continue;
        } else
            printf("Second connection succed\n");
        break;
    }
}

static void main_loop(int *connfd)
{
    int len = 0;
    char sendBuff[1025];

    memset(sendBuff, '0', sizeof(sendBuff));
    while (1) {
        len = read(connfd[0], sendBuff, 1000);
        if (len == -1)
            break;
        sendBuff[len - 1] = '\0';
        if (write(connfd[1], sendBuff, strlen(sendBuff)) == -1)
            break;
        len = read(connfd[1], sendBuff, 1000);
        if (len == -1)
            break;
        sendBuff[len - 1] = '\0';
        if (write(connfd[0], sendBuff, strlen(sendBuff)) == -1)
            break;
    }
}

static int init_server(int *listenfd, struct sockaddr_in serv_addr)
{
    *listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if (*listenfd == -1) {
        printf("\n Error : Could not create socket \n");
        return (EXIT_FAILURE);
    }
    memset(&serv_addr, '0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(5000);
    if (bind(*listenfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
        printf("\n Error : Could not bind\n");
        return (EXIT_FAILURE);
    }
    if (listen(*listenfd, 10) == -1) {
        printf("\n Error : Could not listen\n");
        return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}

int main(void)
{
    int listenfd = 0;
    int connfd[2] = {0, 0};
    struct sockaddr_in serv_addr;

    if (init_server(&listenfd, serv_addr) == EXIT_FAILURE)
        return (EXIT_FAILURE);
    connection(listenfd, connfd);
    main_loop(connfd);
    close(connfd[0]);
    close(connfd[1]);
    return (EXIT_SUCCESS);
}