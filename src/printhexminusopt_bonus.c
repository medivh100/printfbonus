/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printhexminusopt_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yst-laur <yst-laur@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 20:20:36 by yst-laur          #+#    #+#             */
/*   Updated: 2022/01/28 20:20:39 by yst-laur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/ft_printf.h"

void	printhexminusopt(t_flags format, unsigned int nbr, char *base, int *res)
{
	if (format.dot == 1 && format.sharp == 0)
		while ((--format.dotfield - memsizebase(nbr)) >= 0)
			*res += write(1, "0", 1);
	if (format.dot == 1 && format.sharp == 1)
	{
		printox(base, res);
		while ((--format.dotfield - memsizebase(nbr)) >= 0)
			*res += write(1, "0", 1);
	}
	if (format.dot == 0 && format.sharp == 1)
		printox(base, res);
}
