#include "libft.h"
#include "ft_printf_bonus.h"

int	memsizebase(long long n)
{
	int	i;

	i = 0;
	if (n < 0)
		i = (memsizebase(-n) + 1);
	if (n > 0)
		i = (memsizebase(n / 16) + 1);
	return (i);
}
