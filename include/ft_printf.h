/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yst-laur <yst-laur@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 19:23:20 by yst-laur          #+#    #+#             */
/*   Updated: 2022/01/28 19:23:24 by yst-laur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft/libft.h"
# include "ft_printf_bonus.h"

int		ft_printf(const char *s, ...);
void	strcreate(const char *s, va_list ap, int *res);
int		validateflag(int c);
void	dispatchflag(int c, va_list ap, int *res);
void	ft_putnbr_base(unsigned int n, char *base, int *res);
void	ft_putnbr(int n, int *res);
void	ft_putstr(char *s, int *res);
void	ft_putptr(long long ptr, int *res);
void	ft_putptr_base(unsigned long long nbr, char *base, int *res);
void	ft_putuns(unsigned int n, int *res);
void	printchar(int c, int *res);

#endif
