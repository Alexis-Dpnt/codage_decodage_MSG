#include "utils.h"
#include <stddef.h>
#include <stdlib.h>

void ft_putstr(char *str)
{
    int i;
    i = 0;
    while (str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
}

char *doc_content(int fd, char c, int oct)
{
    int i;
    char *tab;
    
    i = 0;
    while (read(fd, &c, oct))
        i++;
    tab = malloc(sizeof(char) * (i + 1));
    lseek(fd, 0, SEEK_SET);
    if (tab == NULL)
        return (NULL);
    i = 0;
    while (read(fd, &c, oct))
    {
        tab[i] = c;
        i++;
    }
    tab[i] = '\0';
    return (tab);
}

char *doc_contentW(int fd, char c, int oct)
{
    int i;
    char *tab;
    
    i = 0;
    while (read(fd, &c, oct))
        i++;
    tab = malloc(sizeof(char) * (i + 1));
    lseek(fd, 0, SEEK_SET);
    if (tab == NULL)
        return (NULL);
    i = 0;
    while (read(fd, &c, oct))
    {
        tab[i] = c;
        write(1, &tab[i], 1);
        i++;
    }
    tab[i] = '\0';
    return (tab);
}