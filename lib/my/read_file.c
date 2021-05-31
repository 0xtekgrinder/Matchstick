/*
** EPITECH PROJECT, 2021
** read_file.c
** File description:
** this is the file to read a file
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdbool.h>

static char *is_malloc_ok(size_t size)
{
    char *buff;

    buff = malloc(sizeof(char) * (size + 1));
    if (buff != NULL)
        buff[size] = '\0';
    return (buff);
}

static bool is_read_okay(size_t size, int fd, char *buff)
{
    if (read(fd, buff, size) == -1) {
        free(buff);
        close(fd);
        return (false);
    }
    return (true);
}

char *read_file(char *file_name)
{
    struct stat file_info;
    int fd;
    char *buff;

    if (stat(file_name, &file_info) == -1)
        return (NULL);
    buff = is_malloc_ok(file_info.st_size);
    if (buff == NULL)
        return (NULL);
    fd = open(file_name, O_RDONLY);
    if (fd == -1) {
        free(buff);
        return (NULL);
    }
    if (is_read_okay(file_info.st_size, fd, buff) == false)
        return (NULL);
    if (close(fd) == -1)
        return (NULL);
    return (buff);
}