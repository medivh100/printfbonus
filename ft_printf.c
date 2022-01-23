#include "libft.h"
#include "ft_printf.h"

// Any combination of flags "-0." and minimum field width for any conversion    //
// All the following flags "# +"                                                //
// main function, initializing va_list ap to be passed to strcreate             //
int	ft_printf(const char *s, ...)
{
	int		res;
	va_list	ap;

	res = 0;
	va_start(ap, s);
	strcreate(s, &ap, &res);
	return (res);
}
