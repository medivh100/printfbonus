/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printunsignedtwo_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yst-laur <yst-laur@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 19:39:30 by yst-laur          #+#    #+#             */
/*   Updated: 2022/01/28 19:39:32 by yst-laur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/ft_printf.h"

void	printunsignedtwo(t_flags format, unsigned int n, int *res)
{
	if (format.fieldwidth > 0 && format.minus == 0
		&& format.dot == 0 && format.zero == 0)
		while ((--format.fieldwidth - numsize(n)) >= 0)
			*res += write(1, " ", 1);
	if (format.fieldwidth > 0 && format.minus == 0
		&& format.dot == 0 && format.zero == 1)
		while ((--format.fieldwidth - numsize(n)) >= 0)
			*res += write(1, "0", 1);
	if (format.fieldwidth > 0 && format.dot == 1 && format.minus == 0)
		printunsdot(format, n, res);
	if (format.fieldwidth == 0 && format.dot == 1)
		while ((--format.dotfield - numsize(n)) >= 0)
			*res += write(1, "0", 1);
	if (format.dot == 1 && format.minus == 1 && format.dotfield > 0)
		while ((--format.dotfield - numsize(n)) >= 0)
			*res += write(1, "0", 1);
}
