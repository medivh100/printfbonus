/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yst-laur <yst-laur@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 19:27:29 by yst-laur          #+#    #+#             */
/*   Updated: 2022/01/28 19:27:33 by yst-laur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/ft_printf.h"

void	ft_putstr(char *s, int *res)
{
	if (s != NULL)
		*res += write(1, s, ft_strlen(s));
	else if (s == NULL)
		*res += write(1, "(null)", 6);
}
