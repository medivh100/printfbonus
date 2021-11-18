#include "libft.h"
#include "libprintf.h"

void    ft_putuns(unsigned long long n, int *res)
{
    if (n >= 10)
	{
		ft_putuns(n / 10, res);
		n = n % 10;
	}
	if (n < 10)
		ft_putchar((n + 48), res);
}