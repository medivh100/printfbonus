/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printpointer_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yst-laur <yst-laur@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 19:38:49 by yst-laur          #+#    #+#             */
/*   Updated: 2022/01/28 19:38:55 by yst-laur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/ft_printf.h"

void	printpointer(t_flags format, void *ptr, int *res)
{
	char	*str;

	str = ft_itoa_base((unsigned long long) ptr);
	if (format.fieldwidth > 0 && format.minus == 0)
		while ((--format.fieldwidth - ft_strlen(str) - 2) >= 0)
			*res += write(1, " ", 1);
	*res += write(1, "0x", 2);
	*res += write(1, str, ft_strlen(str));
	if (format.fieldwidth > 0 && format.minus == 1)
		while ((--format.fieldwidth - ft_strlen(str) - 2) >= 0)
			*res += write(1, " ", 1);
	free(str);
}
