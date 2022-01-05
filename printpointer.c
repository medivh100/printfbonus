#include "libft.h"
#include "ft_printf.h"

void	printpointer(t_flags format, long long ptr, int *res)
{
	int		iter;
	char	*str;

	str = ft_itoa_base(ptr);
	iter = format.fieldwidth - (ft_strlen(str) + 2);
	if (iter > 0 && format.minus == 0)
		while (iter-- > 0)
			*res += write(1, " ", 1);
	*res += write(1, "0x", 2);
	*res += write(1, str, ft_strlen(str));
	free(str);
	if (iter > 0 && format.minus == 1)
		while (iter-- > 0)
			*res += write(1, " ", 1);
}