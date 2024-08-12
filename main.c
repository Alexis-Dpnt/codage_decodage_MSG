#include "utils.h"
#include <stdio.h>

int main()
{
    int choix;
    char *fichier;
    system("clear");
    ft_putstr("entre le nom du fichier a coder ou decoder \"nom_du_fichier.txt\"\n");
    scanf("%s", fichier);
    choix = 0;
    while (choix != 4)
    {
        ft_putstr("veux-tu :\n1-Coder un message\n2-Decoder un message\n3-Voir le contenu su fichier\n4-Quitter\n");
        scanf("%d", &choix);
        if (choix == 1)
            codage(fichier);
        else if (choix == 2)
            decodage(fichier);
        else if (choix == 3)
            see_result(fichier);
        else if (choix == 4)
        {
            system("clear");
            return (0);
        }
        else
            ft_putstr("choix invalide\n");
    }
    return (0);
}
