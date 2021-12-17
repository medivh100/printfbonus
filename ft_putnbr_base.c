#include "libft.h"
#include "ft_printf.h"

void	ft_putnbr_base(t_flags format, unsigned int nbr, char *base, int *res)
{	
	if (nbr < 0)
	{
		ft_putchar('-', res);
		nbr = -nbr;
	}
	if (nbr >= 16)
	{
		ft_putnbr_base(format, nbr / 16, base, res);
		nbr = nbr % 16;
	}
	if (nbr <= 16 && nbr >= 0)
		ft_putchar(base[nbr], res);
}
