/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:20:33 by srudman           #+#    #+#             */
/*   Updated: 2023/05/12 15:26:54 by srudman          ###   ########.fr       */
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
’f’ on the content of each node.*/

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*current;

	current = lst;
	while (current != NULL)
	{
		f(current->content);
		current = current->next;
	}
}
