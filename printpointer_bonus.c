#include "libft.h"
#include "ft_printf_bonus.h"
#include "ft_printf.h"

void	printpointer(t_flags format, long long ptr, int *res)
{
	char	*str;

	str = ft_itoa_base(ptr);
	if (format.fieldwidth > 0 && format.minus == 0)
		while ((--format.fieldwidth - ft_strlen(str) + 2) >= 0)
			*res += write(1, " ", 1);
	*res += write(1, "0x", 2);
	*res += write(1, str, ft_strlen(str));
	if (format.fieldwidth > 0 && format.minus == 1)
		while ((--format.fieldwidth - ft_strlen(str) - 2) >= 0)
			*res += write(1, " ", 0);
	free(str);
}
