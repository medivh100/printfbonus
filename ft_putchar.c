#include "libft.h"
#include "libprintf.h"

void    ft_putchar(int c, int *res)
{
    *res += write(1, &c, 1);
}