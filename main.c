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

int	flagnum(char *s)
{
	int count;
	int trigger;

	count = 0;
	trigger = 0;
	while (*s)
	{
		if (*s == '%')
			trigger = 1;
		if (trigger == 1 && validateflag(*s) == 1)
		{
			count++;
			trigger = 0;
		}
		s++;
	}
	return (count);
}

int		stringlen(char *s, int *index)
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

char **memalloc(char *s)
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

char	**subflag(char *s, char **str)
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

void	parseformat(struct Flags format, char **str)
{

}

int	ft_printf(const char *s, ...)
{
	int		res;
	va_list	ap;

	res = 0;
	va_start(ap, s);
	strcreate(s, ap, &res);
	return (res);
}

int main(void)
{
	char	**str;
	int		count;
	int		i;

	i = 0;
	count = flagnum("%-15.15s %04d %s %13s");

	struct Flags flagarr[flagnum("%-15.15s %04d %s %13s")];

	while (i < count)
	{
		flagarr[i] = initstruct(flagarr[i]);
		i++;
	}
	flagarr[0].dot = 1;

	printf("%d\n", flagarr[1].dot); 

	str = subflag("%-15.15s %04d %s %13s", str);

	printf("%s ", str[0]);
	printf("%s ", str[1]);
	printf("%s ", str[2]);
	printf("%s ", str[3]);
	printf("%s ", str[4]);
	
	return (0);
}