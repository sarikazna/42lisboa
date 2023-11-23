/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 21:56:33 by srudman           #+#    #+#             */
/*   Updated: 2023/05/08 21:11:21 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Allocates with malloc and returns a new node. The member variable 
’content’ is initialized with  the value of the parameter ’content’. 
The variable ’next’ is initialized to NULL. */

/*
typedef	struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;
*/

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

/*
#include <stdio.h>
int main(void)
{
    int content_value = 42;
    t_list *node = ft_lstnew(&content_value);
    if (node == NULL)
    {
        printf("Error: failed to create node\n");
        return 1;
    }
    printf("Node content: %d\n", *(int *)(node->content));
    return 0;
}
*/