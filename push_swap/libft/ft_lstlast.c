/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 22:48:36 by srudman           #+#    #+#             */
/*   Updated: 2023/11/25 14:35:34 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;
*content = data contained in the node, any type of data is stored
*next = address of the next node or NULL if the next node is the last one.*/

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*current;
	t_list	*previous;

	current = lst;
	previous = NULL;
	while (current != NULL)
	{
		previous = current;
		current = current->next;
	}
	return (previous);
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

    int *value = (int *)ft_lstlast(list)->content;
    printf("%d\n", *value);

    return 0;
}
*/