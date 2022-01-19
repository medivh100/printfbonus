#include "libft.h"
#include "ft_printf_bonus.h"
#include "ft_printf.h"

int		stringlen(const char *s, int *index)
{
	int i;
	int	count;

	i = *index;
	count = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			while (validateflag(s[i + 1]) == 0)
			{
				i++;
				count++;
			}
		}
		if (validateflag(s[i]) == 1)
			break ;
		i++;
	}
	*index = i + 1;
	return (count + 1);
}