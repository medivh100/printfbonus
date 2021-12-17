#include "libft.h"
#include "ft_printf.h"

void	ft_putchar(t_flags format, int c, int *res)
{
	*res += write(1, &c, 1);
}
