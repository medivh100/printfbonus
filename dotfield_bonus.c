/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dotfield_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yst-laur <yst-laur@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 19:21:42 by yst-laur          #+#    #+#             */
/*   Updated: 2022/01/28 19:21:45 by yst-laur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "ft_printf_bonus.h"
#include "ft_printf.h"

int	dotfield(const char *s)
{
	int	num;
	int	trigger;

	num = 0;
	trigger = 0;
	while (*s)
	{
		s++;
		if ((*s == '-' || *s == ' ' || *s == '.'
				|| validateflag(*s) == 1) && trigger == 1)
			break ;
		if (*s == '.')
		{
			trigger = 1;
			s++;
		}
		if ((*s >= '0' && *s <= '9') && trigger == 1)
		{
			num = num * 10;
			num += *s - 48;
		}
	}
	return (num);
}
