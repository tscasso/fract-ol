/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tscasso <tscasso@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:36:55 by tscasso           #+#    #+#             */
/*   Updated: 2023/03/13 15:16:59 by tscasso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Cette fonction alloue un bloc de mémoire de taille nmemb * size 
** et initialise toutes les positions de ce bloc à 0.
** Elle renvoie un pointeur vers le début de ce bloc de mémoire,
** ou NULL si l'allocation de mémoire échoue.
**
** nmemb : le nombre d'éléments à allouer
** size : la taille de chaque élément en octets
**
** Retour : un pointeur vers le début du bloc de mémoire alloué,
** ou NULL si l'allocation a échoué.
** Cette fonction prend en compte les cas particuliers suivants :

**  - si nmemb ou size sont égaux à 0, la fonction renvoie NULL 
**    sans allouer de mémoire
**  - si la multiplication de nmemb et size dépasse la taille maximale 
**    d'un size_t,
**    la fonction renvoie NULL et déclenche une erreur de dépassement 
**    de capacité
**
** nmemb : le nombre d'éléments à allouer
** size : la taille de chaque élément en octets
**
** Retour : un pointeur vers le début du bloc de mémoire alloué, 
** ou NULL si l'allocation a échoué
*/

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total_size;
	void	*ptr;
	char	*p;

	total_size = nmemb * size;
	ptr = malloc(total_size);
	p = ptr;
	if (ptr != NULL)
	{
		while (total_size--)
		*p++ = 0;
	}
	return (ptr);
}
