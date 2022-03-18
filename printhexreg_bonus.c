/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printhexreg_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yst-laur <yst-laur@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 19:35:15 by yst-laur          #+#    #+#             */
/*   Updated: 2022/01/28 19:35:19 by yst-laur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/libft.h"
#include "ft_printf_bonus.h"
#include "ft_printf.h"

void	printhexreg(t_flags format, unsigned int nbr, int *res)
{
	if (format.dot == 1 && format.fieldwidth == 0)
		while (--format.dotfield - memsizebase(nbr) >= 0)
			*res += write(1, "0", 1);
	if (format.dot == 1 && format.fieldwidth > 0)
		printhexregdot(format, nbr, res);
	if (format.dot == 0 && format.fieldwidth > 0)
	{
		if (format.zero == 0)
			while ((--format.fieldwidth - memsizebase(nbr)) >= 0)
				*res += write(1, " ", 1);
		if (format.zero == 1)
			while ((--format.fieldwidth - memsizebase(nbr)) >= 0)
				*res += write(1, "0", 1);
	}
}
