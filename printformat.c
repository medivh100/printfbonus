#include "libft.h"
#include "ft_printf.h"

void    printformat(t_flags format, va_list ap, int *count)
{
    if (format.flag == 'c')
		ft_putchar(va_arg(ap, char), count);
}