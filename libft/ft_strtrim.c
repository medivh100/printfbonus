/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yst-laur <yst-laur@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 10:33:44 by yst-laur          #+#    #+#             */
/*   Updated: 2021/09/24 10:33:48 by yst-laur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

static int	ft_isinset(char const *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static size_t	ft_getstart(char const *s1, char const *set)
{
	size_t	start;

	start = 0;
	while (ft_isinset(set, s1[start]) == 1)
		start++;
	return (start);
}

static size_t	ft_getend(char const *s1, char const *set)
{
	size_t	end;
	size_t	i;

	end = ft_strlen(s1) - 1;
	i = 0;
	while (ft_isinset(set, s1[end]) == 1)
	{
		end--;
		i++;
	}
	return (i);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*nstr;
	size_t	start;
	size_t	end;
	size_t	len;
	size_t	i;

	if (!s1)
		return (NULL);
	start = ft_getstart(s1, set);
	end = ft_getend(s1, set);
	len = ft_strlen(s1);
	i = 0;
	if (start >= (len - end))
		return (ft_strdup(""));
	nstr = malloc(((len - start - end) + 1) * sizeof(char));
	if (nstr == NULL)
		return (NULL);
	while ((i + start) < (len - end))
	{
		nstr[i] = s1[i + start];
		i++;
	}
	nstr[i] = '\0';
	return (nstr);
}
