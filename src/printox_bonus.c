/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printox_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yst-laur <yst-laur@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 19:38:28 by yst-laur          #+#    #+#             */
/*   Updated: 2022/01/28 19:38:31 by yst-laur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/ft_printf.h"

void	printox(char *base, int *res)
{
	*res += write(1, "0", 1);
	if (base[10] == 'a')
		*res += write(1, "x", 1);
	else
		*res += write(1, "X", 1);
}
