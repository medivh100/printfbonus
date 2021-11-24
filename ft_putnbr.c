#include "libft.h"
#include "ft_printf.h"

void	ft_putnbr(int n, int *res)
{
	long long nout = (long long) n;
	if (nout < 0)
	{
		ft_putchar('-', res);
		nout = -nout;
	}
	if (nout >= 10)
	{
		ft_putnbr(nout / 10, res);
		nout = nout % 10;
	}
	if (nout <= 9 && nout >= 0)
		ft_putchar((nout + 48), res);
}
