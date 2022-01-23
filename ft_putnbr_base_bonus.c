#include "libft.h"
#include "ft_printf.h"
#include "ft_printf_bonus.h"

void	ft_putnbr_base_bonus(t_flags format, unsigned int nbr, char *base, int *res)
{	
	if (nbr == 0 && format.dot == 1 && format.dotfield == 0)
		return ;
	if (nbr >= 16)
	{
		ft_putnbr_base(nbr / 16, base, res);
		nbr = nbr % 16;
	}
	if (nbr <= 16 && nbr >= 0)
		printchar(base[nbr], res);
}