#include "libft.h"
#include "ft_printf.h"

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