/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tscasso <tscasso@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:36:32 by tscasso           #+#    #+#             */
/*   Updated: 2023/02/21 12:36:48 by tscasso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	substr_len;
	char	*result;

	s_len = ft_strlen(s);
	if (!s || len == 0 || start >= s_len)
		return (ft_strdup(""));
	if (start + len > s_len)
		substr_len = s_len - start;
	else
		substr_len = len;
	result = malloc(substr_len + 1);
	if (result == NULL)
		return (NULL);
	ft_memcpy(result, s + start, substr_len);
	result[substr_len] = '\0';
	return (result);
}
