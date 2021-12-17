#include <stdio.h>
#include "libft.h"
#include "ft_printf.h"

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
	format.minusfield = 0;
	format.plus = 0;
	format.sharp = 0;
	format.space = 0;
	format.zero = 0;
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

// void	parseformat(struct Flags *format, char **str)
// {
// 	int count;


// }

// int	ft_printf(const char *s, ...)
// {
// 	int		res;
// 	va_list	ap;

// 	res = 0;
// 	va_start(ap, s);
// 	strcreate(s, ap, &res);
// 	return (res);
// }

int	minusfield(char *s)
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
		if (*s == '-')
		{
			trigger = 1;
			s++;
		}
		if ((*s > '0' && *s < '9') && trigger == 1)
		{
			num = num * 10;
			num += *s - 48;
		}
	}
	return (num);
}

int	dotfield(char *s)
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
		if ((*s == '-' || *s == ' ' || *s == '.' || *s == '#' || validateflag(*s) == 1) && trigger == 1)
			break ;
		if ((*s == '%' || *s == '0' || *s == '#' || *s == ' ') && (*(s + 1) <= '9' && *(s + 1) >= '0'))
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

int main(void)
{
	int i;

	//i = findfieldwidth("%# -100X");
	//printf("%d\n", i);
	printf("%#5x\n", 100);
	printf("%-#5x\n", 100);
	printf("%5x\n", 100);
	printf("%-5x\n", 100);
	printf("%#12x\n", 100);
	printf("%-#12x\n", 100);
	
	return (0);
}