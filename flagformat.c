#include "libft.h"
#include "ft_printf.h"

t_flags	*flagformat(const char *s)
{
	int				i;
	int				count;
	t_flags			*format;

	format = malloc((flagnum(s)) * sizeof (t_flags));
	i = 0;
	count = flagnum(s);
	while (i < count)
	{
		format[i] = initstruct(format[i]);
		i++;
	}
	return (format);
}
