/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printnumminus_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yst-laur <yst-laur@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 19:36:50 by yst-laur          #+#    #+#             */
/*   Updated: 2022/01/28 19:36:53 by yst-laur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf_bonus.h"
#include "ft_printf.h"

void	printnumminus(t_flags format, int n, int *res)
{
	if (format.plus == 1 || format.space == 1)
	{
		if (format.plus == 1 && n >= 0)
			*res += write(1, "+", 1);
		if (format.space == 1 && format.plus != 1 && n >= 0)
			*res += write(1, " ", 1);
	}
	if (n < 0)
		*res += write(1, "-", 1);
	if (format.dot == 1)
		while ((--format.dotfield - numsizedot(n)) >= 0)
			*res += write(1, "0", 1);
}
