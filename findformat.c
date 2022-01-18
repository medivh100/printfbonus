#include "libft.h"
#include "ft_printf.h"

char	*findformat(const char *s,char *str, int *index)
{
	int	j;
	int	trigger;
	int	i;

	j = 0;
	trigger = 0;
	i = *index;
	while (s[i])
	{
		if (s[i] == '%')
		{
			str[j++] = '%';
			i++;
			trigger = 1;
			while (validateflag(s[i]) == 0 && trigger == 1)
				str[j++] = s[i++];
			if (validateflag(s[i]) == 1 && trigger == 1)
				str[j] = s[i];
		}
		if (validateflag(s[i]) == 1 && trigger == 1)
			break ;
		i++;
	}
	*index = i + 1;
	return (str);
}
