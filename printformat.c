#include "libft.h"
#include "ft_printf.h"

void    printformat(t_flags format, va_list ap, int *res)
{
    if (format.flag == 'c')
		ft_putchar(format, va_arg(ap, char), res);
	if (format.flag == 's')
		ft_putstr(format, va_arg(ap, char *), res);
	if (format.flag == 'd')
		printnumberone(format, va_arg(ap, int), res);
	if (format.flag == 'p')
		printpointer(format, va_arg(ap, long long), res);
	if (format.flag == 'i')
		printnumberone(format, va_arg(ap, int), res);
	if (format.flag == 'u')
		ft_putuns(format, va_arg(ap, unsigned int), res);
	if (format.flag == 'x')
		ft_putnbr_base(format, va_arg(ap, unsigned int), "0123456789abcdef", res);
	if (format.flag == 'X')
		ft_putnbr_base(format, va_arg(ap, unsigned int), "0123456789ABCDEF", res);
	if (format.flag == '%')
		ft_putchar(format, va_arg(ap, char), res);
}