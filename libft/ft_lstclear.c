#include "libft.h"
#include "libft_bonus.h"

void    ft_lstclear(t_list **lst, void del(void *))
{
    t_list *ptr;
    while (*lst)
    {
        ptr = (*lst)->next;
        del((*lst)->content);
        free(*lst);
        *lst = ptr;
    }
    lst = NULL;
}