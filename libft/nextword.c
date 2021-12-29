#include <stdio.h>

int    word_count(const char *s, char c)
{
    int    i;
    int    k;
    int    count;

    i = 0;
    k = 0;
    count = 0;
    while (s[i])
    {
        if (s[i] != c && k == 0)
        {
            count++;
            k = 1;
        }
        else if (s[i] == c)
        {
            k = 0;
        }
        i++;
    }
    return (count);
}

int    nextword(const char *s, char c, int *i)
{
    int    count;
    int index;

    count = 0;
    index = *i;
    while(s[index] == c)
    {
      index++;
    }
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
        return (count + 1);
      }
      
    }
    *i = index;
    return (count + 1);
}

int	main(void)
{
    const char	*str = "    I'm super fucking sick of this dumb shit   ";
    int			index;
    int			wc;

    index = 0;
    wc = word_count(str, ' ');
    while (wc > 0)
    {
        printf("%d\n", nextword(str, ' ', &index));
        wc--;
    }

}