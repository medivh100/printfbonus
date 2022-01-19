#include "libft.h"
#include "ft_printf_bonus.h"
#include "ft_printf.h"

void	printnumbertwo(t_flags format, int n, int *res)
{
		if ((format.fieldwidth > 0 || format.plus == 1 || format.space == 1) && format.zero == 0 && format.dot == 0)
		{
			if (format.plus == 1 || format.space == 1)
				while ((--format.fieldwidth - numsizedot(n) - 1) >= 0)
					*res += write(1, " ", 1);
			else
				while ((--format.fieldwidth - numsize(n)) >= 0)
					*res += write(1, " ", 1);
			if (format.plus == 1 && n >= 0)
				*res += write(1, "+", 1);
			if (format.space == 1 && n >= 0 && format.plus != 1)
				*res += write(1, " ", 1);
		}
		if (format.zero == 1 && format.fieldwidth > 0 && format.plus == 0 && format.space == 0 && format.dot == 0)
		{
			if (n < 0)
				*res += write(1, "-", 1);
			while ((--format.fieldwidth - numsize(n)) >= 0)
				*res += write(1, "0", 1);
		}
		if (format.zero == 1 && format.fieldwidth > 0 && format.dot == 0 && (format.space == 1 || format.plus == 1))
			printnumzero(format, n, res);
		if (format.dot == 1)
			printnumberthree(format, n, res);
}
