/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tscasso <tscasso@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 20:38:10 by tscasso           #+#    #+#             */
/*   Updated: 2023/03/02 22:04:44 by tscasso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	unsigned const char	*s;
	int					*p;

	d = dest;
	s = src;
	p = NULL;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (n-- > 0)
	{
		if (dest == NULL || src == NULL )
			*p = 0;
		*d++ = *s++;
	}
	return (dest);
}

/*
Enlever ligne 28 et 29 pour éviter le segv
*/
