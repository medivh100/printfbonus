/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printunsdot_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yst-laur <yst-laur@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 19:39:04 by yst-laur          #+#    #+#             */
/*   Updated: 2022/01/28 19:39:06 by yst-laur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf_bonus.h"

void	printunsdot(t_flags format, unsigned int n, int *res)
{
	if (format.dotfield > numsize(n) && n != 0)
		while ((--format.fieldwidth - format.dotfield) >= 0)
			*res += write(1, " ", 1);
	else if (format.dotfield < numsize(n) && n != 0)
		while ((--format.fieldwidth - numsize(n)) >= 0)
			*res += write(1, " ", 1);
	else if (n == 0 && format.fieldwidth > format.dotfield)
		while (--format.fieldwidth >= 0)
			*res += write(1, " ", 1);
	while ((--format.dotfield - numsize(n)) >= 0)
		*res += write(1, "0", 1);
}
