#include "libft.h"
#include "ft_printf_bonus.h"

void	printunsdot(t_flags format, unsigned int n, int *res)
{
	if (format.dotfield > numsize(n) && n != 0)
		while ((--format.fieldwidth - format.dotfield) >= 0)
			*res += write(1, " ", 1);
	else if (format.dotfield < numsize(n) && n != 0)
		while ((--format.fieldwidth - numsize(n)) >= 0)
			*res += write(1, " ", 1);
	else if (n == 0 && format.fieldwidth > format.dotfield)
		while (--format.fieldwidth >= 0)
			*res += write(1, " ", 1);
	while ((--format.dotfield - numsize(n)) >= 0)
		*res += write(1, "0", 1);
}