#include "libft.h"
#include "ft_printf_bonus.h"
#include "ft_printf.h"

char	**memalloc(const char *s)
{
	char	**rstr;
	int		count;
	int		index;
	int		i;

	i = 0;
	index = 0;
	count = flagnum(s);
	rstr = malloc((count + 1) * sizeof(char *));
	while (i < count)
	{
		rstr[i] = malloc((stringlen(s, &index) + 1) * sizeof(char));
		i++;
	}
	rstr[i] = NULL;
	return (rstr);
}