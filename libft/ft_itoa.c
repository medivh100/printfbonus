/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yst-laur <yst-laur@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 10:28:50 by yst-laur          #+#    #+#             */
/*   Updated: 2021/09/24 10:29:21 by yst-laur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	memsize(long long n)
{
	size_t	i;

	i = 0;
	if (n < 0)
		i = (memsize(-n) + 1);
	if (n > 0)
		i = (memsize(n / 10) + 1);
	return (i);
}

static char	*negnum(long long n, char *str)
{
	size_t	max;

	max = memsize(n);
	str[max] = '\0';
	while (max > 0)
	{
		if (n < 0)
		{
			str[0] = '-';
			n = -n;
			max--;
		}
		str[max] = (n % 10) + 48;
		n = n / 10;
		max--;
	}
	return (str);
}

static char	*posnum(long long n, char *str)
{
	size_t	max;

	max = memsize(n);
	str[max] = '\0';
	while (max > 0)
	{
		str[max - 1] = (n % 10) + 48;
		n = n / 10;
		max--;
	}
	return (str);
}

char	*ft_itoa(long long n)
{
	char	*str;

	if (n == 0)
	{
		str = malloc(2 * sizeof(char));
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	str = malloc((memsize(n) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	if (n < 0)
		str = negnum(n, str);
	else
		str = posnum(n, str);
	return (str);
}
