/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printhexminus_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yst-laur <yst-laur@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 19:34:56 by yst-laur          #+#    #+#             */
/*   Updated: 2022/01/28 19:34:59 by yst-laur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/libft.h"
#include "ft_printf_bonus.h"
#include "ft_printf.h"

void	printhexminus(t_flags format, unsigned int nbr, int *res)
{
	if (format.dot == 0 && format.fieldwidth > 0 && format.sharp == 0)
		while ((--format.fieldwidth - memsizebase(nbr)) >= 0)
			*res += write(1, " ", 1);
	if (format.dot == 0 && format.fieldwidth > 0 && format.sharp == 1)
		while ((--format.fieldwidth - memsizebase(nbr) - 2) >= 0)
			*res += write(1, " ", 1);
	if (format.dot == 1 && format.fieldwidth > 0 && format.sharp == 0
		&& (format.dotfield > memsizebaseuns(nbr)) && nbr != 0)
		while ((--format.fieldwidth - format.dotfield) >= 0)
			*res += write(1, " ", 1);
	if (format.dot == 1 && format.fieldwidth > 0 && format.sharp == 0
		&& (format.dotfield < memsizebaseuns(nbr)) && nbr != 0)
		while ((--format.fieldwidth - memsizebaseuns(nbr)) >= 0)
			*res += write(1, " ", 1);
	if (format.dot == 1 && format.fieldwidth > 0 && format.sharp == 0
		&& (format.dotfield < memsizebaseuns(nbr)) && nbr == 0)
		while ((--format.fieldwidth - format.dotfield) >= 0)
			*res += write(1, " ", 1);
	if (format.dot == 1 && format.fieldwidth > 0 && format.sharp == 1)
		while ((--format.fieldwidth - format.dotfield - memsizebase(nbr)) >= 0)
			*res += write(1, " ", 1);
}
