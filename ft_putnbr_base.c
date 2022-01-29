/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yst-laur <yst-laur@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 19:24:35 by yst-laur          #+#    #+#             */
/*   Updated: 2022/01/28 19:24:43 by yst-laur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "ft_printf.h"

void	ft_putnbr_base(unsigned int nbr, char *base, int *res)
{	
	if (nbr < 0)
	{
		printchar('-', res);
		nbr = -nbr;
	}
	if (nbr >= 16)
	{
		ft_putnbr_base(nbr / 16, base, res);
		nbr = nbr % 16;
	}
	if (nbr <= 16 && nbr >= 0)
		printchar(base[nbr], res);
}
