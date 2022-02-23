/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printhexsharptwo_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yst-laur <yst-laur@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 20:53:17 by yst-laur          #+#    #+#             */
/*   Updated: 2022/01/28 20:53:24 by yst-laur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "ft_printf_bonus.h"

void	printhexsharptwo(t_flags format, unsigned int nbr, char *base, int *res)
{
	if (format.dot == 0 && format.fieldwidth > 0
		&& format.minus == 0 && format.zero == 0)
	{
		while ((--format.fieldwidth - numsize(nbr) - 2) >= 0)
				*res += write(1, " ", 1);
		printox(base, res);
	}
	if (format.dot == 0 && format.fieldwidth > 0
		&& format.minus == 0 && format.zero == 1)
	{
		printox(base, res);
		while ((--format.fieldwidth - numsize(nbr) - 2) >= 0)
			*res += write(1, "0", 1);
	}
}
