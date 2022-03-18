/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   popstructone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yst-laur <yst-laur@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 19:32:45 by yst-laur          #+#    #+#             */
/*   Updated: 2022/01/28 19:32:48 by yst-laur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/libft.h"
#include "ft_printf_bonus.h"
#include "ft_printf.h"

t_flags	popstructone(const char *s, t_flags format)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '-')
			format.minus = 1;
		if (s[i] == '0' && s[i - 1] != '.' && (s[i - 1] == '%'
				|| s[i - 1] == '#' || s[i - 1] == ' '
				|| s[i - 1] == '-' || s[i - 1] == '+'))
			format.zero = 1;
		if (s[i] == '.')
		{
			format.dot = 1;
			format.dotfield = dotfield(s);
		}
	i++;
	}
	return (format);
}
