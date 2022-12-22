/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuns_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yst-laur <yst-laur@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 19:28:43 by yst-laur          #+#    #+#             */
/*   Updated: 2022/01/28 19:28:46 by yst-laur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_putuns_bonus(t_flags format, unsigned int n, int *res)
{
	if (n == 0 && format.dot == 1 && format.dotfield == 0)
		return ;
	if (n >= 10)
	{
		ft_putuns_bonus(format, n / 10, res);
		n = n % 10;
	}
	if (n < 10)
		printchar((n + 48), res);
}
