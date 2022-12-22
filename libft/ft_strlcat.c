/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yst-laur <yst-laur@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 10:25:30 by yst-laur          #+#    #+#             */
/*   Updated: 2021/09/24 10:25:34 by yst-laur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	start;

	start = ft_strlen(dst);
	if (start + 1 > dstsize)
		return (ft_strlen(src) + dstsize);
	while (*src && start < (dstsize - 1))
	{
		dst[start] = *src;
		src++;
		start++;
	}
	dst[start] = '\0';
	return (ft_strlen(dst) + ft_strlen(src));
}
