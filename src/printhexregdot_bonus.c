/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printhexregdot_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yst-laur <yst-laur@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 19:35:31 by yst-laur          #+#    #+#             */
/*   Updated: 2022/01/28 19:35:34 by yst-laur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/ft_printf.h"

void	printhexregdot(t_flags format, unsigned int nbr, int *res)
{
	if (format.dotfield > memsizebase(nbr) && nbr != 0)
		while ((--format.fieldwidth - format.dotfield) >= 0)
			*res += write(1, " ", 1);
	if (format.dotfield < memsizebase(nbr) && nbr != 0)
		while ((--format.fieldwidth - memsizebase(nbr)) >= 0)
			*res += write(1, " ", 1);
	if (nbr == 0 && format.fieldwidth > format.dotfield)
		while (--format.fieldwidth >= 0)
			*res += write(1, " ", 1);
	while ((--format.dotfield - memsizebase(nbr)) >= 0)
		*res += write(1, "0", 1);
}
