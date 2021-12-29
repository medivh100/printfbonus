#include "libft.h"
#include <stdlib.h>

size_t	wordcount(const char *s, char c)
{
	size_t	count;
	size_t	trigger;

	count = 0;
	trigger = 0;
	while (*s)
	{
		if (*s != c && trigger == 0)
		{
			count++;
			trigger = 1;
		}
		if (*s == c && trigger == 1)
			trigger = 0;
		s++;
	}
	return (count);
}

size_t	nextword(const char *s, char c, size_t *i)
{
	size_t	count;
	size_t	index;

	count = 0;
	index = *i;
	while (s[index] == c)
		index++;
	while (s[index])
	{
		if (s[index] != c)
		{
			count++;
			index++;
		}
		if (s[index] == c)
		{
			*i = index;
			return ((count + 1));
		}
	}
	*i = index;
	return (count + 1);
}

char	**ft_split(const char *s, char c)
{
	char	**str;
	size_t	wc;
	size_t	index;
	size_t	i;
	size_t	size;

	i = 0;
	index = 0;
	wc = wordcount(s, c);
	str = malloc((wc + 1) * sizeof(char *));
	while (i < wc)
	{
		size = nextword(s, c, &index);
		str[i] = ft_substr(s, (index - (size - 1)), (size - 1));
		i++;
	}
	str[i] = NULL;
	return (str);
}
#include <stdio.h>
int main(void)
{
	char **str;

	str = ft_split("  I am sick   ", ' ');
	//printf("%zu\n", wordcount("I am sick of this dumb fucking shit", ' '));

	printf("%s\n", str[0]);
	printf("%s\n", str[1]);
	printf("%s\n", str[2]);
	printf("%s\n", str[3]);
	printf("%s\n", str[4]);
	//printf("%s\n", str[5]);
	///printf("%s\n", str[6]);
	//printf("%s\n", str[7]);
	//printf("%s\n", str[8]);
	//printf("%s\n", str[9]);
	//printf("%s\n", str[10]);
	//printf("%s\n", str[11]);
	//printf("%s\n", str[12]);

	return (0);
}