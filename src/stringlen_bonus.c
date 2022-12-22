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
#include "../include/ft_printf.h"

int	stringlen(const char *s, int *index)
{
	int	i;
	int	res;
	int	trigger;

	i = *index;
	res = 0;
	trigger = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			trigger = 1;
			while (validateflag(s[++i]) == 0)
				res++;
		}
		if (validateflag(s[i]) == 1 && trigger == 1)
			break ;
		i++;
	}
	*index = i + 1;
	return (res + 1);
}
