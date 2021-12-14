#include "libft.h"
#include "ft_printf.h"

void	parseformat(t_flags *format, char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		format[i] = popstructone(str[i], format[i]);
		format[i] = popstructtwo(str[i], format[i]);
		i++;
	}
}
