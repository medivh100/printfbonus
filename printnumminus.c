#include "libft.h"
#include "ft_printf.h"

void	printnumminus(t_flags format, int n, int *res)
{
	if (format.plus == 1 || format.space == 1)
	{
		if (format.plus == 1 && n >= 0)
			*res += write(1, "+", 1);
		if (format.space == 1 && format.plus != 1 && n >= 0)
			*res += write(1, " ", 1);
	}
	if (n < 0)
		*res += write(1, "-", 1);
	if (format.dot == 1)
		while ((--format.dotfield - numsizedot(n)) >= 0)
			*res += write(1, "0", 1);
}
