#include "libft.h"
#include "ft_printf.h"

void	ft_putptr(t_flags format, long long ptr, int *res)
{
	*res += write(1, "0x", 2);
	ft_putptr_base(format, (unsigned long long) ptr, "0123456789abcdef", res);
}
