#include "libft.h"
#include "ft_printf_bonus.h"
#include "ft_printf.h"

void	parseformat(t_flags format, char *str, va_list *ap, int *res)
{
	format = popstructone(str, format);
	format = popstructtwo(str, format);
	printformat(format, ap, res);
}
