#include "libft.h"
#include "ft_printf_bonus.h"

void	printnumsign(t_flags format, int n, int *res)
{
	while ((--format.fieldwidth - format.dotfield - 1) >= 0)
		*res += write(1, " ", 1);
	if (n >= 0 && format.plus == 1)
		*res += write(1, "+", 1);
	else if (n >= 0 && format.space == 1)
		*res += write(1, " ", 1);
	else if (n < 0 == (format.space == 1 || format.plus == 1))
		*res += write(1, "-", 1);
}