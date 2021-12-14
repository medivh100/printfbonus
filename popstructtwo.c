#include "libft.h"
#include "ft_printf.h"


// typedef struct t_flags
// {
// 	int		flag;
// 	int		plus;
// 	int		sharp;
// 	int		space;
// } t_flags;

t_flags	popstructtwo(char *s, t_flags format)
{
	while (*s)
	{
		if (*s == '+')
			format.plus = 1;
		if (*s == '#')
			format.sharp = 1;
		if (*s == ' ')
			format.space = 1;
		if (validateflag(*s) == 1)
			format.flag = *s;
		s++;
	}
	return (format);
}