/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuns.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yst-laur <yst-laur@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 19:28:33 by yst-laur          #+#    #+#             */
/*   Updated: 2022/01/28 19:28:37 by yst-laur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/ft_printf.h"

void	ft_putuns(unsigned int n, int *res)
{
	if (n >= 10)
	{
		ft_putuns(n / 10, res);
		n = n % 10;
	}
	if (n < 10)
		printchar((n + 48), res);
}
