#include "libft.h"
#include "ft_printf.h"

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
			count++;
			s += 2;
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