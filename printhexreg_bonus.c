#include "libft.h"
#include "ft_printf_bonus.h"

void	printhexreg(t_flags format, unsigned int nbr, int *res)
{
	if (format.dot == 1 && format.fieldwidth == 0)
		while (--format.dotfield - memsizebase(nbr) >= 0)
			*res += write(1, "0", 1);
	if (format.dot == 1 && format.fieldwidth > 0)
	{
		while ((--format.fieldwidth - format.dotfield) >= 0)
			*res += write(1, " ", 1);
		while ((--format.dotfield - memsizebase(nbr)) >= 0)
			*res += write(1, "0", 1);
	}
	if (format.dot == 0 && format.fieldwidth > 0)
	{
		if (format.zero == 0)
			while ((--format.fieldwidth - memsizebase(nbr)) >= 0)
				*res += write(1, " ", 1);
		if (format.zero == 1)
			while ((--format.fieldwidth - memsizebase(nbr)) >= 0)
				*res += write(1, "0", 1);
	}
}
