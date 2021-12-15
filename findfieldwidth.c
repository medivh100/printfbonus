#include "libft.h"
#include "ft_printf.h"

int findfieldwidth(const char *s)
{
    int		num;
	int		trigger;

	num = 0;
	trigger = 0;
	while (*s)
	{
		s++;
		if ((*s == '-' || *s == ' ' || *s == '.' || *s == '#' || validateflag(*s) == 1) && trigger == 1)
			break ;
		if (*s == '%' && (*(s + 1) <= '9' && *(s + 1) >= '0'))
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