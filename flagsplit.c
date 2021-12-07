#include "ft_printf.h"
#include "libft.h"

int	flagnum(char *s)
{
	int count;
	while (*s)
	{
		if (*s == '%' && validateflag(*(s + 1)) == 1)
			count++;
	s++;
	}
	return (count);
}

char	**flagsplit(char *s)
{
	char	**str;
	int		flags;

	flags = flagnum(s);
	printf("%d", flags);
	return (str);
}