/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printhex_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yst-laur <yst-laur@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 19:34:46 by yst-laur          #+#    #+#             */
/*   Updated: 2022/01/28 19:34:49 by yst-laur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf_bonus.h"
#include "ft_printf.h"

void	printhex(t_flags format, unsigned int nbr, char *base, int *res)
{
	if (format.sharp == 1 && format.minus == 0)
		printhexsharp(format, nbr, base, res);
	if (format.sharp == 0 && format.minus == 0)
		printhexreg(format, nbr, res);
	if (format.minus == 1)
		printhexminusopt(format, nbr, base, res);
	if (format.sharp == 1 && format.dot == 0
		&& format.fieldwidth == 0 && format.minus == 0 && nbr != 0)
		printox(base, res);
	ft_putnbr_base_bonus(format, nbr, base, res);
	if (format.minus == 1)
		printhexminus(format, nbr, res);
}
