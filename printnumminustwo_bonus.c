#include "libft.h"
#include "ft_printf_bonus.h"

void	printnumminustwo(t_flags format, int n, int *res)
{
	if (format.minus == 1 && format.fieldwidth > 0 && format.dot == 0)
	{
		if (format.plus == 0 && format.space == 0)
			while (--format.fieldwidth - numsize(n) >= 0)
				*res += write(1, " ", 1);
		if ((format.plus == 1 || format.space == 1) && n >= 0)
			while (--format.fieldwidth - numsize(n) > 0)
				*res += write(1, " ", 1);
		if ((format.plus == 1 || format.space == 1) && n < 0)
			while ((--format.fieldwidth - numsize(n)) >= 0)
				*res += write(1, " ", 1);
	}
	if (format.minus == 1 && format.fieldwidth > 0 && format.dot == 1)
	{
		if (format.plus == 0 && format.space == 0 && n >= 0)
			while ((--format.fieldwidth - format.dotfield) >= 0)
				*res += write(1, " ", 1);
		if (format.plus == 0 && format.space == 0 && n < 0)
			while ((--format.fieldwidth - format.dotfield) > 0)
				*res += write(1, " ", 1);
		if (format.plus == 1 || format.space == 1)
			while ((--format.fieldwidth - format.dotfield) > 0)
				*res += write(1, " ", 1);
	}
}