#include "libft.h"
#include "ft_printf.h"

void    printformat(t_flags format, va_list ap, int *count)
{
    if (format.flag == 'c')
		ft_putchar(format, va_arg(ap, char), count);
	if (format.flag == 's')
		ft_putstr(format, va_arg(ap, char *), count);
	if (format.flag == 'd')
		printnumber(format, va_arg(ap, int), count);
	if (format.flag == 'p')
		ft_putptr(format, va_arg(ap, long long), count);
	if (format.flag == 'i')
		printnumber(format, va_arg(ap, int), count);
	if (format.flag == 'u')
		ft_putuns(format, va_arg(ap, unsigned int), count);
	if (format.flag == 'x')
		ft_putnbr_base(format, va_arg(ap, unsigned int), "0123456789abcdef", count);
	if (format.flag == 'X')
		ft_putnbr_base(format, va_arg(ap, unsigned int), "0123456789ABCDEF", count);
	if (format.flag == '%')
		ft_putchar(format, va_arg(ap, char), count);
}