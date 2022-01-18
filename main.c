#include <stdio.h>
#include "libft.h"
#include "ft_printf.h"

int	memsizebase(long long n)
{
	size_t	i;

	i = 0;
	if (n < 0)
		i = (memsizebase(-n) + 1);
	if (n > 0)
		i = (memsizebase(n / 16) + 1);
	return (i);
}

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
	int res;
	int trigger;

	res = 0;
	trigger = 0;
	while (*s)
	{
		if (*s == '%' && *(s + 1) == '%' && trigger == 0)
		{
			s += 2;
			res++;
		}
		if (*s == '%' && trigger == 0)
		{
			trigger = 1;
			s++;
		}
		if (trigger == 1 && validateflag(*s) == 1)
		{
			res++;
			trigger = 0;
		}
		s++;
	}
	return (res);
}

void	printchar(int c, int *res)
{
	*res += write(1, &c, 1);
}

void	ft_putchar(t_flags format, int c, int *res)
{
	if (format.fieldwidth > 0 && format.minus == 0)
		while ((--format.fieldwidth - 1) >= 0)
			*res += write(1, " ", 1);
	*res += write(1, &c, 1);
	if (format.fieldwidth > 0 && format.minus == 1)
		while ((--format.fieldwidth - 1) >= 0)
			*res += write(1, " ", 1);
}

void	printox(char *base, int *res)
{
	*res += write(1, "0", 1);
	if (base[10] == 'a')
		*res += write(1, "x", 1);
	else
		*res += write(1, "X", 1);
}

void	printhexsharp(t_flags format, unsigned int nbr, char *base, int *res)
{
	if (format.dot == 1 && format.fieldwidth == 0)
	{
		printox(base, res);
		while ((--format.dotfield - numsize(nbr) - 2) >= 0)
			*res += write(1, "0", 1);
	}
	if (format.dot == 1 && format.fieldwidth > 0 && format.minus == 0)
	{
		while ((--format.fieldwidth - format.dotfield - numsize(nbr) - 2) >= 0)
			*res += write(1, " ", 1);
		printox(base, res);
		while (--format.dotfield - numsize(nbr) - 2)
			*res += write(1, "0", 1);
	}
	if (format.dot == 0 && format.fieldwidth > 0 && format.minus == 0 && format.zero == 0)
	{
		while ((--format.fieldwidth - numsize(nbr) - 2) >= 0)
				*res += write(1, " ", 1);
		printox(base, res);
	}
	if (format.dot == 0 && format.fieldwidth > 0 && format.minus == 0 && format.zero == 1)
	{
		printox(base, res);
		while ((--format.fieldwidth - numsize(nbr) - 2) >= 0)
			*res += write(1, "0", 1);
	}
}

void	printhexreg(t_flags format, unsigned int nbr, int *res)
{
	if (format.dot == 1 && format.fieldwidth == 0)
		while (--format.dotfield - memsizebase(nbr) >= 0)
			*res += write(1, "0", 1);
	if (format.dot == 1 && format.fieldwidth > 0)
	{
		while ((--format.fieldwidth - format.dotfield) >= 0)
			*res += write(1, " ", 1);
		while ((--format.dotfield - memsizebase(nbr)) >= 0)
			*res += write(1, "0", 1);
	}
	if (format.dot == 0 && format.fieldwidth > 0)
	{
		if (format.zero == 0)
			while ((--format.fieldwidth - memsizebase(nbr)) >= 0)
				*res += write(1, " ", 1);
		if (format.zero == 1)
			while ((--format.fieldwidth - memsizebase(nbr)) >= 0)
				*res += write(1, "0", 1);
	}
}

void	printhexminusopt(t_flags format, unsigned int nbr, char *base, int *res)
{
	if (format.dot == 1 && format.sharp == 0)
		while ((--format.dotfield - memsizebase(nbr)) >= 0)
			*res += write(1, "0", 1);
	if (format.dot == 1 && format.sharp == 1)
	{
		printox(base, res);
		while ((--format.dotfield - memsizebase(nbr)) >= 0)
			*res += write(1, "0", 1);
	}
	if (format.dot == 0 && format.sharp == 1)
		printox(base, res);
}

void	printhexminus(t_flags format, unsigned int nbr, int *res)
{
	if (format.dot == 0 && format.fieldwidth > 0 && format.sharp == 0)
		while ((--format.fieldwidth - memsizebase(nbr)) >= 0)
			*res += write(1, " ", 1);
	if (format.dot == 0 && format.fieldwidth > 0 && format.sharp == 1)
		while ((--format.fieldwidth - memsizebase(nbr) - 2) >= 0)
			*res += write(1, " ", 1);
	if (format.dot == 1 && format.fieldwidth > 0 && format.sharp == 0)
		while ((--format.fieldwidth - format.dotfield) >= 0)
			*res += write(1, " ", 1);
	if (format.dot == 1 && format.fieldwidth > 0 && format.sharp == 1)
		while ((--format.fieldwidth - format.dotfield - memsizebase(nbr)) >= 0)
			*res += write(1, " ", 1);
}

void	printhex(t_flags format, unsigned int nbr, char *base, int *res)
{
	if (format.sharp == 1 && format.minus == 0)
		printhexsharp(format, nbr, base, res);
	if (format.sharp == 0 && format.minus == 0)
		printhexreg(format, nbr, res);
	if (format.minus == 1)
		printhexminusopt(format, nbr, base, res);
	if (format.sharp == 1 && format.dot == 0 && format.fieldwidth == 0 && format.minus == 0)
		printox(base, res);
	ft_putnbr_base(nbr, base, res);
	if (format.minus == 1)
		printhexminus(format, nbr, res);
}

void	ft_putnbr_base(unsigned int nbr, char *base, int *res)
{	
	if (nbr < 0)
	{
		printchar('-', res);
		nbr = -nbr;
	}
	if (nbr >= 16)
	{
		ft_putnbr_base(nbr / 16, base, res);
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

void	printnumzero(t_flags format, int n, int *res)
{
	if (format.plus == 1 && n >= 0)
				*res += write(1, "+", 1);
	if (n < 0)
		*res += write(1, "-", 1);
	if (format.space == 1 && n >= 0)
		*res += write(1, " ", 1);
	while ((--format.fieldwidth - numsizedot(n) - 1) >= 0)
		*res += write(1, "0", 1);
}

void	printnumminus(t_flags format, int n, int *res)
{
	if (format.plus == 1 || format.space == 1)
	{
		if (format.plus == 1 && n >= 0)
			*res += write(1, "+", 1);
		if (format.space == 1 && format.plus != 1 && n >= 0)
			*res += write(1, " ", 1);
	}
	if (n < 0)
		*res += write(1, "-", 1);
	if (format.dot == 1)
		while ((--format.dotfield - numsizedot(n)) >= 0)
			*res += write(1, "0", 1);
}

void	printnumminustwo(t_flags format, int n, int *res)
{
	if (format.minus == 1 && format.fieldwidth > 0 && format.dot == 0)
	{
		if (format.plus == 0 && format.space == 0)
			while (--format.fieldwidth - numsize(n) >= 0)
				*res += write(1, " ", 1);
		if ((format.plus == 1 || format.space == 1) && n >= 0)
			while (--format.fieldwidth - numsize(n) > 0)
				*res += write(1, " ", 1);
		if ((format.plus == 1 || format.space == 1) && n < 0)
			while ((--format.fieldwidth - numsize(n)) >= 0)
				*res += write(1, " ", 1);
	}
	if (format.minus == 1 && format.fieldwidth > 0 && format.dot == 1)
	{
		if (format.plus == 0 && format.space == 0 && n >= 0)
			while ((--format.fieldwidth - format.dotfield) >= 0)
				*res += write(1, " ", 1);
		if (format.plus == 0 && format.space == 0 && n < 0)
			while ((--format.fieldwidth - format.dotfield) > 0)
				*res += write(1, " ", 1);
		if (format.plus == 1 || format.space == 1)
			while ((--format.fieldwidth - format.dotfield) > 0)
				*res += write(1, " ", 1);
	}
}

void	printnumberthree(t_flags format, int n, int *res)
{
	if (format.space == 1 || format.plus == 1)
	{
		while ((--format.fieldwidth - format.dotfield - 1) >= 0)
			*res += write(1, " ", 1);
		if (n >= 0 && format.plus == 1)
			*res += write(1, "+", 1);
		else if (n >= 0 && format.space == 1)
			*res += write(1, " ", 1);
		else if (n < 0 == (format.space == 1 || format.plus == 1))
			*res += write(1, "-", 1);
	}
	else
	{
		if (n < 0)
			while ((--format.fieldwidth - format.dotfield - 1) >= 0)
				*res += write(1, " ", 1);
		if (n < 0)
			*res += write(1, "-", 1);
		if (n > 0)
			while ((--format.fieldwidth - format.dotfield) >= 0)
				*res += write(1, " ", 1);
	}
	while ((--format.dotfield - numsizedot(n)) >= 0)
		*res += write(1, "0", 1);
}

void	printnumbertwo(t_flags format, int n, int *res)
{
		if ((format.fieldwidth > 0 || format.plus == 1 || format.space == 1) && format.zero == 0 && format.dot == 0)
		{
			if (format.plus == 1 || format.space == 1)
				while ((--format.fieldwidth - numsizedot(n) - 1) >= 0)
					*res += write(1, " ", 1);
			else
				while ((--format.fieldwidth - numsize(n)) >= 0)
					*res += write(1, " ", 1);
			if (format.plus == 1 && n >= 0)
				*res += write(1, "+", 1);
			if (format.space == 1 && n >= 0 && format.plus != 1)
				*res += write(1, " ", 1);
		}
		if (format.zero == 1 && format.fieldwidth > 0 && format.plus == 0 && format.space == 0 && format.dot == 0)
		{
			if (n < 0)
				*res += write(1, "-", 1);
			while ((--format.fieldwidth - numsize(n)) >= 0)
				*res += write(1, "0", 1);
		}
		if (format.zero == 1 && format.fieldwidth > 0 && format.dot == 0 && (format.space == 1 || format.plus == 1))
			printnumzero(format, n, res);
		if (format.dot == 1)
			printnumberthree(format, n, res);
}

void	printnumberone(t_flags format, int n, int *res)
{
	if (format.minus == 0)
		printnumbertwo(format, n, res);
	if (format.minus == 1)
		printnumminus(format, n, res);
	if ((format.dot == 0 && format.zero == 0 && format.minus == 0)
		|| (format.zero == 1 && format.fieldwidth == 0 && format.minus == 0))
		if (n < 0)
			*res += write(1, "-", 1);
	ft_putnbr(n, res);
	if (format.minus == 1)
		printnumminustwo(format, n, res);
}

char	*negnumbase(long long n, char *str)
{
	size_t	max;
	const char	*base;

	base = "0123456789abcdef";
	max = memsizebase(n);
	str[max] = '\0';
	while (max > 0)
	{
		if (n < 0)
		{
			str[0] = '-';
			n = -n;
			max--;
		}
		str[max] = base[n % 16];
		n = n / 16;
		max--;
	}
	return (str);
}

char	*posnumbase(long long n, char *str)
{
	size_t		max;
	const char	*base;

	base = "0123456789abcdef";
	max = memsizebase(n);
	str[max] = '\0';
	while (max > 0)
	{
		str[max - 1] = base[n % 16];
		n = n / 16;
		max--;
	}
	return (str);
}

char	*ft_itoa_base(long long n)
{
	char	*str;
	size_t	max;

	max = memsizebase(n);
	if (n == 0)
	{
		str = malloc(2 * sizeof(char));
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	str = malloc((memsizebase(n) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	if (n < 0)
		str = negnumbase(n, str);
	else
		str = posnumbase(n, str);
	return (str);
}

void	printpointer(t_flags format, long long ptr, int *res)
{
	char	*str;

	str = ft_itoa_base(ptr);
	if (format.fieldwidth > 0 && format.minus == 0)
		while ((--format.fieldwidth - ft_strlen(str) + 2) >= 0)
			*res += write(1, " ", 1);
	*res += write(1, "0x", 2);
	*res += write(1, str, ft_strlen(str));
	if (format.fieldwidth > 0 && format.minus == 1)
		while ((--format.fieldwidth - ft_strlen(str) - 2) >= 0)
			*res += write(1, " ", 0);
	free(str);
}

void	ft_putstr(t_flags format, char *s, int *res)
{
	if (s != NULL)
	{
		if (format.fieldwidth > 0 && format.minus == 0 && format.dot == 0)
			while ((--format.fieldwidth - ft_strlen(s)) >= 0)
				*res += write(1, " ", 1);
		if (format.fieldwidth > 0 && format.dot == 1 && format.minus == 0)
			while ((--format.fieldwidth - ft_strlen(s) - format.dotfield))
				*res += write(1, " ", 1);
		if (format.dot == 1)
			*res += write(1, s, format.dotfield);
		else
			*res += write(1, s, ft_strlen(s));
		if (format.fieldwidth > 0 && format.minus == 1)
			while ((--format.fieldwidth - ft_strlen(s)) >= 0)
				*res += write(1, " ", 1);
	}
	else if (s == NULL)
		*res += write(1, "(null)", 6);
}

void	printunsigned(t_flags format, unsigned int n, int *res)
{
	if (format.fieldwidth > 0 && format.minus == 0 && format.dot == 0)
		while ((--format.fieldwidth - numsize(n)) >= 0)
			*res += write(1, " ", 1);
	if (format.fieldwidth > 0 && format.dot == 1 && format.minus == 0)
	{
		while ((--format.fieldwidth - format.dotfield) >= 0)
			*res += write(1, " ", 1);
		while ((--format.dotfield - numsize(n)) >= 0)
			*res += write(1, "0", 1);
	}
	if (format.fieldwidth == 0 && format.dot == 1)
		while ((--format.dotfield - numsize(n)) >= 0)
			*res += write(1, "0", 1);
	if (format.dot == 1 && format.minus == 1)
		while ((--format.dotfield - numsize(n)) >= 0)
			*res += write(1, "0", 1);
	ft_putuns(n, res);
	if (format.fieldwidth > 0 && format.minus == 1 && format.dotfield == 0)
		while ((--format.fieldwidth - numsize(n)) >= 0)
			*res += write(1, " ", 1);
	if (format.fieldwidth > 0 && format.minus == 1 && format.dotfield == 1)
		while ((--format.fieldwidth - format.dotfield - numsize(n)) >= 0)
			*res += write(1, " ", 1);
}

void	ft_putuns(unsigned int n, int *res)
{
	if (n >= 10)
	{
		ft_putuns(n / 10, res);
		n = n % 10;
	}
	if (n < 10)
		printchar((n + 48), res);
}

void	printpercent(t_flags format, int *res)
{
	if (format.fieldwidth > 0 && format.zero == 0 && format.minus == 0)
		while ((--format.fieldwidth - 1) >= 0)
			*res += write(1, " ", 1);
	if (format.fieldwidth > 0 && format.zero == 1 && format.minus == 0)
		while ((--format.fieldwidth - 1) >= 0)
			*res += write(1, "0", 1);
	*res += write(1, "%", 1);
	if (format.fieldwidth > 0 && format.minus == 1)
		while ((--format.fieldwidth - 1) >= 0)
			*res += write(1, " ", 1);
}

int		stringlen(const char *s, int *index)
{
	int i;
	int	res;

	i = *index;
	res = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			while (validateflag(s[i + 1]) == 0)
			{
				i++;
				res++;
			}
		}
		if (validateflag(s[i]) == 1)
			break ;
		i++;
	}
	*index = i + 1;
	return (res + 1);
}

char **memalloc(const char *s)
{
	char **rstr;
	int res;
	int index;
	int i;

	i = 0;
	index = 0;
	res = flagnum(s);
	rstr = malloc((res + 1) * sizeof(char *));
	while (i < res)
	{
		rstr[i] = malloc((stringlen(s, &index) + 1) * sizeof(char));
		i++;
	}
	rstr[i] = NULL;
	return (rstr);
}

char	*findformat(const char *s,char *str, int *index)
{
	int j;
	int trigger;
	int	i;

	j = 0;
	trigger = 0;
	i = *index;
	while (s[i])
	{
		if (s[i] == '%')
		{
			str[j++] = '%';
			i++;
			trigger = 1;
			while (validateflag(s[i]) == 0 && trigger == 1)
				str[j++] = s[i++];
			if (validateflag(s[i]) == 1 && trigger == 1)
				str[j] = s[i];
		}
		if (validateflag(s[i]) == 1 && trigger == 1)
			break ;
		i++;
	}
	*index = i + 1;
	return (str);
}

char	**subflag(const char *s, char **str)
{
	int	iter;
	int	limit;
	int index;

	iter = -1;
	limit = flagnum(s);
	index = 0;
	while (++iter < limit)
		str[iter] = findformat(s,str[iter], &index);
	return (str);
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
			|| *s == '-' || *s == '+') && (*(s + 1) <= '9' && *(s + 1) >= '1'))
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
		if (s[i] == '0' && (s[i - 1] == '%' || s[i - 1] == '.' || s[i - 1] == '#' || s[i - 1] == ' ' || s[i - 1] == '-' || s[i - 1] == '+'))
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
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] >= '0' && s[i] <= '9')
			format.fieldwidth = findfieldwidth(s);
		if (s[i] == '+')
			format.plus = 1;
		if (s[i] == '#')
			format.sharp = 1;
		if (s[i] == ' ')
			format.space = 1;
		if (validateflag(s[i]) == 1)
			format.flag = s[i];
		i++;
	}
	return (format);
}

void    printformat(t_flags format, va_list ap, int *res)
{
    if (format.flag == 'c')
		ft_putchar(format, va_arg(ap, int), res);
	if (format.flag == 's')
		ft_putstr(format, va_arg(ap, char *), res);
	if (format.flag == 'd')
		printnumberone(format, va_arg(ap, int), res);
	if (format.flag == 'p')
		printpointer(format, va_arg(ap, long long), res);
	if (format.flag == 'i')
		printnumberone(format, va_arg(ap, int), res);
	if (format.flag == 'u')
		printunsigned(format, va_arg(ap, unsigned int), res);
	if (format.flag == 'x')
		printhex(format, va_arg(ap, unsigned int), "0123456789abcdef", res);
	if (format.flag == 'X')
		printhex(format, va_arg(ap, unsigned int), "0123456789ABCDEF", res);
	if (format.flag == '%')
		printpercent(format, res);
}

void	parseformat(t_flags format, char *str, va_list ap, int *res)
{
	format = popstructone(str, format);
	format = popstructtwo(str, format);
	printformat(format, ap, res);
}

void	printall(va_list ap, const char *s, char **formatstrings, int *res)
{
	t_flags format;
	int i;
	int j;

	i = 0;
	j = 0;
	while (s[j])
	{
		while (s[j] == '%')
		{
			format = initstruct(format);
			parseformat(format, formatstrings[i], ap, res);
			j += ft_strlen(formatstrings[i]);
			free(formatstrings[i]);
			i++;
			if (s[j] == '\0')
				break;
		}
		if (s[j] == '\0')
			break ;
		if (s[j] != '%')
			printchar(s[j], res);
		j++;
	}
}

int	ft_printf(const char *s, ...)
{
	int		res;
	va_list	ap;
	char **formatstrings;

	formatstrings = memalloc(s);
	formatstrings = subflag(s, formatstrings);
	res = 0;
	va_start(ap, s);
	printall(ap, s, formatstrings, &res);
	va_end(ap);
	return (res);
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
	//t_flags format;
	int		i;
	// int		*b;
	//unsigned int b = 232;

	//format.fieldwidth = 5;

	i = 0;


	printf("%di\n", -22);
	ft_printf("%di", -22);
	printf("\n\n");

	printf("%+di\n", -22);
	ft_printf("%+di", -22);
	printf("\n\n");

	printf("% di\n", -22);
	ft_printf("% di", -22);
	printf("\n\n");

	printf("%+10di\n", -22);
	ft_printf("%+10di", -22);
	printf("\n\n");

	printf("% 10di\n", -22);
	ft_printf("% 10di", -22);
	printf("\n\n");

	printf("%0di\n", -22);
	ft_printf("%0di", -22);
	printf("\n\n");

	printf("%010di\n", -22);
	ft_printf("%010di", -22);
	printf("\n\n");

	printf("%+010di\n", -22);
	ft_printf("%+010di", -22);
	printf("\n\n");

	printf("%+ 10di\n", -22);
	ft_printf("%+ 10di", -22);
	printf("\n\n");

	printf("%.10di\n", -22);
	ft_printf("%.10di", -22);
	printf("\n\n");

	printf("%+.10di\n", -22);
	ft_printf("%+.10di", -22);
	printf("\n\n");

	printf("% .10di\n", -22);
	ft_printf("% .10di", -22);
	printf("\n\n");

	printf("%15.10di\n", -22);
	ft_printf("%15.10di", -22);
	printf("\n\n");

	printf("%+15.10di\n", -22);
	ft_printf("%+15.10di", -22);
	printf("\n\n");

	printf("% 15.10di\n", -22);
	ft_printf("% 15.10di", -22);
	printf("\n\n");

	printf("%di\n", 22);
	ft_printf("%di", 22);
	printf("\n\n");

	printf("%+di\n", 22);
	ft_printf("%+di", 22);
	printf("\n\n");

	printf("% di\n", 22);
	ft_printf("% di", 22);
	printf("\n\n");

	printf("%+10di\n", 22);
	ft_printf("%+10di", 22);
	printf("\n\n");

	printf("% 10di\n", 22);
	ft_printf("% 10di", 22);
	printf("\n\n");

	printf("%0di\n", 22);
	ft_printf("%0di", 22);
	printf("\n\n");

	printf("%010di\n", 22);
	ft_printf("%010di", 22);
	printf("\n\n");

	printf("%+010di\n", 22);
	ft_printf("%+010di", 22);
	printf("\n\n");

	printf("%+ 10di\n", 22);
	ft_printf("%+ 10di", 22);
	printf("\n\n");

	printf("%.10di\n", 22);
	ft_printf("%.10di", 22);
	printf("\n\n");

	printf("%+.10di\n", 22);
	ft_printf("%+.10di", 22);
	printf("\n\n");

	printf("% .10di\n", 22);
	ft_printf("% .10di", 22);
	printf("\n\n");

	printf("%15.10di\n", 22);
	ft_printf("%15.10di", 22);
	printf("\n\n");

// Minus testing with negative int starts here 
	printf("%-15di\n", -22);
	ft_printf("%-15d1", -22);
	printf("\n\n");

	printf("%+-15di\n", 22);
	ft_printf("%+-15d2", 22);
	printf("\n\n");

	printf("%- 15di\n", 22);
	ft_printf("%- 15d3", 22);
	printf("\n\n");

	printf("%-+ 15di\n", 22);
	ft_printf("%-+ 15d4", 22);
	printf("\n\n");

	printf("%-15.10di\n", -22);
	ft_printf("%-15.10d5", -22);
	printf("\n\n");

	printf("%-+15.10di\n", -22);
	ft_printf("%-+15.10d6", -22);
	printf("\n\n");

	printf("%- 15.10di\n", -22);
	ft_printf("%- 15.10d7", -22);
	printf("\n\n");

	printf("%-+015.10di\n", -22);
	ft_printf("%-+015.10d8", -22);
	printf("\n\n");

	printf("%-015.10di\n", -22);
	ft_printf("%-015.10d9", -22);
	printf("\n\n");

	printf("%-015di\n", -22);
	ft_printf("%-015d10", -22);
	printf("\n\n");

	printf("%-0.15di\n", -22);
	ft_printf("%-.15d11", -22);
	printf("\n\n");

//Minus testing with positive int starts here

	printf("%-15di\n", 22);
	ft_printf("%-15d1", 22);
	printf("\n\n");

	printf("%+-15di\n", 22);
	ft_printf("%+-15d2", 22);
	printf("\n\n");

	printf("%- 15di\n", 22);
	ft_printf("%- 15d3", 22);
	printf("\n\n");

	printf("%-+ 15di\n", 22);
	ft_printf("%-+ 15d4", 22);
	printf("\n\n");

	printf("%-15.10di\n", 22);
	ft_printf("%-15.10d5", 22);
	printf("\n\n");

	printf("%-+15.10di\n", 22);
	ft_printf("%-+15.10d6", 22);
	printf("\n\n");

	printf("%- 15.10di\n", 22);
	ft_printf("%- 15.10d7", 22);
	printf("\n\n");

	printf("%-+015.10di\n", 22);
	ft_printf("%-+015.10d8", 22);
	printf("\n\n");

	printf("%-015.10di\n", 22);
	ft_printf("%-015.10d9", 22);
	printf("\n\n");

	printf("%-015di\n", 22);
	ft_printf("%-015d10", 22);
	printf("\n\n");

	printf("%-0.15di\n", 22);
	ft_printf("%-.15d11", 22);
	printf("\n\n");

	//printunsigned(format, b, &i);

	//printnumberone(format, -1, &i);

	//printf("%d", format.fieldwidth);
	
	return (0);
}
