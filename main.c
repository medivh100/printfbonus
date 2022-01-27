#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include "ft_printf_bonus.h"

int validateflag(int c)
{
    if (c != 'c' && c != 's' && c != 'd' && c != 'i' && c != 'u' 
		&& c != 'p' && c != 'x' && c != 'x' && c != 'X' && c != '%')
        return (0);
    return (1);
}

int	memsizebase(long long n)
{
	long long	i;

	i = 0;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	if (n == 0)
		return (1);
	while (n != 0)
	{
		i++;
		n /= 16;
	}
	return (i);
}

int	numsize(long long n)
{
	long long	i;

	i = 0;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	if (n == 0)
		return (1);
	while (n != 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

int	numsizedot(long long n)
{
	long long	i;

	i = 0;
	if (n < 0)
		n = -n;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

int	memsizebaseuns(unsigned long long n)
{
	long long	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		i++;
		n /= 16;
	}
	return (i);
}

int	dotfield(const char *s)
{
	int	num;
	int	trigger;

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

int findfieldwidth(const char *s)
{
    int	num;
	int	trigger;

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

char	*findformat(const char *s,char *str, int *index)
{
	int	j;
	int	trigger;
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

int	flagnum(const char *s)
{
	int	res;
	int	trigger;

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

static char	*posnumbase(unsigned long long n, char *str)
{
	size_t		max;
	const char	*base;

	base = "0123456789abcdef";
	max = memsizebaseuns(n);
	str[max] = '\0';
	while (max > 0)
	{
		str[max - 1] = base[n % 16];
		n = n / 16;
		max--;
	}
	return (str);
}

char	*ft_itoa_base(unsigned long long n)
{
	char	*str;
	size_t	max;

	max = memsizebaseuns(n);
	if (n == 0)
	{
		str = malloc(2 * sizeof(char));
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	str = malloc((max + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	else
		str = posnumbase(n, str);
	return (str);
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

void	ft_putnbr_base_bonus(t_flags format, unsigned int nbr, char *base, int *res)
{	
	if (nbr == 0 && format.dot == 1 && format.dotfield == 0)
		return ;
	if (nbr >= 16)
	{
		ft_putnbr_base(nbr / 16, base, res);
		nbr = nbr % 16;
	}
	if (nbr <= 16 && nbr >= 0)
		printchar(base[nbr], res);
}

void	ft_putnbr_bonus(t_flags format, int n, int *res)
{
	long long	nout;

	nout = (long long) n;
	if (format.dot == 1 && format.dotfield == 0 && n == 0)
		return ;
	if (nout < 0)
		nout = -nout;
	if (nout >= 10)
	{
		ft_putnbr_bonus(format, nout / 10, res);
		nout = nout % 10;
	}
	if (nout <= 9 && nout >= 0)
		printchar((nout + 48), res);
}

void	ft_putstrnull(t_flags format, int *res)
{
	if (format.fieldwidth > 0 && format.minus == 0)
			while ((--format.fieldwidth - 6) >= 0)
				*res += write(1, " ", 1);
	if (format.dot == 0 || (format.dot == 1 && format.dotfield > 6))
		*res += write(1, "(null)", 6);
	if (format.dot == 1 && format.dotfield <= 6)
		*res += write(1, "(null)", format.dotfield);
	if (format.fieldwidth > 0 && format.minus == 1)
		while ((--format.fieldwidth - 6) >= 0)
			*res += write(1, " ", 1);
}

void	ft_putstrtwo(t_flags format, char *s, int *res)
{
	int i;

	i = -1;
	if (format.fieldwidth > 0 && format.minus == 0 && format.dot == 0)
			while ((--format.fieldwidth - ft_strlen(s)) >= 0)
				*res += write(1, " ", 1);
		if (format.fieldwidth > 0 && format.dot == 1 && format.minus == 0)
			while ((--format.fieldwidth - ft_strlen(s) - format.dotfield) >= 0)
				*res += write(1, " ", 1);
		if (format.dot == 1)
			while ((++i < format.dotfield) && s[i] != '\0')
				*res += write(1, &s[i], 1);
		else
			*res += write(1, s, ft_strlen(s));
}

void	ft_putuns_bonus(t_flags format, unsigned int n, int *res)
{
	if (n == 0 && format.dot == 1 && format.dotfield == 0)
		return ;
	if (n >= 10)
	{
		ft_putuns_bonus(format, n / 10, res);
		n = n % 10;
	}
	if (n < 10)
		printchar((n + 48), res);
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

t_flags	popstructone(const char *s, t_flags format)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '-')
			format.minus = 1;
		if (s[i] == '0' && s[i - 1] != '.' && (s[i - 1] == '%' || s[i - 1] == '#' || s[i - 1] == ' ' || s[i - 1] == '-' || s[i - 1] == '+'))
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

void	ft_putstr_bonus(t_flags format, char *s, int *res)
{
	int i;

	i = -1;
	if (s == NULL)
		ft_putstrnull(format, res);
	else if (s != NULL)
	{
		ft_putstrtwo(format, s, res);
		if (format.fieldwidth > 0 && format.minus == 1 && format.dot == 0)
			while ((--format.fieldwidth - ft_strlen(s)) >= 0)
				*res += write(1, " ", 1);
		if (format.fieldwidth > 0 && format.minus == 1 && format.dot == 1 && format.dotfield < ft_strlen(s))
			while ((--format.fieldwidth - format.dotfield) >= 0)
				*res += write(1, " ", 1);
		if (format.fieldwidth > 0 && format.minus == 1 && format.dot == 1 && format.dotfield >= ft_strlen(s))
			while ((--format.fieldwidth - ft_strlen(s)) >= 0)
				*res += write(1, " ", 1);
	}
}

void	printhex(t_flags format, unsigned int nbr, char *base, int *res)
{
	if (format.sharp == 1 && format.minus == 0)
		printhexsharp(format, nbr, base, res);
	if (format.sharp == 0 && format.minus == 0)
		printhexreg(format, nbr, res);
	if (format.minus == 1)
		printhexminusopt(format, nbr, base, res);
	if (format.sharp == 1 && format.dot == 0 && format.fieldwidth == 0 && format.minus == 0 && nbr != 0)
		printox(base, res);
	ft_putnbr_base_bonus(format, nbr, base, res);
	if (format.minus == 1)
		printhexminus(format, nbr, res);
}

void	printhexminus(t_flags format, unsigned int nbr, int *res)
{
	if (format.dot == 0 && format.fieldwidth > 0 && format.sharp == 0)
		while ((--format.fieldwidth - memsizebase(nbr)) >= 0)
			*res += write(1, " ", 1);
	if (format.dot == 0 && format.fieldwidth > 0 && format.sharp == 1)
		while ((--format.fieldwidth - memsizebase(nbr) - 2) >= 0)
			*res += write(1, " ", 1);
	if (format.dot == 1 && format.fieldwidth > 0 && format.sharp == 0 && (format.dotfield > memsizebaseuns(nbr)) && nbr != 0)
		while ((--format.fieldwidth - format.dotfield) >= 0)
			*res += write(1, " ", 1);
	if (format.dot == 1 && format.fieldwidth > 0 && format.sharp == 0 && (format.dotfield < memsizebaseuns(nbr)) && nbr != 0)
		while ((--format.fieldwidth - memsizebaseuns(nbr)) >= 0)
			*res += write(1, " ", 1);
	if (format.dot == 1 && format.fieldwidth > 0 && format.sharp == 0 && (format.dotfield  < memsizebaseuns(nbr)) && nbr == 0)
		while ((--format.fieldwidth - format.dotfield) >= 0)
			*res += write(1, " ", 1);
	if (format.dot == 1 && format.fieldwidth > 0 && format.sharp == 1)
		while ((--format.fieldwidth - format.dotfield - memsizebase(nbr)) >= 0)
			*res += write(1, " ", 1);
}

void	printhexreg(t_flags format, unsigned int nbr, int *res)
{
	if (format.dot == 1 && format.fieldwidth == 0)
		while (--format.dotfield - memsizebase(nbr) >= 0)
			*res += write(1, "0", 1);
	if (format.dot == 1 && format.fieldwidth > 0)
		printhexregdot(format, nbr, res);
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

void	printhexregdot(t_flags format, unsigned int nbr, int *res)
{
	if (format.dotfield > memsizebase(nbr) && nbr != 0)
		while ((--format.fieldwidth - format.dotfield) >= 0)
			*res += write(1, " ", 1);
	if (format.dotfield < memsizebase(nbr) && nbr != 0)
		while ((--format.fieldwidth - memsizebase(nbr)) >= 0)
			*res += write(1, " ", 1);
	if (nbr == 0 && format.fieldwidth > format.dotfield)
		while (--format.fieldwidth >= 0)
			*res += write(1, " ", 1);
	while ((--format.dotfield - memsizebase(nbr)) >= 0)
		*res += write(1, "0", 1);
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

void	printunsminus(t_flags format, unsigned int n, int *res)
{
	if (format.fieldwidth > 0 && format.minus == 1 && format.dot == 0)
		while ((--format.fieldwidth - numsize(n)) >= 0)
			*res += write(1, " ", 1);
	if (format.fieldwidth > 0 && format.minus == 1 && format.dot == 1 && (format.dotfield < numsize(n)) && n != 0)
		while((--format.fieldwidth - numsize(n)) >= 0)
			*res += write(1, " ", 1);
	if (format.fieldwidth > 0 && format.minus == 1 && format.dot == 1 && (format.dotfield > numsize(n)) && n != 0)
		while ((--format.fieldwidth - format.dotfield) >= 0)
			*res += write(1, " ", 1);
	if (format.fieldwidth > 0 && format.minus == 1 && format.dot == 1 && n == 0 && (format.fieldwidth < format.dotfield))
		while ((--format.fieldwidth - numsize(n)) >= 0)
			*res += write(1, " ", 1);
	if (format.fieldwidth > 0 && format.minus == 1 && format.dot == 1 && n == 0 && (format.fieldwidth > format.dotfield))
		while (--format.fieldwidth >= 0)
			*res += write(1, " ", 1);
}

void	printunsignedtwo(t_flags format, unsigned int n, int *res)
{
	if (format.fieldwidth > 0 && format.minus == 0 && format.dot == 0 && format.zero == 0)
		while ((--format.fieldwidth - numsize(n)) >= 0)
			*res += write(1, " ", 1);
	if (format.fieldwidth > 0 && format.minus == 0 && format.dot == 0 && format.zero == 1)
		while ((--format.fieldwidth - numsize(n)) >= 0)
			*res += write(1, "0", 1);
	if (format.fieldwidth > 0 && format.dot == 1 && format.minus == 0)
		printunsdot(format, n, res);
	if (format.fieldwidth == 0 && format.dot == 1)
		while ((--format.dotfield - numsize(n)) >= 0)
			*res += write(1, "0", 1);
	if (format.dot == 1 && format.minus == 1 && format.dotfield > 0)
		while ((--format.dotfield - numsize(n)) >= 0)
			*res += write(1, "0", 1);
}

void	printunsigned(t_flags format, unsigned int n, int *res)
{
	printunsignedtwo(format, n, res);
	ft_putuns_bonus(format, n, res);
	printunsminus(format, n, res);
}


void	printunsdot(t_flags format, unsigned int n, int *res)
{
	if (format.dotfield > numsize(n) && n != 0)
		while ((--format.fieldwidth - format.dotfield) >= 0)
			*res += write(1, " ", 1);
	else if (format.dotfield < numsize(n) && n != 0)
		while ((--format.fieldwidth - numsize(n)) >= 0)
			*res += write(1, " ", 1);
	else if (n == 0 && format.fieldwidth > format.dotfield)
		while (--format.fieldwidth >= 0)
			*res += write(1, " ", 1);
	while ((--format.dotfield - numsize(n)) >= 0)
		*res += write(1, "0", 1);
}

void	printpointer(t_flags format, void *ptr, int *res)
{
	char	*str;

	str = ft_itoa_base((unsigned long long) ptr);
	if (format.fieldwidth > 0 && format.minus == 0)
		while ((--format.fieldwidth - ft_strlen(str) - 2) >= 0)
			*res += write(1, " ", 1);
	*res += write(1, "0x", 2);
	*res += write(1, str, ft_strlen(str));
	if (format.fieldwidth > 0 && format.minus == 1)
		while ((--format.fieldwidth - ft_strlen(str) - 2) >= 0)
			*res += write(1, " ", 1);
	free(str);
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

void	printox(char *base, int *res)
{
	*res += write(1, "0", 1);
	if (base[10] == 'a')
		*res += write(1, "x", 1);
	else
		*res += write(1, "X", 1);
}

void	printnumspace(t_flags format, int n, int *res)
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

void	printnumsign(t_flags format, int n, int *res)
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

void	printnumminusthree(t_flags format, int n, int *res)
{
	if (format.plus == 0 && format.space == 0 && n > 0 && (format.dotfield > numsize(n)))
		while ((--format.fieldwidth - format.dotfield) >= 0)
			*res += write(1, " ", 1);
	if (format.plus == 0 && format.space == 0 && n > 0 && (format.dotfield < numsize(n)))
		while ((--format.fieldwidth - numsize(n) >= 0))
			*res += write(1, " ", 1);
	if (format.plus == 0 && format.space == 0 && n < 0)
		while ((--format.fieldwidth - format.dotfield) > 0)
			*res += write(1, " ", 1);
	if (format.plus == 1 || format.space == 1)
		while ((--format.fieldwidth - format.dotfield) > 0)
			*res += write(1, " ", 1);
	if (n == 0)
		while ((--format.fieldwidth - format.dotfield) >= 0)
			*res += write(1, " ", 1);
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
		printnumminusthree(format, n, res);
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

void	printnumberthree(t_flags format, int n, int *res)
{
	if (format.space == 1 || format.plus == 1)
		printnumsign(format, n, res);
	else
	{
		if (n < 0 && (format.dotfield > numsize(n)))
			while ((--format.fieldwidth - format.dotfield - 1) >= 0)
				*res += write(1, " ", 1);
		if (n < 0 && (format.dotfield < numsize(n)))
			while ((--format.fieldwidth - numsize(n)) >= 0)
				*res += write(1, " ", 1);
		if (n < 0)
			*res += write(1, "-", 1);
		if (n > 0 && (format.dotfield >= numsize(n)))
			while ((--format.fieldwidth - format.dotfield) >= 0)
				*res += write(1, " ", 1);
		else if (n > 0 && (numsize(n) > format.dotfield))
			while ((--format.fieldwidth - numsize(n)) >= 0)
				*res += write(1, " ", 1);
		if (n == 0 && format.fieldwidth > 0)
			while ((--format.fieldwidth - format.dotfield) >= 0)
				*res += write(1, " ", 1);
	}
	while ((--format.dotfield - numsizedot(n)) >= 0)
		*res += write(1, "0", 1);
}

void	printnumbertwo(t_flags format, int n, int *res)
{
	if ((format.fieldwidth > 0 || format.plus == 1 || format.space == 1) && format.zero == 0 && format.dot == 0)
		printnumspace(format, n, res);
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
		|| (format.zero == 1 && format.fieldwidth == 0 && format.minus == 0 && format.dot == 0))
		if (n < 0)
			*res += write(1, "-", 1);
	ft_putnbr_bonus(format, n, res);
	if (format.minus == 1)
		printnumminustwo(format, n, res);
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

char **memalloc(const char *s)
{
	char **rstr;
	int res;
	int index;
	int i;

	i = -1;
	index = 0;
	res = flagnum(s);
	rstr = malloc((res + 1) * sizeof(char *));
	while (++i < res)
		rstr[i] = malloc((stringlen(s, &index) + 1) * sizeof(char));
	rstr[i] = NULL;
	return (rstr);
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
			while (validateflag(s[++i]) == 0)
				res++;
		if (validateflag(s[i]) == 1)
			break ;
		i++;
	}
	*index = i + 1;
	return (res + 1);
}

void	printformat(t_flags format, va_list ap, int *res)
{
    if (format.flag == 'c')
		ft_putchar(format, va_arg(ap, int), res);
	if (format.flag == 's')
		ft_putstr_bonus(format, va_arg(ap, char *), res);
	if (format.flag == 'd')
		printnumberone(format, va_arg(ap, int), res);
	if (format.flag == 'p')
		printpointer(format, va_arg(ap, void*), res);
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
	t_flags	format;
	int		i;
	int		j;

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
	char	**formatstrings;

	formatstrings = memalloc(s);
	formatstrings = subflag(s, formatstrings);
	res = 0;
	va_start(ap, s);
	printall(ap, s, formatstrings, &res);
	free(formatstrings);
	va_end(ap);
	return (res);
}

int main(void)
{
	
	
	return (0);
}
