#include "libft.h"
#include "ft_printf_bonus.h"

int	ft_printf(const char *s, ...)
{
	int		res;
	va_list	ap;
	char	**formatstrings;

	formatstrings = memalloc(s);
	formatstrings = subflag(s, formatstrings);
	res = 0;
	va_start(ap, s);
	printall(ap, s, formatstrings, &res);
	va_end(ap);
	return (res);
}
