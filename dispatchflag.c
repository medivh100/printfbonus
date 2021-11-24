#include "libft.h"
#include "ft_printf.h"

// Function that dispatches the arguments to corresponding functions for printing.

void	dispatchflag(int c, va_list ap, int *res)
{
	if (c == 'c')
		ft_putchar(va_arg(ap, int), res);
	if (c == 's')
		ft_putstr(va_arg(ap, char *), res);
	if (c == 'd')
		ft_putnbr(va_arg(ap, int), res);
	if (c == 'p')
		ft_putptr(va_arg(ap, long long), res);
	if (c == 'i')
		ft_putnbr(va_arg(ap, int), res);
	if (c == 'u')
		ft_putuns(va_arg(ap, unsigned int), res);
	if (c == 'x')
		ft_putnbr_base(va_arg(ap, unsigned int), "0123456789abcdef", res);
	if (c == 'X')
		ft_putnbr_base(va_arg(ap, unsigned int), "0123456789ABCDEF", res);
	if (c == '%')
		*res += write(1, "%", 1);
}
