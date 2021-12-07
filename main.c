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

char	*subflag(char **str, char *s, int *index)
{
	int		i;

	i = *index;
	while (s[i])
	{
		if (s[i] == '%')
		{
			while (validateflag(s[i] == 0))
			{
				str[i] 
			
			}
		}
		i++;
	}
}

// char	**flagsplit(char *s)
// {
// 	char	**str;
// 	int		i;

// 	str = memalloc(s);
	
// 	return (str);
// }

int main(void)
{

	// int i;
	// int count;

	// i = 0;
	// count = -1;
	char	**str;

	str = memalloc("%-15.15s %04d %s");
	
	//printf("%d\n", stringlen("%-15.15s %04d %s", &i));

	return (0);
}