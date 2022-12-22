/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yst-laur <yst-laur@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 10:26:27 by yst-laur          #+#    #+#             */
/*   Updated: 2021/09/24 10:26:32 by yst-laur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	count;

	count = 0;
	while (*s)
	{
		count++;
		s++;
	}
	while (count >= 0)
	{
		if (*s == (char)c)
			return ((char *) s);
		s--;
		count--;
	}
	return (NULL);
}
