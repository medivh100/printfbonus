/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yst-laur <yst-laur@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 10:23:32 by yst-laur          #+#    #+#             */
/*   Updated: 2021/09/24 10:23:37 by yst-laur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			cd;
	unsigned char	cout;
	unsigned char	*ptr;

	ptr = (unsigned char *) b;
	cout = (unsigned char) c;
	cd = 0;
	while (cd < len)
	{
		*ptr = cout;
		ptr++;
		cd++;
	}
	return (b);
}
