#include "libft.h"
#include "ft_printf.h"

static char	*negnumbase(long long n, char *str)
{
	size_t		max;
	const char	*base;

	base = "0123456789abcdef";
	max = memsizebase(n);
	str[max] = '\0';
	while (max > 0)
	{
		if (n < 0)
		{
			str[0] = '-';
			n = -n;
			max--;
		}
		str[max] = base[n % 16];
		n = n / 16;
		max--;
	}
	return (str);
}

static char	*posnumbase(long long n, char *str)
{
	size_t		max;
	const char	*base;

	base = "0123456789abcdef";
	max = memsizebase(n);
	str[max] = '\0';
	while (max > 0)
	{
		str[max - 1] = base[n % 16];
		n = n / 16;
		max--;
	}
	return (str);
}

char	*ft_itoa_base(long long n)
{
	char	*str;
	size_t	max;

	max = memsizebase(n);
	if (n == 0)
	{
		str = malloc(2 * sizeof(char));
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	str = malloc((memsizebase(n) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	if (n < 0)
		str = negnumbase(n, str);
	else
		str = posnumbase(n, str);
	return (str);
}