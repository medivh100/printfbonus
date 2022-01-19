#include "libft.h"
#include "ft_printf_bonus.h"
#include "ft_printf.h"

void	printox(char *base, int *res)
{
	*res += write(1, "0", 1);
	if (base[11] == 'a')
		*res += write(1, "x", 1);
	else
		*res += write(1, "X", 1);
}
