/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printnumspace_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yst-laur <yst-laur@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 19:38:03 by yst-laur          #+#    #+#             */
/*   Updated: 2022/01/28 19:38:06 by yst-laur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	printnumspace(t_flags format, int n, int *res)
{
	if (format.plus == 1 || format.space == 1)
		while ((--format.fieldwidth - numsizedot(n) - 1) >= 0)
			*res += write(1, " ", 1);
	else
		while ((--format.fieldwidth - numsize(n)) >= 0)
			*res += write(1, " ", 1);
	if (format.plus == 1 && n >= 0)
		*res += write(1, "+", 1);
	if (format.space == 1 && n >= 0 && format.plus != 1)
		*res += write(1, " ", 1);
}
