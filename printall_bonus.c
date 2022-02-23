/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printall_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yst-laur <yst-laur@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 19:33:42 by yst-laur          #+#    #+#             */
/*   Updated: 2022/01/28 19:33:46 by yst-laur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "ft_printf_bonus.h"
#include "ft_printf.h"

void	printall(va_list *ap, const char *s, char **formatstrings, int *res)
{
	t_flags	format;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[j])
	{
		while (s[j] == '%')
		{
			format = initstruct(format);
			parseformat(format, formatstrings[i], ap, res);
			j += ft_strlen(formatstrings[i]);
			free(formatstrings[i]);
			i++;
			if (s[j] == '\0')
				break ;
		}
		if (s[j] == '\0')
			break ;
		if (s[j] != '%')
			printchar(s[j], res);
		j++;
	}
}
