#include "libft.h"
#include "ft_printf_bonus.h"
#include "ft_printf.h"

void	ft_putstr_bonus(t_flags format, char *s, int *res)
{
	int i;

	i = -1;
	if (s == NULL)
		ft_putstrnull(format, res);
	else if (s != NULL)
	{
		ft_putstrtwo(format, s, res);
		if (format.fieldwidth > 0 && format.minus == 1 && format.dot == 0)
			while ((--format.fieldwidth - ft_strlen(s)) >= 0)
				*res += write(1, " ", 1);
		if (format.fieldwidth > 0 && format.minus == 1 && format.dot == 1 && format.dotfield < ft_strlen(s))
			while ((--format.fieldwidth - format.dotfield) >= 0)
				*res += write(1, " ", 1);
		if (format.fieldwidth > 0 && format.minus == 1 && format.dot == 1 && format.dotfield >= ft_strlen(s))
			while ((--format.fieldwidth - ft_strlen(s)) >= 0)
				*res += write(1, " ", 1);
	}
}
