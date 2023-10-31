/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tscasso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 19:22:51 by tscasso           #+#    #+#             */
/*   Updated: 2023/02/23 19:22:57 by tscasso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	const char	*last;

	last = NULL;
	if (c == '\0')
		return ((char *)str + ft_strlen(str));
	while (*str)
	{
		if (*str == c)
			last = str;
		str++;
	}
	return ((char *)last);
}
