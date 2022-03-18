/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yst-laur <yst-laur@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 19:25:36 by yst-laur          #+#    #+#             */
/*   Updated: 2022/01/28 19:25:38 by yst-laur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/libft.h"
#include "ft_printf.h"

void	ft_putptr(long long ptr, int *res)
{
	*res += write(1, "0x", 2);
	ft_putptr_base((unsigned long long) ptr, "0123456789abcdef", res);
}
