#include "libft.h"
#include "ft_printf.h"

void	ft_putstr(t_flags format, char *s, int *res)
{
	if (s != NULL)
	{
		if (format.fieldwidth > 0 && format.minus == 0 && format.dot == 0)
			while ((--format.fieldwidth - ft_strlen(s)) >= 0)
				*res += write(1, " ", 1);
		if (format.fieldwidth > 0 && format.dot == 1 && format.minus == 0)
			while ((--format.fieldwidth - ft_strlen(s) - format.dotfield))
				*res += write(1, " ", 1);
		if (format.dot == 1)
			*res += write(1, s, format.dotfield);
		else
			*res += write(1, s, ft_strlen(s));
		if (format.fieldwidth > 0 && format.minus == 1)
			while ((--format.fieldwidth - ft_strlen(s)) >= 0)
				*res += write(1, " ", 1);
	}
	else if (s == NULL)
		*res += write(1, "(null)", 6);
}
