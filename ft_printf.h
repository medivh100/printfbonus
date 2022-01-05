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
	int		plus;
	int		sharp;
	int		space;
	int		zero;
	int		dot;
	int		dotfield;
} t_flags;

int     		ft_printf(const char *, ...);
void			ft_putnbr_base(t_flags format, unsigned int nbr, char *base, int *res);
void			ft_putnbr(int n, int *res);
void    		ft_putstr(t_flags format, char *s, int *);
void    		ft_putchar(t_flags format, int , int *);
void			ft_putptr(t_flags format, long long ptr, int *res);
void			ft_putuns(t_flags format, unsigned int n, int *res);
void			ft_putptr_base(t_flags format, unsigned long long nbr, char *base, int *res);
int				validateflag(int c);

t_flags		 	initstruct(t_flags);
void			parseformat(t_flags format, char *str, va_list ap, int *count);
int				flagnum(const char *s);
int				stringlen(const char *s, int *index);
char 			**memalloc(const char *s);
char			**subflag(const char *s, char **str);
t_flags 		popstructone(const char *s, t_flags format);
t_flags			popstructtwo(const char *s, t_flags format);
int				minusfield(char *s);
int				dotfield(const char *s);
void    		printformat(t_flags format, va_list ap, int *res);
void			printchar(int c, int *res);
void			printnumberone(t_flags format, int n, int *res);
void			printnumbertwo(t_flags format, int n, int *res);
int 			numsizedot(long long n);
void			printpointer(t_flags format, long long ptr, int *res);
char			*ft_itoa_base(long long n);
static char		*posnumbase(long long n, char *str);
static char		*negnumbase(long long n, char *str);
static size_t	memsizebase(long long n);

#endif
