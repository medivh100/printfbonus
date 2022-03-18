/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printnumsign_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yst-laur <yst-laur@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 19:37:53 by yst-laur          #+#    #+#             */
/*   Updated: 2022/01/28 19:37:55 by yst-laur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/libft.h"
#include "ft_printf_bonus.h"

void	printnumsign(t_flags format, int n, int *res)
{
	while ((--format.fieldwidth - format.dotfield - 1) >= 0)
		*res += write(1, " ", 1);
	if (n >= 0 && format.plus == 1)
		*res += write(1, "+", 1);
	else if (n >= 0 && format.space == 1)
		*res += write(1, " ", 1);
	else if (n < 0 && (format.space == 1 || format.plus == 1))
		*res += write(1, "-", 1);
}
