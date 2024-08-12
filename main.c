/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexis <alexis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 23:56:22 by alexis            #+#    #+#             */
/*   Updated: 2024/08/12 12:04:13 by alexis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    int choix;
    choix = 0;

    if (argc < 2)
    {
        ft_putstr("Usage: ./programme <nom_du_fichier>\n");
        return (1);
    }

    ft_putstr("veux-tu :\n1-coder un message\n2-decoder un message\n");
    scanf("%d", &choix);

    if (choix == 1)
        codage(argv);
    else if (choix == 2)
        decodage(argv);
    else
        ft_putstr("choix invalide\n");
    return (0);
}
