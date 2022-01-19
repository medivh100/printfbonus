#include "libft.h"
#include "ft_printf_bonus.h"
#include "ft_printf.h"

void	ft_putchar(t_flags format, int c, int *res)
{
	if (format.fieldwidth > 0 && format.minus == 0)
		while (--format.fieldwidth > 0)
			res += write(1, " ", 1);
	*res += write(1, &c, 1);
	if (format.fieldwidth > 0 && format.fieldwidth == 1)
		while (--format.fieldwidth > 0)
			res += write(1, " ", 1);
}
