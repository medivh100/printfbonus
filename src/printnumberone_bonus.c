/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printnumberone_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yst-laur <yst-laur@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 19:36:00 by yst-laur          #+#    #+#             */
/*   Updated: 2022/01/28 19:36:03 by yst-laur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	printnumberone(t_flags format, int n, int *res)
{
	if (format.minus == 0)
		printnumbertwo(format, n, res);
	if (format.minus == 1)
		printnumminus(format, n, res);
	if ((format.dot == 0 && format.zero == 0 && format.minus == 0)
		|| (format.zero == 1 && format.fieldwidth == 0
			&& format.minus == 0 && format.dot == 0))
		if (n < 0)
			*res += write(1, "-", 1);
	ft_putnbr_bonus(format, n, res);
	if (format.minus == 1)
		printnumminustwo(format, n, res);
}
