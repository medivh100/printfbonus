#include <stdio.h>

int  word_count(const char *s, char c)
{
    int  i;
    int  k;
    int  count;

    i = 0;
    k = 0;
    count = 0;
    while(s[i])
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

int  nextstring(char *s,char c, int *index)
{
    int count;

    count = 0;
    while(s[count] == c)
        count++;
    while(s[count] != c)
    {
        count++;
    }
    index = &count;
    return (count);
}

int main(void)
{
    int wc;
    int *index;

    index = NULL;
    char *str = "I amfdsf";
    wc = word_count(str, ' ');

    while(wc > 0)
    {
        nextstring(str, ' ', index);
        printf("%d", *index);
        wc--;
    }
}