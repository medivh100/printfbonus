#include "libft.h"
#include "ft_printf_bonus.h"

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