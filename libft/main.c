#include "libft.h"
#include "libft_bonus.h"
#include <stdio.h>

int main(void)
{
	int a = 1;
	int b = 2;
	int c = 3;
	int d = 4;
	t_list *begin;

	t_list *elem1 = ft_lstnew(&a);
	t_list *elem2 = ft_lstnew(&b);
	t_list *elem3 = ft_lstnew(&c);
	t_list *elem4 = ft_lstnew(&d);
	ft_lstadd_front(&begin, elem4);
	ft_lstadd_front(&begin, elem3);
	ft_lstadd_front(&begin, elem2);
	ft_lstadd_front(&begin, elem1);

	printf("%d", ft_lstsize(begin));
}