#include "libft.h"
#include "libprintf.h"

void    ft_putstr(char *s, int *res)
{
    *res += write(1, s, ft_strlen(s));
}