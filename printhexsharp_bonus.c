/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printhexsharp_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yst-laur <yst-laur@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 19:35:43 by yst-laur          #+#    #+#             */
/*   Updated: 2022/01/28 19:35:46 by yst-laur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/libft.h"
#include "ft_printf_bonus.h"
#include "ft_printf.h"

void	printhexsharp(t_flags format, unsigned int nbr, char *base, int *res)
{
	if (format.dot == 1 && format.fieldwidth == 0)
	{
		printox(base, res);
		while ((--format.dotfield - numsize(nbr) - 2) >= 0)
			*res += write(1, "0", 1);
	}
	if (format.dot == 1 && format.fieldwidth > 0 && format.minus == 0)
	{
		while ((--format.fieldwidth - format.dotfield - numsize(nbr) - 2) >= 0)
			*res += write(1, " ", 1);
		printox(base, res);
		while (--format.dotfield - numsize(nbr) - 2)
			*res += write(1, "0", 1);
	}
	printhexsharptwo(format, nbr, base, res);
}
