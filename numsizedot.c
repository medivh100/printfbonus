#include "libft.h"
#include "ft_printf.h"

int	numsizedot(long long n)
{
	long long	i;

	i = 0;
	if (n < 0)
		n = -n;
	if (n > 0)
		i = (numsize(n / 10) + 1);
	return (i);
}
