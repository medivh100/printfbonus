#include "libft.h"
#include "ft_printf.h"

t_flags popstructone(char *s, t_flags format)
{
	while (*s)
	{
		if (*s == '-')
		{
			format.minus = 1;
			format.minusfield = minusfield(s);
		}
		if (*s == '0')
			format.zero = 1;
		if (*s == '.')
		{
			format.dot = 1;
			format.dotfield = dotfield(s);
		}
	s++;
	}
	return (format);
}