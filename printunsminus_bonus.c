#include "libft.h"
#include "ft_printf_bonus.h"

void	printunsminus(t_flags format, unsigned int n, int *res)
{
	if (format.fieldwidth > 0 && format.minus == 1 && format.dot == 0)
		while ((--format.fieldwidth - numsize(n)) >= 0)
			*res += write(1, " ", 1);
	if (format.fieldwidth > 0 && format.minus == 1 && format.dot == 1 && (format.dotfield < numsize(n)) && n != 0)
		while((--format.fieldwidth - numsize(n)) >= 0)
			*res += write(1, " ", 1);
	if (format.fieldwidth > 0 && format.minus == 1 && format.dot == 1 && (format.dotfield > numsize(n)) && n != 0)
		while ((--format.fieldwidth - format.dotfield) >= 0)
			*res += write(1, " ", 1);
	if (format.fieldwidth > 0 && format.minus == 1 && format.dot == 1 && n == 0 && (format.fieldwidth < format.dotfield))
		while ((--format.fieldwidth - numsize(n)) >= 0)
			*res += write(1, " ", 1);
	if (format.fieldwidth > 0 && format.minus == 1 && format.dot == 1 && n == 0 && (format.fieldwidth > format.dotfield))
		while (--format.fieldwidth >= 0)
			*res += write(1, " ", 1);
}