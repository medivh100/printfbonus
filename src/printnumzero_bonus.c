/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printnumzero_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yst-laur <yst-laur@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 19:38:15 by yst-laur          #+#    #+#             */
/*   Updated: 2022/01/28 19:38:19 by yst-laur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	printnumzero(t_flags format, int n, int *res)
{
	if (format.plus == 1 && n >= 0)
				*res += write(1, "+", 1);
	if (n < 0)
		*res += write(1, "-", 1);
	if (format.space == 1 && n >= 0)
		*res += write(1, " ", 1);
	while ((--format.fieldwidth - numsizedot(n) - 1) >= 0)
		*res += write(1, "0", 1);
}
