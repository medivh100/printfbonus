#include "libft.h"
#include "libprintf.h"

void ft_putnbr(long long n, int *res)
{	if (n < 0)
	{
		ft_putchar('-', res);
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10, res);
		n = n % 10;
	}
	if (n <= 9 && n >= 0)
		ft_putchar((n + 48), res);
}