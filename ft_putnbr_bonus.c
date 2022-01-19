#include "libft.h"
#include "ft_printf_bonus.h"
#include "ft_printf.h"

void	ft_putnbr(int n, int *res)
{
	long long	nout;

	nout = (long long) n;
	if (nout < 0)
		nout = -nout;
	if (nout >= 10)
	{
		ft_putnbr(nout / 10, res);
		nout = nout % 10;
	}
	if (nout <= 9 && nout >= 0)
		printchar((nout + 48), res);
}
