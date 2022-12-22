/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printformat_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yst-laur <yst-laur@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 19:34:27 by yst-laur          #+#    #+#             */
/*   Updated: 2022/01/28 19:34:30 by yst-laur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/ft_printf.h"

void	printformat(t_flags format, va_list ap, int *res)
{
	if (format.flag == 'c')
		ft_putchar(format, va_arg(ap, int), res);
	if (format.flag == 's')
		ft_putstr_bonus(format, va_arg(ap, char *), res);
	if (format.flag == 'd')
		printnumberone(format, va_arg(ap, int), res);
	if (format.flag == 'p')
		printpointer(format, va_arg(ap, void *), res);
	if (format.flag == 'i')
		printnumberone(format, va_arg(ap, int), res);
	if (format.flag == 'u')
		printunsigned(format, va_arg(ap, unsigned int), res);
	if (format.flag == 'x')
		printhex(format, va_arg(ap, unsigned int), "0123456789abcdef", res);
	if (format.flag == 'X')
		printhex(format, va_arg(ap, unsigned int), "0123456789ABCDEF", res);
	if (format.flag == '%')
		printpercent(format, res);
}
