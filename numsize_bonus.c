#include "libft.h"
#include "ft_printf_bonus.h"

int	numsize(long long n)
{
	long long	i;

	i = 0;
	if (n < 0)
		i = (memsize(-n) + 1);
	if (n > 0)
		i = (memsize(n / 10) + 1);
	return (i);
}