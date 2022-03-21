/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printpercent_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yst-laur <yst-laur@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 19:38:38 by yst-laur          #+#    #+#             */
/*   Updated: 2022/01/28 19:38:40 by yst-laur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf_bonus.h"
#include "ft_printf.h"

void	printpercent(t_flags format, int *res)
{
	if (format.fieldwidth > 0 && format.zero == 0 && format.minus == 0)
		while ((--format.fieldwidth - 1) >= 0)
			*res += write(1, " ", 1);
	if (format.fieldwidth > 0 && format.zero == 1 && format.minus == 0)
		while ((--format.fieldwidth - 1) >= 0)
			*res += write(1, "0", 1);
	*res += write(1, "%", 1);
	if (format.fieldwidth > 0 && format.minus == 1)
		while ((--format.fieldwidth - 1) >= 0)
			*res += write(1, " ", 1);
}
