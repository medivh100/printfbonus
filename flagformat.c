#include "libft.h"
#include "ft_printf.h"

struct Flags	*flagsformat(const char *s)
{
	int				i;
	int				count;
	struct Flags	*format;

	format = malloc((flagnum(s)) * sizeof (struct Flags));
	i = 0;
	count = flagnum(s);
	while (i < count)
	{
		format[i] = initstruct(format[i]);
		i++;
	}
	return (format);
}
