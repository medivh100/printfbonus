#include "ft_printf_bonus.h"
#include "libft.h"
#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
    printf("Test 1\n");
    printf("%%");
    printf("\n");
    ft_printf("%%");
    printf("\n");

    printf("Test 2\n");
    printf("100%%");
    printf("\n");
    ft_printf("100%%");
    printf("\n");

    printf("Test 3\n");
    printf("%%c%%s%%p%%d%%i%%u%%x%%X%%");
    printf("\n");
    ft_printf("%%c%%s%%p%%d%%i%%u%%x%%X%%");
    printf("\n");

    printf("Test 4\n");
    printf("%c - %s - %p %d - %i - %u - %x %X %%", 'a', "test", (void *)0xdeadc0de, 20, -20, -1, -1, 200000000);
    printf("\n");
    ft_printf("%c - %s - %p %d - %i - %u - %x %X %%", 'a', "test", (void *)0xdeadc0de, 20, -20, -1, -1, 200000000);
    printf("\n");

    printf("Test 5\n");
    printf("%c - %s - %p %d - %i - %u - %x %X %%", '\0', "test", (void *)-1, 20, -20, -1, -1, 200000000);
    printf("\n");
    ft_printf("%c - %s - %p %d - %i - %u - %x %X %%", '\0', "test", (void *)-1, 20, -20, -1, -1, 200000000);
    printf("\n");

    return (0);
}