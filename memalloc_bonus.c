/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memalloc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yst-laur <yst-laur@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 19:31:19 by yst-laur          #+#    #+#             */
/*   Updated: 2022/01/28 19:31:23 by yst-laur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "ft_printf_bonus.h"
#include "ft_printf.h"

char	**memalloc(const char *s)
{
	char	**rstr;
	int		res;
	int		index;
	int		i;

	i = -1;
	index = 0;
	res = flagnum(s);
	rstr = malloc((res + 1) * sizeof(char *));
	while (++i < res)
		rstr[i] = malloc((stringlen(s, &index) + 1) * sizeof(char));
	rstr[i] = NULL;
	return (rstr);
}
