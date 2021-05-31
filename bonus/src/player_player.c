/*
** EPITECH PROJECT, 2021
** player_player.c
** File description:
** player_player
*/

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
#include <stdbool.h>
#include "my.h"
#include "player_player.h"

static int player_turn(game_tools_t game_tools, FILE *stream, int sockfd)
{
    char line[512];
    char matches[512];

    my_printf("\nYour turn:\n");
    while (1) {
        my_printf("Line: ");
        if (get_input(stream, line) == EXIT_FAILURE)
            return (END_EOF);
        if (!is_line_ok(line, my_tablen(game_tools.map)))
            continue;
        my_printf("Matches: ");
        if (get_input(stream, matches) == EXIT_FAILURE)
            return (END_EOF);
        if (!is_matches_ok(matches, game_tools.map[my_getnbr(line)]
            , game_tools.max_sticks))
            continue;
        break;
    }
    remove_sticks(game_tools.map, my_getnbr(line), my_getnbr(matches));
    my_printf("Player removed %s match(es) from line %s\n", matches, line);
    my_strcat(my_strcat(line, ":"), matches);
    write(sockfd, line, strlen(line) + 1);
    return (CONTINUE);
}

static int load_everything(int *sockfd)
{
    struct sockaddr_in serv_addr;

    if ((*sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Error : Could not create socket \n");
        return (EXIT_FAILURE);
    }
    memset(&serv_addr, '0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(5000);
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf("\n inet_pton error occured\n");
        return (EXIT_FAILURE);
    }
    if (connect(*sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\n Error : Connect Failed \n");
        return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}

static int player_1(int sockfd, game_tools_t game_tools)
{
    char recvBuff[1024];
    int len = 0;
    char **map = NULL;

    memset(recvBuff, '0',sizeof(recvBuff));
    while (1) {
        my_show_word_array(game_tools.map);
        if (is_it_a_win(game_tools.map)) {
            my_printf("Second player won!!\n");
            return (USER_WIN);
        }
        if (player_turn(game_tools, stdin, sockfd) == END_EOF)
            return (END_EOF);
        my_show_word_array(game_tools.map);
        if (is_it_a_win(game_tools.map)) {
            my_printf("First player won!!\n");
            return (USER_WIN);
        }
        len = read(sockfd, recvBuff, 1000);
        if (len == -1)
            break;
        recvBuff[len] = '\0';
        map = my_str_to_word_array(recvBuff);
        remove_sticks(game_tools.map, my_getnbr(map[0]), my_getnbr(map[1]));
        my_printf("Player removed %s match(es) from line %s\n", map[1], map[0]);
        my_free("2", map);
    }
    return (END_EOF);
}

static int player_2(int sockfd, game_tools_t game_tools)
{
    char recvBuff[1024];
    int len = 0;
    char **map = NULL;

    memset(recvBuff, '0',sizeof(recvBuff));
    while (1) {
        my_show_word_array(game_tools.map);
        if (is_it_a_win(game_tools.map)) {
            my_printf("First player won!!\n");
            return (USER_WIN);
        }
        len = read(sockfd, recvBuff, 1000);
        if (len == -1)
            break;
        recvBuff[len] = '\0';
        map = my_str_to_word_array(recvBuff);
        remove_sticks(game_tools.map, my_getnbr(map[0]), my_getnbr(map[1]));
        my_printf("Player removed %s match(es) from line %s\n", map[1], map[0]);
        my_free("2", map);
        my_show_word_array(game_tools.map);
        if (is_it_a_win(game_tools.map)) {
            my_printf("Second player won!!\n");
            return (USER_WIN);
        }
        if (player_turn(game_tools, stdin, sockfd) == END_EOF)
            return (END_EOF);
    }
    return (END_EOF);
}

int player_player(game_tools_t game_tools, int player)
{
    int sockfd = 0;

    if (load_everything(&sockfd) == EXIT_FAILURE)
        return (END_EOF);
    if (player == 1)
        return (player_1(sockfd, game_tools));
    else
        return (player_2(sockfd, game_tools));
}