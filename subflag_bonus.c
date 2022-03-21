/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subflag_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yst-laur <yst-laur@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 19:40:20 by yst-laur          #+#    #+#             */
/*   Updated: 2022/01/28 19:40:22 by yst-laur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf_bonus.h"
#include "ft_printf.h"

char	**subflag(const char *s, char **str)
{
	int	iter;
	int	limit;
	int	index;

	iter = -1;
	limit = flagnum(s);
	index = 0;
	while (++iter < limit)
		str[iter] = findformat(s, str[iter], &index);
	return (str);
}
