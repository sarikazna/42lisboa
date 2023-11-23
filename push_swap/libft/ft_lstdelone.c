/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:31:38 by srudman           #+#    #+#             */
/*   Updated: 2023/05/12 15:00:25 by srudman          ###   ########.fr       */
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

/*Takes as a parameter a node and frees the memory of
the node’s content using the function ’del’ given
as a parameter and free the node. The memory of
’next’ must not be freed.*/

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	del(lst->content);
	free(lst);
}
