/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yst-laur <yst-laur@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 10:29:52 by yst-laur          #+#    #+#             */
/*   Updated: 2021/09/24 10:29:56 by yst-laur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*dptr;
	unsigned char	*sptr;

	dptr = (unsigned char *) dst;
	sptr = (unsigned char *) src;
	i = 0;
	if (!dst && !src)
		return (NULL);
	if (src > dst)
	{
		while (i++ < len)
			dptr[i - 1] = sptr[i - 1];
	}
	else
	{
		while (len-- > 0)
			dptr[len] = sptr[len];
	}
	return (dst);
}
