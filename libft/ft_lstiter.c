#include "libft_bonus.h"
#include "libft.h"

void    ft_lstiter(t_list *lst, void (f)(void *))
{
    while (lst)
    {
        f(lst->content);
        lst = lst->next;
    }
}