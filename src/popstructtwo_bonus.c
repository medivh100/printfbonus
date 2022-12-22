/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   popstructtwo_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yst-laur <yst-laur@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 19:32:55 by yst-laur          #+#    #+#             */
/*   Updated: 2022/01/28 19:32:58 by yst-laur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/ft_printf.h"

t_flags	popstructtwo(const char *s, t_flags format)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] >= '0' && s[i] <= '9')
			format.fieldwidth = findfieldwidth(s);
		if (s[i] == '+')
			format.plus = 1;
		if (s[i] == '#')
			format.sharp = 1;
		if (s[i] == ' ')
			format.space = 1;
		if (validateflag(s[i]) == 1)
			format.flag = s[i];
		i++;
	}
	return (format);
}
