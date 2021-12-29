#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	slen;
	size_t	i;
	char *rs;

	slen = ft_strlen(s);
	i = 0;
	if (slen < start)
		return (ft_strdup(""));
	while (s[i] && (i + (size_t) start) < len)
		i++;
	rs = malloc(i * sizeof(char));
	i = 0;
	while (s[i] && (i + (size_t) start) < len)
	{
		rs[i] = s[start + i];
		i++;
	}
	return (rs);
}

#include <stdio.h>
int main(void)
{
	char	str[] = "0123456789";

	char *s = ft_substr(str, 0, 10);
	printf("%s\n", s);

	s = ft_substr(str, 7, 10);
	printf("%s\n", s);
}