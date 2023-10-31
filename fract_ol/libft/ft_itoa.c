/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tscasso <tscasso@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:37:12 by tscasso           #+#    #+#             */
/*   Updated: 2023/03/13 18:14:20 by tscasso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 ** Calcule la longueur d'un nombre entier en chiffres.
 **
 ** n : le nombre entier dont on veut connaître la longueur.
 **
 ** Retour: le nombre de chiffres du nombre entier n.
 */

static int	ft_nbrlen(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i = 1;
	while (n)
	{
		n /= 10;
		++i;
	}
	return (i);
}

/*
 ** ft_itoa - Convertit un nombre entier en une chaîne de caractères.
 **
 ** n: le nombre entier à convertir.
 **
 ** Retour: une chaîne de caractères représentant le nombre entier n.
 ** Si la conversion échoue, retourne NULL.
 **
 ** Note: le pointeur retourné doit être libéré par l'appelant avec free().
 */

char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	len = ft_nbrlen(n);
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		if (n == -2147483648)
		{
			str[--len] = '8';
			n /= 10;
		}
		n = -n;
	}
	while (len-- && n != 0)
	{
		str[len] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}
