#include "libft.h"
#include "ft_printf_bonus.h"
#include "ft_printf.h"

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