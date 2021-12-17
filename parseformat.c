#include "libft.h"
#include "ft_printf.h"

void	parseformat(t_flags format, char **str, va_list ap, int *count)
{
	int	i;

	i = 0;
	while (str[i])
	{
		format = popstructone(str[i], format);
		format = popstructtwo(str[i], format);
		printformat(format, ap, count);
		format = initstruct(format);
		i++;
	}

}
