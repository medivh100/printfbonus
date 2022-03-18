/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yst-laur <yst-laur@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 19:25:07 by yst-laur          #+#    #+#             */
/*   Updated: 2022/01/28 19:25:10 by yst-laur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/libft.h"
#include "ft_printf.h"
#include "ft_printf_bonus.h"

void	ft_putnbr_base_bonus(t_flags format, unsigned int nbr,
			char *base, int *res)
{	
	if (nbr == 0 && format.dot == 1 && format.dotfield == 0)
		return ;
	if (nbr >= 16)
	{
		ft_putnbr_base(nbr / 16, base, res);
		nbr = nbr % 16;
	}
	if (nbr <= 16)
		printchar(base[nbr], res);
}
