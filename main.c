#include <stdio.h>
#include "libft.h"
#include "ft_printf.h"

int	numsize(long long n)
{
	long long	i;

	i = 0;
	if (n < 0)
		i = (numsize(-n) + 1);
	if (n > 0)
		i = (numsize(n / 10) + 1);
	return (i);
}

int numsizedot(long long n)
{
	long long i;

	i = 0;
	if (n < 0)
		n = -n;
	if (n > 0)
		i = (numsize(n / 10) + 1);
	return (i);
}

int validateflag(int c)
{
    if (c != 'c' && c != 's' && c != 'd' && c != 'i' && c != 'u' 
		&& c != 'p' && c != 'x' && c != 'x' && c != 'X' && c != '%')
        return (0);
    return (1);
}

t_flags initstruct(t_flags format)
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

int	flagnum(const char *s)
{
	int count;
	int trigger;

	count = 0;
	trigger = 0;
	while (*s)
	{
		if (*s == '%' && *(s + 1) == '%')
		{
			s += 2;
			count++;
		}
		if (*s == '%')
		{
			trigger = 1;
			s++;
		}
		if (trigger == 1 && validateflag(*s) == 1)
		{
			count++;
			trigger = 0;
		}
		s++;
	}
	return (count);
}

void	printchar(int c, int *res)
{
	*res += write(1, &c, 1);
}

void	ft_putchar(t_flags format, int c, int *res)
{
	if (format.fieldwidth > 0 && format.minus == 0)
		while (--format.fieldwidth > 0)
			*res += write(1, " ", 1);
	*res += write(1, &c, 1);
	if (format.fieldwidth > 0 && format.minus == 1)
		while (--format.fieldwidth > 0)
			*res += write(1, " ", 1);
}

void	ft_putnbr_base(t_flags format, unsigned int nbr, char *base, int *res)
{	
	if (nbr < 0)
	{
		printchar('-', res);
		nbr = -nbr;
	}
	if (nbr >= 16)
	{
		ft_putnbr_base(format, nbr / 16, base, res);
		nbr = nbr % 16;
	}
	if (nbr <= 16 && nbr >= 0)
		printchar(base[nbr], res);
}

void	ft_putnbr(int n, int *res)
{
	long long nout = (long long) n;
	if (nout < 0)
		nout = -nout;
	if (nout >= 10)
	{
		ft_putnbr(nout / 10, res);
		nout = nout % 10;
	}
	if (nout <= 9 && nout >= 0)
		printchar((nout + 48), res);
}
// 0 is ignored when - is present
//+ in front of 0 padding when 0 and + used
//space in front of padding when 0 and space used
//space ignored when + is used
//minus sign in front of 0 padding when dot is used
//dot doesnt count space or sign when used
void	printnumbertwo(t_flags format, int n, int *res)
{
	int iter;

	iter = format.fieldwidth - numsize(n);
	if (format.dot == 1)
		iter = format.dotfield - numsizedot(n);
	if (format.fieldwidth > 0 && format.minus == 0 && format.zero == 0 && format.plus == 0)
		while (iter-- > 0)
			*res += write(1, " ", 1);
	if (format.fieldwidth > 0 && format.plus == 1 && format.zero == 0 && (format.space == 1 || format.space == 0))
	{
		while (iter-- > 1)
			*res += write(1, " ", 1);
		if (n >= 0)
			*res += write(1, "+", 1);
	}
	if (format.fieldwidth > 0 && format.space == 1 && format.plus == 0)
		while (iter-- > 0)
			*res += write(1, " ", 1);
	if (format.fieldwidth > 0 && format.zero == 1)
		while (iter-- > 0)
			*res += write(1, "0", 1);
	if (format.fieldwidth == 0 && format.dot == 1 && format.dotfield > 0)
		while (iter-- > 0)
			*res += write(1, "0", 1);
}

void	printnumberone(t_flags format, int n, int *res)
{
	int iter;

	iter = format.fieldwidth - numsize(n);
	if (format.plus == 1 && format.fieldwidth == 0 && format.zero == 0 && n >= 0)
		*res += write(1, "+", 1);
	if ((n < 0) && (format.dotfield > 0 || format.zero == 1))
		*res += write(1, "-", 1);
	printnumbertwo(format, n, res);
	if ((n < 0) && format.plus == 1 && format.fieldwidth != 0)
		*res += write(1, " ", 1);
	if ((n < 0) && format.dotfield == 0 && format.zero == 0)
		*res += write(1, "-", 1);
	ft_putnbr(n, res);
	if (format.fieldwidth > 0 && format.minus == 1)
		while (iter-- > 0)
			*res += write(1, " ", 1);
}

void	ft_putptr_base(t_flags format, unsigned long long nbr, char *base, int *res)
{
	if (nbr < 0)
	{
		ft_putchar(format, '-', res);
		nbr = -nbr;
	}
	if (nbr >= 16)
	{
		ft_putptr_base(format, nbr / 16, base, res);
		nbr = nbr % 16;
	}
	if (nbr <= 16 && nbr >= 0)
		ft_putchar(format, base[nbr], res);
}

void	ft_putptr(t_flags format, long long ptr, int *res)
{
	*res += write(1, "0x", 2);
	ft_putptr_base(format, (unsigned long long) ptr, "0123456789abcdef", res);
}

void	ft_putstr(t_flags format, char *s, int *res)
{
	int iter;

	iter = format.fieldwidth - ft_strlen(s);
	if (s != NULL)
	{
		if (format.fieldwidth > 0 && format.minus == 0)
			while (iter-- > 0)
				*res += write(1, " ", 1);
		if (format.dot == 1)
			*res += write(1, s, format.dotfield);
		else
			*res += write(1, s, ft_strlen(s));
		if (format.fieldwidth > 0 && format.minus == 1)
			while (iter-- > 0)
				*res += write(1, " ", 1);
	}
	else if (s == NULL)
		*res += write(1, "(null)", 6);
}

void	ft_putuns(t_flags format, unsigned int n, int *res)
{
	if (n >= 10)
	{
		ft_putuns(format, n / 10, res);
		n = n % 10;
	}
	if (n < 10)
		ft_putchar(format, (n + 48), res);
}

int		stringlen(const char *s, int *index)
{
	int i;
	int	count;

	i = *index;
	count = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			while (validateflag(s[i + 1]) == 0)
			{
				i++;
				count++;
			}
		}
		if (validateflag(s[i]) == 1)
			break ;
		i++;
	}
	*index = i + 1;
	return (count + 1);
}

char **memalloc(const char *s)
{
	char **rstr;
	int count;
	int index;
	int i;

	i = 0;
	index = 0;
	count = flagnum(s);
	rstr = malloc((count + 1) * sizeof(char *));
	while (i < count)
	{
		rstr[i] = malloc((stringlen(s, &index) + 1) * sizeof(char));
		i++;
	}
	rstr[i] = NULL;
	return (rstr);
}

char	**subflag(const char *s, char **str)
{
	int		index;
	int		i;
	int		j;

	str = memalloc(s);
	i = 0;
	j = 0;
	index = 0;
	while (s[index])
	{
		if (s[index] == '%')
		{
			while (s[index + i] != ' ')
			{
				str[j][i] = s[index + i];
				i++;
				if (s[index + i] == '%')
					break ;
			}
		i = 0;
		j++;
		}
	index++;
	}
	return (str);
}

t_flags	*flagformat(const char *s)
{
	int				i;
	int				count;
	t_flags			*format;

	format = malloc((flagnum(s)) * sizeof (t_flags));
	i = 0;
	count = flagnum(s);
	while (i < count)
	{
		format[i] = initstruct(format[i]);
		i++;
	}
	return (format);
}

int	dotfield(const char *s)
{
	int		num;
	int		trigger;

	num = 0;
	trigger = 0;
	while (*s)
	{
		s++;
		if ((*s == '-' || *s == ' ' || *s == '.' || validateflag(*s) == 1) && trigger == 1)
			break ;
		if (*s == '.')
		{
			trigger = 1;
			s++;
		}
		if ((*s >= '0' && *s <= '9') && trigger == 1)
		{
			num = num * 10;
			num += *s - 48;
		}
	}
	return (num);
}

int findfieldwidth(const char *s)
{
    int		num;
	int		trigger;

	num = 0;
	trigger = 0;
	while (*s)
	{
		if ((*s == ' ' || *s == '.' || validateflag(*s) == 1) && trigger == 1)
			break ;
		if ((*s == '%' || *s == '0' || *s == '#' || *s == ' '
			|| *s == '-') && (*(s + 1) <= '9' && *(s + 1) >= '0'))
			trigger = 1;
		if ((*s >= '0' && *s <= '9') && trigger == 1)
		{
			num = num * 10;
			num += *s - 48;
		}
		s++;
	}
	return (num);
}

t_flags popstructone(const char *s, t_flags format)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '-')
			format.minus = 1;
		if (s[i] == '0')
			format.zero = 1;
		if (s[i] == '.')
		{
			format.dot = 1;
			format.dotfield = dotfield(s);
		}
	i++;
	}
	return (format);
}

t_flags	popstructtwo(const char *s, t_flags format)
{
	while (*s)
	{
		if (*s >= 0 && *s <= 9)
			format.fieldwidth = findfieldwidth(s);
		if (*s == '+')
			format.plus = 1;
		if (*s == '#')
			format.sharp = 1;
		if (*s == ' ')
			format.space = 1;
		if (validateflag(*s) == 1)
			format.flag = *s;
		s++;
	}
	return (format);
}

void    printformat(t_flags format, va_list ap, int *count)
{
    if (format.flag == 'c')
		ft_putchar(format, va_arg(ap, int), count);
	if (format.flag == 's')
		ft_putstr(format, va_arg(ap, char *), count);
	if (format.flag == 'd')
		printnumberone(format, va_arg(ap, int), count);
	if (format.flag == 'p')
		ft_putptr(format, va_arg(ap, long long), count);
	if (format.flag == 'i')
		printnumberone(format, va_arg(ap, int), count);
	if (format.flag == 'u')
		ft_putuns(format, va_arg(ap, unsigned int), count);
	if (format.flag == 'x')
		ft_putnbr_base(format, va_arg(ap, unsigned int), "0123456789abcdef", count);
	if (format.flag == 'X')
		ft_putnbr_base(format, va_arg(ap, unsigned int), "0123456789ABCDEF", count);
	if (format.flag == '%')
		count += write(1, "%", 1);
}

void	parseformat(t_flags format, char *str, va_list ap, int *count)
{
	format = popstructone(str, format);
	format = popstructtwo(str, format);
	free(str);
	printformat(format, ap, count);
}
// "-0."
// "# +" + minfieldwidth
// 0 is ignored when - is present
//+ in front of 0 padding when 0 and + used
//space in front of padding when 0 and space used
//space ignored when + is used
//minus sign in front of 0 padding when dot is used
//dot doesnt count space or sign when used
int main(void)
{
	t_flags format;
	int		i;
	//int		*b;

	i = 0;
	//b = &i;
	format = initstruct(format);
	//format.dotfield = 5;
	//format.zero = 1;
	//format.dot = 1;
	format.plus = 1;
	//format.fieldwidth = 5;
	//format.minus = 1;
	//ft_putstr(format, "Hello", &i);

	printf("%+di\n", -1);
	printnumberone(format, -1, &i);

	//printf("%d", format.fieldwidth);
	
	return (0);
}