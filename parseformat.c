#include "libft.h"
#include "ft_printf.h"

void	parseformat(t_flags format, char *str, va_list ap, int *count)
{
	format = popstructone(str, format);
	format = popstructtwo(str, format);
	free(str);
	printformat(format, ap, count);
}
