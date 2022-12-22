/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numsizedot_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yst-laur <yst-laur@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 19:32:13 by yst-laur          #+#    #+#             */
/*   Updated: 2022/01/28 19:32:15 by yst-laur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/ft_printf.h"

int	numsizedot(long long n)
{
	long long	i;

	i = 0;
	if (n < 0)
		n = -n;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}
