/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printnumminustwo_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yst-laur <yst-laur@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 19:37:28 by yst-laur          #+#    #+#             */
/*   Updated: 2022/01/28 19:37:30 by yst-laur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/libft.h"
#include "ft_printf_bonus.h"
#include "ft_printf.h"

void	printnumminustwo(t_flags format, int n, int *res)
{
	if (format.minus == 1 && format.fieldwidth > 0 && format.dot == 0)
	{
		if (format.plus == 0 && format.space == 0)
			while (--format.fieldwidth - numsize(n) >= 0)
				*res += write(1, " ", 1);
		if ((format.plus == 1 || format.space == 1) && n >= 0)
			while (--format.fieldwidth - numsize(n) > 0)
				*res += write(1, " ", 1);
		if ((format.plus == 1 || format.space == 1) && n < 0)
			while ((--format.fieldwidth - numsize(n)) >= 0)
				*res += write(1, " ", 1);
	}
	if (format.minus == 1 && format.fieldwidth > 0 && format.dot == 1)
		printnumminusthree(format, n, res);
}
