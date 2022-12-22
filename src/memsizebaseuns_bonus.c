/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memsizebaseuns_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yst-laur <yst-laur@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 19:31:46 by yst-laur          #+#    #+#             */
/*   Updated: 2022/01/28 19:31:50 by yst-laur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/ft_printf.h"

int	memsizebaseuns(unsigned long long n)
{
	long long	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		i++;
		n /= 16;
	}
	return (i);
}
