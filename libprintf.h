#ifndef LIBPRINTF_H
#define LIBPRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int     ft_printf(const char *, ...);

void    strcreate(const char *, va_list, int *);

int     validateflag(int);

void    dispatchflag(int, va_list *, int *);

void	ft_putnbr_base(long long int, char *, int *);

void	ft_putnbr(long long n, int *);

void    ft_putstr(char *s, int *);

void    ft_putchar(int , int *);

void    ft_putptr(void *, int *);

void    ft_putuns(unsigned long long, int *);

#endif
