/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yst-laur <yst-laur@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 10:27:55 by yst-laur          #+#    #+#             */
/*   Updated: 2021/09/24 10:28:09 by yst-laur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = count * size;
	j = 0;
	str = malloc(count * size);
	if (str == NULL)
		return (NULL);
	while (j < i)
	{
		str[j] = '\0';
		j++;
	}
	return ((void *) str);
}
