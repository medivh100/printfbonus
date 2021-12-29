#include "libft.h"
#include "ft_printf.h"

void	ft_putuns(t_flags format, unsigned int n, int *res)
{
	if (n >= 10)
	{
		ft_putuns(format, n / 10, res);
		n = n % 10;
	}
	if (n < 10)
		ft_putchar(format, (n + 48), res);
}
