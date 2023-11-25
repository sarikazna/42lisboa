/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:25:17 by srudman           #+#    #+#             */
/*   Updated: 2023/11/25 14:34:50 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* this is the header file
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;
*content = data contained in the node, any type of data is stored
*next = address of the next node or NULL if the next node is the last one.*/

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
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
    ft_lstadd_front(&list, node1);
    ft_lstadd_front(&list, node2);
    ft_lstadd_front(&list, node3);

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