#include "libft.h"
#include "ft_printf.h"

char	**subflag(char *s, char **str)
{
	int		index;
	int		i;
	int		j;

	str = memalloc(s);
	i = 0;
	j = 0;
	index = 0;
	while (s[index])
	{
		if (s[index] == '%')
		{
			while (s[index + i] != ' ')
			{
				str[j][i] = s[index + i];
				i++;
				if (s[index + i] == '%')
					break ;
			}
		i = 0;
		j++;
		}
	index++;
	}
	return (str);
}
