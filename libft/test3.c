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