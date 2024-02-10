/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:33:13 by srudman           #+#    #+#             */
/*   Updated: 2024/02/10 13:52:11 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Function stack_init checks for syntax errors, converts string 
// arguments into 'long', then checks for 'int' overflow, and 
// duplicates. If everything is okay, it builds a stack.

t_stack_node	*stack_init(t_stack_node *a, int stack_len, char **nptr)
{
	long	tmp;

	tmp = 0;
	while (stack_len--)
	{
		if (!syntax_error(*nptr))
		{
			free_list(a);
			write (2, "Error\n", 6);
			return (NULL);
		}
		tmp = ft_atol(*nptr);
		if (tmp < INT_MIN || tmp > INT_MAX || contains_duplicate(a, (int) tmp))
		{
			free_list(a);
			write (2, "Error\n", 6);
			return (NULL);
		}
		ft_nodeadd_back(&a, (ft_nodenew((int) tmp)));
		nptr++;
	}
	return (a);
}

/*
// Main to test stack_init
#include <stdio.h>
int main(void) 
{
    t_stack_node *a = NULL;
    char *arguments[] = {"3", "8", "7", "1", "2"};
    int argum_len = sizeof(arguments) / sizeof(arguments[0]);

    a = stack_init(a, argum_len, arguments);

    if (!a)
    {
        printf("Error initializing the stack.\n");
        return (1);
    }
    printf("Stack initialized successfully. Contents:\n");
    
	while (a != NULL)
	{
    printf("Value: %d, Position: %d\n", a->value, a->position);
    a = a->next;
    }
    return (0);
}
*/