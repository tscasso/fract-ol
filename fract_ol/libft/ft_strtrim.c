/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tscasso <tscasso@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:38:18 by tscasso           #+#    #+#             */
/*   Updated: 2023/03/13 18:18:55 by tscasso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	Supprimer les caractères de la chaine 'set' présent dans 's1'
	Retour: une chaine de caractères

** 1. Vérifie si les arguments sont non-nuls
** 2. Calcule la longueur de la chaine s1
** 3. Initialise pointeurs 'start' et 'end' au début et fin de s1
** 4. Déplace le pointeur 'start' tant que le caractère pointé
**	  est présent dans 'set'
** 5. Déplace le pointeur 'end' tant que le caractère pointé
**	  est présent dans 'set'
** 6. Extrait la sous-chaîne de s1 qui ne contient pas 
**    les caractères de 'set'
** 7. utilise la sous-chaîne extraite pour créer
**    une nouvelle chaîne de caractères
*/

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	char	*start;
	char	*end;
	char	*result;

	if (s1 == NULL || set == NULL)
		return (NULL);
	len = ft_strlen(s1);
	start = (char *)s1;
	end = (char *)s1 + len - 1;
	while (*start && ft_strchr(set, *start))
		start++;
	while (end > start && ft_strchr(set, *end))
		end--;
	result = ft_substr(start, 0, end - start + 1);
	return (result);
}
