/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:33:13 by srudman           #+#    #+#             */
/*   Updated: 2023/11/27 15:56:31 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// handle errors: integre overflow, dubplicates, syntax errors (+, -)
// if it's string, convert it into long integer
// append the nodes to stack 'a'
// run a check if stack 'a' is sorted, if it's not sorted, implement our
// sorting algoritm
// ALGORITM
// Check for 2 numbers, if yes. Simply swap the numbers.
// Check for 3 numbers, if so implement our simple 'sort three' algorithm.
// check if stack has more than 3 numbers, implement our Turk Algorithm.

// Function stack_init checks for syntax errors, converts string arguments into 
// 'long', then checks for 'int' overflow, and duplicates. If everything is okay,
// it builds a stack

t_stack_node	*stack_init(t_stack_node *a, int stack_len, char **nptr)
{	
	long			tmp;
	
	tmp = 0;
	while (stack_len--)
	{
		if (!syntax_error(*nptr))
		{
			free_list(a);
			return (NULL);
		}
		tmp = ft_atol(*nptr);
		if (tmp < INT_MIN || tmp > INT_MAX || contains_duplicate(a, (int) tmp))
		{
			free_list(a);
			return (NULL);
		}
		ft_nodeadd_back(&a, (ft_nodenew((int) tmp)));
		nptr++;
	}
	return (a);
}

/*
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