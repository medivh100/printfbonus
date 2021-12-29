#include "libft.h"
#include "libft_bonus.h"

t_list  *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list  *newlst;
    t_list  *ptr;

    if (!lst)
        return (NULL);
    if (!(newlst = ft_lstnew(f(lst->content))))
    {
        ft_lstclear(&lst, del);
        return (NULL);
    }
    lst = lst->next;
    ptr = newlst;
    while (lst)
    {
        if (!(newlst = ft_lstnew(f(lst->content))))
        {
            ft_lstclear(&lst, del);
            ft_lstclear(&ptr, del);
            return (NULL);
        }
        lst = lst->next;
        ft_lstadd_back(&ptr, newlst);
    }
    return (ptr);
}