/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:29:10 by srudman           #+#    #+#             */
/*   Updated: 2023/05/11 17:52:12 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;
*/

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current;

	if (*lst == NULL)
		*lst = new;
	else
	{
		current = *lst;
		while (current->next != NULL)
			current = current->next;
		current->next = new;
	}
}

/*
#include <stdio.h>
int main()
{
    t_list *list = NULL;
    int a = 1, b = 2, c = 3;

    // Create new nodes
    t_list *node1 = ft_lstnew(&a);
    t_list *node2 = ft_lstnew(&b);
    t_list *node3 = ft_lstnew(&c);

    //
    ft_lstadd_back(&list, node1);
    ft_lstadd_back(&list, node2);
    ft_lstadd_back(&list, node3);
	
    // Traverse the list and print its contents
    t_list *current = list;
    while (current != NULL)
    {
        int *value = (int *)current->content;
        printf("%d\n", *value);
        current = current->next;
    }
    return 0;
}
*/