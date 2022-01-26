#include "libft.h"
#include "ft_printf_bonus.h"
#include "ft_printf.h"

void	printnumberthree(t_flags format, int n, int *res)
{
	if (format.space == 1 || format.plus == 1)
		printnumsign(format, n, res);
	else
	{
		if (n < 0 && (format.dotfield > numsize(n)))
			while ((--format.fieldwidth - format.dotfield - 1) >= 0)
				*res += write(1, " ", 1);
		if (n < 0 && (format.dotfield < numsize(n)))
			while ((--format.fieldwidth - numsize(n)) >= 0)
				*res += write(1, " ", 1);
		if (n < 0)
			*res += write(1, "-", 1);
		if (n > 0 && (format.dotfield >= numsize(n)))
			while ((--format.fieldwidth - format.dotfield) >= 0)
				*res += write(1, " ", 1);
		else if (n > 0 && (numsize(n) > format.dotfield))
			while ((--format.fieldwidth - numsize(n)) >= 0)
				*res += write(1, " ", 1);
		if (n == 0 && format.fieldwidth > 0)
			while ((--format.fieldwidth - format.dotfield) >= 0)
				*res += write(1, " ", 1);
	}
	while ((--format.dotfield - numsizedot(n)) >= 0)
		*res += write(1, "0", 1);
}
