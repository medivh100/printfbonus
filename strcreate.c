#include "libft.h"
#include "ft_printf.h"

void	strcreate(const char *s, va_list ap, int *res)
{
	while (*s)
	{
		while (*s == '%' && validateflag(*(s + 1)) == 1)
		{
			dispatchflag(*(s + 1), ap, res);
			s += 2;
			if (*s == '\0')
				break;
		}
		if (*s == '\0')
			break ;
		printchar(*s, res);
		s++;
	}
}
