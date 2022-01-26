#include "libft.h"
#include "ft_printf_bonus.h"

void	ft_putstrnull(t_flags format, int *res)
{
	if (format.fieldwidth > 0 && format.minus == 0)
			while ((--format.fieldwidth - 6) >= 0)
				*res += write(1, " ", 1);
	if (format.dot == 0 || (format.dot == 1 && format.dotfield > 6))
		*res += write(1, "(null)", 6);
	if (format.dot == 1 && format.dotfield <= 6)
		*res += write(1, "(null)", format.dotfield);
	if (format.fieldwidth > 0 && format.minus == 1)
		while ((--format.fieldwidth - 6) >= 0)
			*res += write(1, " ", 1);
}