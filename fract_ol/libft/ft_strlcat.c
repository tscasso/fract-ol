/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Thibault <Thibault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:09:54 by tscasso           #+#    #+#             */
/*   Updated: 2023/03/14 04:44:54 by Thibault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//#define SIZE(a, b) ((a) < (b) ? (a) : (b))

/*size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	n;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (!dstsize || dstsize == 0)
		return (ft_strlen(src));
	if (dstsize <= dstlen)
		return (srclen + dstsize);
	if ((dstsize - dstlen - 1) < srclen)
		n = dstsize - dstlen - 1;
	if ((dstsize - dstlen - 1) > srclen)
		n = srclen;
	ft_memcpy(dst + dstlen, src, n);
	dst[dstlen + n] = '\0';
	return (dstlen + srclen);
}
*/

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dst[i] && i < dstsize)
		i++;
	while (src[j] && (i + j + 1) < dstsize)
	{
		dst[i + j] = src[j];
		j++;
	}
	if (i < dstsize)
		dst[i + j] = '\0';
	return (i + ft_strlen(src));
}
