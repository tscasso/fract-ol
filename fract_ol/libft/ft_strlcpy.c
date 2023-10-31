/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tscasso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 18:51:47 by tscasso           #+#    #+#             */
/*   Updated: 2023/02/04 18:51:49 by tscasso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	len;

	len = ft_strlen(src);
	if (!size)
		return (len);
	if (size <= len)
		len = size - 1;
	ft_memcpy(dest, src, len);
	dest[len] = '\0';
	return ((size_t)ft_strlen(src));
}
