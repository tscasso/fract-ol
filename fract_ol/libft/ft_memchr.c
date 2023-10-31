/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tscasso <tscasso@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:06:33 by tscasso           #+#    #+#             */
/*   Updated: 2023/02/21 17:06:52 by tscasso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*p;
	unsigned char		ch;

	p = s;
	ch = c;
	while (n-- > 0)
	{
		if (*p == ch)
			return ((void *)p);
		p++;
	}
	return (NULL);
}
