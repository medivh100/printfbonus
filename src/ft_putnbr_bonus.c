/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yst-laur <yst-laur@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 19:25:21 by yst-laur          #+#    #+#             */
/*   Updated: 2022/01/28 19:25:24 by yst-laur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/ft_printf.h"

void	ft_putnbr_bonus(t_flags format, int n, int *res)
{
	long long	nout;

	nout = (long long) n;
	if (format.dot == 1 && format.dotfield == 0 && n == 0)
		return ;
	if (nout < 0)
		nout = -nout;
	if (nout >= 10)
	{
		ft_putnbr_bonus(format, nout / 10, res);
		nout = nout % 10;
	}
	if (nout <= 9 && nout >= 0)
		printchar((nout + 48), res);
}
