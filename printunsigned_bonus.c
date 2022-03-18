/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printunsigned_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yst-laur <yst-laur@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 19:39:19 by yst-laur          #+#    #+#             */
/*   Updated: 2022/01/28 19:39:22 by yst-laur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/libft.h"
#include "ft_printf_bonus.h"
#include "ft_printf.h"

void	printunsigned(t_flags format, unsigned int n, int *res)
{
	printunsignedtwo(format, n, res);
	ft_putuns_bonus(format, n, res);
	printunsminus(format, n, res);
}
