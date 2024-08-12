#include "utils.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

void codage(char **argv)
{
    char c;
    char *content_doc;
    int i;
    int Ropen = open(argv[1], O_RDONLY);                       //ouverture
    if (Ropen == -1)
    {
        ft_putstr("Erreur lors de l'ouverture du fichier\n");
        return ;
    }
    content_doc = doc_content(Ropen, c, 1);
    close(Ropen);                                             //fermeture
    i = 0;
    while (content_doc[i])
    {
        if (content_doc[i] >= 'a' && content_doc[i] <= 'z')
            content_doc[i] -= 64;
        else if (content_doc[i] >= 'A' && content_doc[i] <= 'Z')
        {
            ft_putstr("erreur, les majuscules ne sont pas acceptees.\n");
            return ;
        }
        i++;
    }
    int Wopen = open(argv[1], O_WRONLY | O_TRUNC);                      //ouverture
    if (Wopen == -1)
    {
        ft_putstr("Erreur lors de l'ouverture du fichier\n");
        return ;
    }
    write(Wopen, content_doc, i);
    ft_putstr("codage effectue\n");
    close(Wopen);                                                       //fermeture
    free(content_doc);
    system("read -p 'Appuyez sur Entrée pour continuer...' var");
    system("clear");
}
