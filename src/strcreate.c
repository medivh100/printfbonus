/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcreate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yst-laur <yst-laur@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 19:39:55 by yst-laur          #+#    #+#             */
/*   Updated: 2022/01/28 19:39:59 by yst-laur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	strcreate(const char *s, va_list ap, int *res)
{
	while (*s)
	{
		while (*s == '%' && validateflag(*(s + 1)) == 1)
		{
			dispatchflag(*(s + 1), ap, res);
			s += 2;
			if (*s == '\0')
				break ;
		}
		if (*s == '\0')
			break ;
		printchar(*s, res);
		s++;
	}
}
