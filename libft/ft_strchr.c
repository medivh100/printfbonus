/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yst-laur <yst-laur@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 10:24:33 by yst-laur          #+#    #+#             */
/*   Updated: 2021/09/24 10:24:36 by yst-laur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	cin;

	cin = c;
	while (*s)
	{
		if (*s == cin)
		{
			return ((char *) s);
		}
		s++;
	}
	if (cin == '\0')
	{
		return ((char *) s);
	}
	return (NULL);
}
