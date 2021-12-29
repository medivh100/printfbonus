#include "libft.h"
#include "libft_bonus.h"
#include <stdio.h>

void    ft_lstadd_back(t_list **lst, t_list *new)
{
    while(*lst)
    {
        lst = &(*lst)->next;
    }
    *lst = new;
    new->next = NULL;
}
