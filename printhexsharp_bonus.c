#include "libft.h"
#include "ft_printf_bonus.h"
#include "ft_printf.h"

void	printhexsharp(t_flags format, unsigned int nbr, char *base, int *res)
{
	if (format.dot == 1 && format.fieldwidth == 0)
	{
		printox(base, res);
		while ((--format.dotfield - numsize(nbr) - 2) >= 0)
			*res += write(1, "0", 1);
	}
	if (format.dot == 1 && format.fieldwidth > 0 && format.minus == 0)
	{
		while ((--format.fieldwidth - format.dotfield - numsize(nbr) - 2) >= 0)
			*res += write(1, " ", 1);
		printox(base, res);
		while (--format.dotfield - numsize(nbr) - 2)
			*res += write(1, "0", 1);
	}
	if (format.dot == 0 && format.fieldwidth > 0 && format.minus == 0 && format.zero == 0)
	{
		while ((--format.fieldwidth - numsize(nbr) - 2) >= 0)
				*res += write(1, " ", 1);
		printox(base, res);
	}
	if (format.dot == 0 && format.fieldwidth > 0 && format.minus == 0 && format.zero == 1)
	{
		printox(base, res);
		while ((--format.fieldwidth - numsize(nbr) - 2) >= 0)
			*res += write(1, "0", 1);
	}
}
