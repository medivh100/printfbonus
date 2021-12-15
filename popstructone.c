#include "libft.h"
#include "ft_printf.h"

t_flags popstructone(const char *s, t_flags format)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '-')
		{
			format.minus = 1;
			format.minusfield = minusfield(s);
		}
		if (s[i] == '0')
			format.zero = 1;
		if (s[i] == '.')
		{
			format.dot = 1;
			format.dotfield = dotfield(s);
		}
	i++;
	}
	return (format);
}