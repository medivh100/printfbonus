#include "libft.h"
#include "ft_printf.h"

void	printnumbertwo(t_flags format, int n, int *res)
{
	int iter;

	iter = format.fieldwidth - numsize(n);
	if (format.dot == 1)
		iter = format.dotfield - numsizedot(n);
	if (format.fieldwidth > 0 && format.minus == 0 && format.zero == 0 && format.plus == 0)
		while (iter-- > 0)
			*res += write(1, " ", 1);
	if (format.fieldwidth > 0 && format.plus == 1 && format.zero == 0 && (format.space == 1 || format.space == 0))
	{
		while (iter-- > 1)
			*res += write(1, " ", 1);
		if (n >= 0)
			*res += write(1, "+", 1);
	}
	if (format.fieldwidth > 0 && format.space == 1 && format.plus == 0)
		while (iter-- > 0)
			*res += write(1, " ", 1);
	if (format.fieldwidth > 0 && format.zero == 1)
		while (iter-- > 0)
			*res += write(1, "0", 1);
	if (format.fieldwidth == 0 && format.dot == 1 && format.dotfield > 0)
		while (iter-- > 0)
			*res += write(1, "0", 1);
}
