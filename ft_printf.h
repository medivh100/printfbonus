#ifndef LIBPRINTF_H
#define LIBPRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

struct Flags
{
	int		flag;
	int		minus;
	int		minusfield;
	int		plus;
	int		sharp;
	int		space;
	int		zero;
	int		dot;
	int		dotstring;
};

int     		ft_printf(const char *, ...);
void    		dispatchflag(int, va_list, int *);
void			ft_putnbr_base(unsigned int nbr, char *base, int *res);
void			ft_putnbr(int n, int *res);
void    		ft_putstr(char *s, int *);
void    		ft_putchar(int , int *);
void			ft_putptr(long long ptr, int *res);
void			ft_putuns(unsigned int n, int *res);
void			ft_putptr_base(unsigned long long nbr, char *base, int *res);
struct Flags 	initstruct(struct Flags);
struct Flags 	flagformat(const char *s);
void			parseformat(struct Flags format, char **str);
int				validateflag(int c);
int				flagnum(char *s);
int				stringlen(char *s, int *index);
char 			**memalloc(char *s);
char			**subflag(char *s, char **str);

#endif
