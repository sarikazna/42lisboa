/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 19:31:16 by srudman           #+#    #+#             */
/*   Updated: 2023/05/12 15:00:49 by srudman          ###   ########.fr       */
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

/* Deletes and frees the given node and every
successor of that node, using the function ’del’
and free(3).
Finally, the pointer to the list must be set to
NULL. */

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*buffer;

	if (!lst || !del)
		return ;
	current = *lst;
	while (current != NULL)
	{
		buffer = current->next;
		del(current->content);
		free(current);
		current = buffer;
	}
	*lst = NULL;
}
