/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yst-laur <yst-laur@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 10:31:28 by yst-laur          #+#    #+#             */
/*   Updated: 2021/09/24 10:31:32 by yst-laur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

static int	total_str_len(char const *s1, char const *s2)
{
	int	total_len;

	total_len = 0;
	total_len += ft_strlen(s1);
	total_len += ft_strlen(s2);
	return (total_len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*ns;
	size_t		start;
	size_t		i;
	size_t		k;

	if (!s1)
		return ((char *)s2);
	if (!s2)
		return ((char *)s1);
	start = ft_strlen(s1);
	i = 0;
	k = 0;
	ns = malloc((total_str_len(s1, s2) + 1 * sizeof(char)));
	if (ns == NULL)
		return (NULL);
	ft_strlcpy(ns, s1, total_str_len(s1, s2) + 1);
	ft_strlcat(ns, s2, total_str_len(s1, s2) + 1);
	return (ns);
}
