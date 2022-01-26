#include "libft.h"
#include "ft_printf_bonus.h"
#include "ft_printf.h"

void	printunsigned(t_flags format, unsigned int n, int *res)
{
	printunsignedtwo(format, n, res);
	ft_putuns_bonus(format, n, res);
	printunsminus(format, n, res);
}
