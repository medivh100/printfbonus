#include "libft.h"
#include "ft_printf_bonus.h"

t_flags	popstructtwo(const char *s, t_flags format)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] >= '0' && s[i] <= '9')
			format.fieldwidth = findfieldwidth(s);
		if (s[i] == '+')
			format.plus = 1;
		if (s[i] == '#')
			format.sharp = 1;
		if (s[i] == ' ')
			format.space = 1;
		if (validateflag(s[i]) == 1)
			format.flag = s[i];
		i++;
	}
	return (format);
}