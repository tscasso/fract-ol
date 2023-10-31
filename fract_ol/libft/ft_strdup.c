/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tscasso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:03:07 by tscasso           #+#    #+#             */
/*   Updated: 2023/02/23 17:03:12 by tscasso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/*char	*ft_strdup(const char *s)
{
	size_t		len;
	void		*dup;

	len = ft_strlen(s + 1);
	dup = malloc(len);
	if (dup == NULL)
		return (NULL);
	return ((char *)ft_memcpy(dup, s, len));
}

*/

char	*ft_strdup(const char *s)
{
	char	*ns;
	size_t	i;

	i = 0;
	ns = (char *)ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!ns)
	{
		return (NULL);
	}
	while (s[i])
	{
		ns[i] = s[i];
		i++;
	}
	ns[i] = '\0';
	return (ns);
}
