#include "libft.h"
#include "ft_printf_bonus.h"
#include "ft_printf.h"

void	ft_putnbr_bonus(t_flags format, int n, int *res)
{
	long long	nout;

	nout = (long long) n;
	if (format.dot == 1 && format.dotfield == 0 && n == 0)
		return ;
	if (nout < 0)
		nout = -nout;
	if (nout >= 10)
	{
		ft_putnbr_bonus(format, nout / 10, res);
		nout = nout % 10;
	}
	if (nout <= 9 && nout >= 0)
		printchar((nout + 48), res);
}
