/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yst-laur <yst-laur@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 19:23:36 by yst-laur          #+#    #+#             */
/*   Updated: 2022/01/28 19:23:39 by yst-laur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "ft_printf_bonus.h"
#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	int		res;
	va_list	ap;
	char	**formatstrings;
	int		i;

	formatstrings = memalloc(s);
	formatstrings = subflag(s, formatstrings);
	res = 0;
	i = -1;
	va_start(ap, s);
	printall(ap, s, formatstrings, &res);
	while (formatstrings[++i])
		free(formatstrings[i]);
	free(formatstrings);
	va_end(ap);
	return (res);
}
