/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrtwo_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yst-laur <yst-laur@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 19:28:16 by yst-laur          #+#    #+#             */
/*   Updated: 2022/01/28 19:28:21 by yst-laur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/ft_printf.h"

void	ft_putstrtwo(t_flags format, char *s, int *res)
{
	int	i;

	i = -1;
	if (format.fieldwidth > 0 && format.minus == 0 && format.dot == 0)
		while ((--format.fieldwidth - ft_strlen(s)) >= 0)
			*res += write(1, " ", 1);
	if (format.fieldwidth > 0 && format.dot == 1 && format.minus == 0)
		while ((--format.fieldwidth - ft_strlen(s) - format.dotfield) >= 0)
			*res += write(1, " ", 1);
	if (format.dot == 1)
		while ((++i < format.dotfield) && s[i] != '\0')
			*res += write(1, &s[i], 1);
	else
		*res += write(1, s, ft_strlen(s));
}
