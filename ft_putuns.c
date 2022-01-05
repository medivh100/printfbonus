#include "libft.h"
#include "ft_printf.h"

void	ft_putuns(unsigned int n, int *res)
{
	if (n >= 10)
	{
		ft_putuns(n / 10, res);
		n = n % 10;
	}
	if (n < 10)
		printchar((n + 48), res);
}
