#include "libft.h"
#include "ft_printf.h"

void	ft_putstr(t_flags format, char *s, int *res)
{
	if (s != NULL)
		*res += write(1, s, ft_strlen(s));
	else if (s == NULL)
		*res += write(1, "(null)", 6);
}
