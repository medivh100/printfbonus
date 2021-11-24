#include "ft_printf.h"
#include "libft.h"

void	ft_putptr_base(unsigned long long nbr, char *base, int *res)
{	
	//long long nout = (long long) nbr;
	if (nbr < 0)
	{
		ft_putchar('-', res);
		nbr = -nbr;
	}
	if (nbr >= 16)
	{
		ft_putptr_base(nbr / 16, base, res);
		nbr = nbr % 16;
	}
	if (nbr <= 16 && nbr >= 0)
		ft_putchar(base[nbr], res);
}