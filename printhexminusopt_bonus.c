#include "libft.h"
#include "ft_printf_bonus.h"
#include "ft_printf.h"

void	printhexminusopt(t_flags format, unsigned int nbr, char *base, int *res)
{
	if (format.dot == 1 && format.sharp == 0)
		while ((--format.dotfield - memsizebase(nbr)) >= 0)
			*res += write(1, "0", 1);
	if (format.dot == 1 && format.sharp == 1)
	{
		printox(base, res);
		while ((--format.dotfield - memsizebase(nbr)) >= 0)
			*res += write(1, "0", 1);
	}
	if (format.dot == 0 && format.sharp == 1)
		printox(base, res);
}
