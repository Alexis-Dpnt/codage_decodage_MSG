#ifndef UTILS_H
#define UTILS_H

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stddef.h>

void ft_putstr(char *str);
char *doc_content(int fd, char c, int oct);
char *doc_contentW(int fd, char c, int oct);
void codage(char **argv);
void decodage(char **argv);
void see_result(char **argv);

#endif
