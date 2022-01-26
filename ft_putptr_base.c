#include "libft.h"
#include "ft_printf.h"
#include "ft_printf_bonus.h"

void	ft_putptr_base(unsigned long long nbr, char *base, int *res)
{
	if (nbr >= 16)
	{
		ft_putptr_base(nbr / 16, base, res);
		nbr = nbr % 16;
	}
	if (nbr <= 16 && nbr >= 0)
		printchar(base[nbr], res);
}
