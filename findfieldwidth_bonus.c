/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findfieldwidth_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yst-laur <yst-laur@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 19:21:55 by yst-laur          #+#    #+#             */
/*   Updated: 2022/01/28 19:22:00 by yst-laur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "ft_printf_bonus.h"
#include "ft_printf.h"

int	findfieldwidth(const char *s)
{
	int	num;
	int	trigger;

	num = 0;
	trigger = 0;
	while (*s)
	{
		if ((*s == ' ' || *s == '.' || validateflag(*s) == 1) && trigger == 1)
			break ;
		if ((*s == '%' || *s == '0' || *s == '#' || *s == ' '
				|| *s == '-' || *s == '+')
			&& (*(s + 1) <= '9' && *(s + 1) >= '1'))
			trigger = 1;
		if ((*s >= '0' && *s <= '9') && trigger == 1)
		{
			num = num * 10;
			num += *s - 48;
		}
		s++;
	}
	return (num);
}
