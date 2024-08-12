/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decodage.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexis <alexis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 22:49:55 by alexis            #+#    #+#             */
/*   Updated: 2024/08/12 12:08:05 by alexis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

void decodage(char **argv)
{
    int i;
    char *content_doc;
    char c;
    int Ropen = open(argv[1], O_RDONLY);
    if (Ropen == -1)
    {
        ft_putstr("Erreur lors de l'ouverture du fichier");
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
            ft_putstr("erreur, les majuscules ne sont pas acceptees.");
            return ;
        }
        i++;
    }
    int Wopen = open(argv[1], O_WRONLY, O_TRUNC);
    if (Wopen == -1)
    {
        ft_putstr("Erreur lors de l'ouverture du fichier");
        return ;
    }
    write(Wopen, content_doc, i);
    close(Wopen);                                                       //fermeture
    free(content_doc);
}