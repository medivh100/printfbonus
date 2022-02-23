/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stringlen_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yst-laur <yst-laur@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 19:40:08 by yst-laur          #+#    #+#             */
/*   Updated: 2022/01/28 19:40:10 by yst-laur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "ft_printf_bonus.h"
#include "ft_printf.h"

int	stringlen(const char *s, int *index)
{
	int	i;
	int	res;

	i = *index;
	res = 0;
	while (s[i])
	{
		if (s[i] == '%')
			while (validateflag(s[++i]) == 0)
				res++;
		if (validateflag(s[i]) == 1)
			break ;
		i++;
	}
	*index = i + 1;
	return (res + 1);
}
