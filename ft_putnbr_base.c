#include "libft.h"
#include "libprintf.h"

void ft_putnbr_base(long long nbr, char *base, int *res)
{	
	if (nbr < 0)
	{
		ft_putchar('-', res);
		nbr = -nbr;
	}
	if (nbr >= 16)
	{
		ft_putnbr_base(nbr / 16, base, res);
		nbr = nbr % 16;
	}
	if (nbr <= 16 && nbr >= 0)
		ft_putchar(base[nbr], res);
}