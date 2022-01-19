#include "libft.h"
#include "ft_printf_bonus.h"
#include "ft_printf.h"

char	**subflag(const char *s, char **str)
{
	int	iter;
	int	limit;
	int index;

	iter = -1;
	limit = flagnum(s);
	index = 0;
	while (++iter < limit)
		str[iter] = findformat(s,str[iter], &index);
	return (str);
}
