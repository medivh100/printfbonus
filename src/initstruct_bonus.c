/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initstruct_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yst-laur <yst-laur@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 19:28:54 by yst-laur          #+#    #+#             */
/*   Updated: 2022/01/28 19:28:57 by yst-laur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/ft_printf.h"

t_flags	initstruct(t_flags format)
{
	format.dot = 0;
	format.dotfield = 0;
	format.flag = 0;
	format.minus = 0;
	format.plus = 0;
	format.sharp = 0;
	format.space = 0;
	format.zero = 0;
	format.fieldwidth = 0;
	return (format);
}
