#include "libft.h"
#include "libprintf.h"

void    ft_putptr(void *ptr, int *res)
{
	*res += write(1, "0x", 2);
	ft_putnbr_base((long long) ptr, "0123456789abcdef", res);
}