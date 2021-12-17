#ifndef LIBPRINTF_H
#define LIBPRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct t_flags
{
	int		flag;
	int		fieldwidth;
	int		minus;
	int		minusfield;
	int		plus;
	int		sharp;
	int		space;
	int		zero;
	int		dot;
	int		dotfield;
} t_flags;

int     		ft_printf(const char *, ...);
void    		dispatchflag(int, va_list, int *);
void			ft_putnbr_base(unsigned int nbr, char *base, int *res);
void			ft_putnbr(int n, int *res);
void    		ft_putstr(char *s, int *);
void    		ft_putchar(int , int *);
void			ft_putptr(long long ptr, int *res);
void			ft_putuns(unsigned int n, int *res);
void			ft_putptr_base(unsigned long long nbr, char *base, int *res);
int				validateflag(int c);

t_flags		 	initstruct(t_flags);
t_flags		 	*flagformat(const char *s);
void			parseformat(t_flags format, char **str, va_list ap, int *count);
int				flagnum(const char *s);
int				stringlen(const char *s, int *index);
char 			**memalloc(const char *s);
char			**subflag(const char *s, char **str);
t_flags 		popstructone(const char *s, t_flags format);
t_flags			popstructtwo(const char *s, t_flags format);
int				minusfield(char *s);
int				dotfield(char *s);
void    		printformat(t_flags format, va_list ap, int *count);

#endif
