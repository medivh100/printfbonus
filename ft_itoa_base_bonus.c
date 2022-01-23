#include "libft.h"
#include "ft_printf_bonus.h"
#include "ft_printf.h"

static char	*posnumbase(unsigned long long n, char *str)
{
	size_t		max;
	const char	*base;

	base = "0123456789abcdef";
	max = memsizebaseuns(n);
	str[max] = '\0';
	while (max > 0)
	{
		str[max - 1] = base[n % 16];
		n = n / 16;
		max--;
	}
	return (str);
}

char	*ft_itoa_base(unsigned long long n)
{
	char	*str;
	size_t	max;

	max = memsizebaseuns(n);
	if (n == 0)
	{
		str = malloc(2 * sizeof(char));
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	str = malloc((max + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	else
		str = posnumbase(n, str);
	return (str);
}