#include "libft.h"
#include "ft_printf.h"

void	printnumberone(t_flags format, int n, int *res)
{
	int iter;

	iter = format.fieldwidth - numsize(n);
	if (format.plus == 1 && format.fieldwidth == 0 && format.zero == 0 && n >= 0)
		*res += write(1, "+", 1);
	if ((n < 0) && (format.dotfield > 0 || format.zero == 1))
		*res += write(1, "-", 1);
	printnumbertwo(format, n, res);
	if ((n < 0) && format.plus == 1 && format.fieldwidth != 0)
		*res += write(1, " ", 1);
	if ((n < 0) && format.dotfield == 0 && format.zero == 0)
		*res += write(1, "-", 1);
	ft_putnbr(n, res);
	if (format.fieldwidth > 0 && format.minus == 1)
		while (iter-- > 0)
			*res += write(1, " ", 1);
}
