#include "libft.h"
#include "ft_printf_bonus.h"
#include "ft_printf.h"

void	printchar(int c, int *res)
{
	*res += write(1, &c, 1);
}