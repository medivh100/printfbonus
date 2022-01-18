#include "libft.h"
#include "ft_printf.h"

int		stringlen(const char *s, int *index)
{
	int i;
	int	res;

	i = *index;
	res = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			while (validateflag(s[i + 1]) == 0)
			{
				i++;
				res++;
			}
		}
		if (validateflag(s[i]) == 1)
			break ;
		i++;
	}
	*index = i + 1;
	return (res + 1);
}