/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatchflag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yst-laur <yst-laur@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 19:21:15 by yst-laur          #+#    #+#             */
/*   Updated: 2022/01/28 19:21:24 by yst-laur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/libft.h"
#include "ft_printf.h"

void	dispatchflag(int c, va_list ap, int *res)
{
	if (c == 'c')
		printchar(va_arg(ap, int), res);
	if (c == 's')
		ft_putstr(va_arg(ap, char *), res);
	if (c == 'd')
		ft_putnbr(va_arg(ap, int), res);
	if (c == 'p')
		ft_putptr(va_arg(ap, long long), res);
	if (c == 'i')
		ft_putnbr(va_arg(ap, int), res);
	if (c == 'u')
		ft_putuns(va_arg(ap, unsigned int), res);
	if (c == 'x')
		ft_putnbr_base(va_arg(ap, unsigned int), "0123456789abcdef", res);
	if (c == 'X')
		ft_putnbr_base(va_arg(ap, unsigned int), "0123456789ABCDEF", res);
	if (c == '%')
		*res += write(1, "%", 1);
}
