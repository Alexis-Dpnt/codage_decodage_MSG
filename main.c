#include "utils.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    int choix;
    if (argc < 2)
    {
        ft_putstr("Usage: ./programme <nom_du_fichier txt>\n");
        return (1);
    }
    system("clear");
    choix = 0;
    while (choix != 4)
    {
        ft_putstr("veux-tu :\n1-Coder un message\n2-Decoder un message\n3-Voir le contenu su fichier\n4-Quitter\n");
        scanf("%d", &choix);

        if (choix == 1)
            codage(argv);
        else if (choix == 2)
            decodage(argv);
        else if (choix == 3)
            see_result(argv);
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
