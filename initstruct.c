#include "libft.h"
#include "ft_printf.h"

t_flags initstruct(t_flags format)
{
	format.dot = 0;
	format.dotstring = 0;
	format.flag = 0;
	format.minus = 0;
	format.minusfield = 0;
	format.plus = 0;
	format.sharp = 0;
	format.space = 0;
	format.zero = 0;
	return (format);
}
