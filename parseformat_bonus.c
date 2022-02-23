/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseformat_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yst-laur <yst-laur@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 19:32:28 by yst-laur          #+#    #+#             */
/*   Updated: 2022/01/28 19:32:30 by yst-laur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "ft_printf_bonus.h"
#include "ft_printf.h"

void	parseformat(t_flags format, char *str, va_list *ap, int *res)
{
	format = popstructone(str, format);
	format = popstructtwo(str, format);
	printformat(format, ap, res);
}
