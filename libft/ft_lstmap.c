/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:29:29 by srudman           #+#    #+#             */
/*   Updated: 2023/05/12 16:17:15 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* this is the header file
typedef	struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;
*/

/*Iterates the list ’lst’ and applies the function
’f’ on the content of each node. Creates a new
list resulting of the successive applications of
the function ’f’. The ’del’ function is used to
delete the content of a node if needed.*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *),	void (*del)(void *))
{
	t_list	*current;
	t_list	*new_node;
	t_list	*new_list;

	current = lst;
	new_list = NULL;
	while (current != NULL)
	{
		new_node = ft_lstnew(f(current->content));
		if (!new_node)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		current = current->next;
	}
	return (new_list);
}
