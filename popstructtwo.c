#include "libft.h"
#include "ft_printf.h"

t_flags	popstructtwo(const char *s, t_flags format)
{
	while (*s)
	{
		if (*s >= 0 && *s <= 9)
			format.fieldwidth = findfieldwidth(s);
		if (*s == '+')
			format.plus = 1;
		if (*s == '#')
			format.sharp = 1;
		if (*s == ' ')
			format.space = 1;
		if (validateflag(*s) == 1)
			format.flag = *s;
		s++;
	}
	return (format);
}