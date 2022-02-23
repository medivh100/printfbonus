/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yst-laur <yst-laur@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 17:02:26 by yst-laur          #+#    #+#             */
/*   Updated: 2022/01/28 17:02:30 by yst-laur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*ptr;

	if (!lst)
		return (NULL);
	newlst = ft_lstnew(f(lst->content));
	if (newlst == NULL)
		return (NULL);
	lst = lst->next;
	ptr = newlst;
	while (lst)
	{
		newlst = ft_lstnew(f(lst->content));
		if (newlst == NULL)
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
