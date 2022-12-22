/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yst-laur <yst-laur@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 19:22:56 by yst-laur          #+#    #+#             */
/*   Updated: 2022/01/28 19:23:07 by yst-laur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	int		res;
	va_list	ap;

	res = 0;
	va_start(ap, s);
	strcreate(s, ap, &res);
	return (res);
}
