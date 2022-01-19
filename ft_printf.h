#ifndef FT_PRINTF_H
#define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *, ...);
void	strcreate(const char *, va_list, int *);
int		validateflag(int c);
void	dispatchflag(int, va_list, int *);
void	ft_putnbr_base(unsigned int, char *, int *);
void	ft_putnbr(int, int *);
void	ft_putstr(char *, int *);
void	ft_putptr(long long, int *);
void	ft_putptr_base(unsigned long long, char *, int *);
void	ft_putuns(unsigned int, int *);
void	printchar(int c, int *res);

#endif
