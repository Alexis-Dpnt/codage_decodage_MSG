#include "utils.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

void decodage(char *fichier)
{
    int i;
    char *content_doc;
    char c;
    int Ropen = open(fichier, O_RDONLY);
    if (Ropen == -1)
    {
        ft_putstr("Erreur lors de l'ouverture du fichier\n");
        return ;
    }
    content_doc = doc_content(Ropen, c, 1);
    close(Ropen);
    i = 0;
    while (content_doc[i])
    {
        if ((content_doc[i] >= 33 && content_doc[i] <= 58))
            content_doc[i] += 64;
        else if (content_doc[i] >= 'A' && content_doc[i] <= 'Z')
        {
            ft_putstr("erreur, les majuscules ne sont pas acceptees.\n");
            return ;
        }
        i++;
    }
    int Wopen = open(fichier, O_WRONLY, O_TRUNC);
    if (Wopen == -1)
    {
        ft_putstr("Erreur lors de l'ouverture du fichier\n");
        return ;
    }
    write(Wopen, content_doc, i);
    ft_putstr("decodage effectue\n");
    close(Wopen);
    free(content_doc);
    system("read -p 'Appuyez sur Entrée pour continuer...' var");
    system("clear");
}