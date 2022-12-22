/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yst-laur <yst-laur@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 10:23:01 by yst-laur          #+#    #+#             */
/*   Updated: 2021/09/24 10:23:17 by yst-laur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	cd;
	char	*ptr;
	char	*ptr2;

	cd = 0;
	ptr = (char *) dst;
	ptr2 = (char *) src;
	if (dst == 0 && src == 0)
		return (NULL);
	while (cd < n)
	{
		*ptr = *ptr2;
		cd++;
		ptr++;
		ptr2++;
	}
	return ((void *) dst);
}
/*
#include <stdio.h>
#include <string.h>
int main(void)
{
	printf("%s", ((char *) ft_memcpy(((void *)0), ((void *)0), 3)));
}
*/