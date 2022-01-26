#include "libft.h"
#include "ft_printf_bonus.h"
#include "ft_printf.h"

void	ft_putuns_bonus(t_flags format, unsigned int n, int *res)
{
	if (n == 0 && format.dot == 1 && format.dotfield == 0)
		return ;
	if (n >= 10)
	{
		ft_putuns_bonus(format, n / 10, res);
		n = n % 10;
	}
	if (n < 10)
		printchar((n + 48), res);
}
