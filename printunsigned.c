#include "libft.h"
#include "ft_printf.h"

void	printunsigned(t_flags format, unsigned int n, int *res)
{
	if (format.fieldwidth > 0 && format.minus == 0 && format.dot == 0)
		while ((--format.fieldwidth - numsize(n)) >= 0)
			*res += write(1, " ", 1);
	if (format.fieldwidth > 0 && format.dot == 1 && format.minus == 0)
	{
		while ((--format.fieldwidth - format.dotfield) >= 0)
			*res += write(1, " ", 1);
		while ((--format.dotfield - numsize(n)) >= 0)
			*res += write(1, "0", 1);
	}
	if (format.fieldwidth == 0 && format.dot == 1)
		while ((--format.dotfield - numsize(n)) >= 0)
			*res += write(1, "0", 1);
	if (format.dot == 1 && format.minus == 1)
		while ((--format.dotfield - numsize(n)) >= 0)
			*res += write(1, "0", 1);
	ft_putuns(n, res);
	if (format.fieldwidth > 0 && format.minus == 1 && format.dotfield == 0)
		while ((--format.fieldwidth - numsize(n)) >= 0)
			*res += write(1, " ", 1);
	if (format.fieldwidth > 0 && format.minus == 1 && format.dotfield == 1)
		while((--format.fieldwidth - format.dotfield - numsize(n) > 1))
			*res += write(1, " ", 1);
}
