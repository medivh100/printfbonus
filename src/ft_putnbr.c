/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yst-laur <yst-laur@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 19:24:17 by yst-laur          #+#    #+#             */
/*   Updated: 2022/01/28 19:24:21 by yst-laur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/ft_printf.h"

void	ft_putnbr(int n, int *res)
{
	long long	nout;

	nout = (long long) n;
	if (nout < 0)
	{
		printchar('-', res);
		nout = -nout;
	}
	if (nout >= 10)
	{
		ft_putnbr(nout / 10, res);
		nout = nout % 10;
	}
	if (nout <= 9 && nout >= 0)
		printchar((nout + 48), res);
}
