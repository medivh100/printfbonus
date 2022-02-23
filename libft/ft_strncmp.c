/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yst-laur <yst-laur@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 10:26:08 by yst-laur          #+#    #+#             */
/*   Updated: 2021/09/24 10:26:11 by yst-laur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	index;

	index = 0;
	while (index < n && (*s1 || *s2))
	{
		if (*s1 != *s2)
		{
			return ((unsigned char) *s1 - (unsigned char) *s2);
		}
		s1++;
		s2++;
		index++;
	}
	return (0);
}
