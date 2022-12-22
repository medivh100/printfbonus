/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yst-laur <yst-laur@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 10:32:02 by yst-laur          #+#    #+#             */
/*   Updated: 2021/09/24 10:32:07 by yst-laur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

static char	*memalloc(char const *s)
{
	char	*str;
	int		i;

	i = 0;
	while (s[i])
		i++;
	str = malloc(i + 1 * sizeof(char));
	if (str == NULL)
		return (NULL);
	return (str);
}

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	char	*str;
	int		index;

	if (!s)
		return (NULL);
	index = 0;
	str = memalloc(s);
	if (str == NULL)
		return (NULL);
	while (s[index])
	{
		str[index] = f(index, s[index]);
		index++;
	}
	str[index] = '\0';
	return (str);
}
