#include "utils.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

void see_result(char *fichier)
{
    char *content;
    char c;

    int readO = open(fichier, O_RDONLY);
    content = doc_contentW(readO, c, 1);
    close(readO);
    write(1, "\n", 1);
    free(content);
    system("read -p 'Appuyez sur Entrée pour continuer...' var");
    system("clear");
}