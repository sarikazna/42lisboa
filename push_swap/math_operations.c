/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 18:20:26 by srudman           #+#    #+#             */
/*   Updated: 2024/01/21 21:02:12 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				ft_stacksize(t_stack_node *first);

// handle single plus! if next position exists?
long	ft_atol(const char *nptr)
{
	int	minus;
	long	result;

	minus = 1;
	result = 0;
	while (*nptr != '\0')
	{
		while ((*nptr >= '\t' && *nptr <= '\r') || *nptr == ' ')
			nptr++;
		if (*nptr == '+' || *nptr == '-')
		{
			if (*nptr == '-')
				minus = -1;
			nptr++;
		}
		while (*nptr >= '0' && *nptr <= '9')
		{
			result = result * 10 + (*nptr - '0');
			nptr++;
		}
		break ;
	}
	return (result * minus);
}

t_stack_node	*get_min(t_stack_node *head)
{
	t_stack_node	*current;
	t_stack_node	*min_node;

	min_node = head;
    current = head;
	while (current)
	{	
		if (current->value < min_node->value)
			min_node = current;
		current = current->next;
	}
	return (min_node);
}

t_stack_node	*get_max(t_stack_node *head)
{
	t_stack_node	*current;
	t_stack_node	*max_node;

	max_node = head;
    current = head;
	while (current)
	{	
		if (current->value > max_node->value)
			max_node = current;
		current = current->next;
	}
	return (max_node);
}

t_stack_node    *set_cheapest(t_stack_node **a)
{
    long            cheapest_value;
    t_stack_node    *current;
    t_stack_node    *current_cheapest;

    current = (*a);
    cheapest_value = LONG_MAX;
    current_cheapest = current;
    while (current)
    {
        if (current->push_cost < cheapest_value)
        {
            cheapest_value = current->push_cost;
            current_cheapest = current;
        }
        current = current->next;
    }
    current_cheapest->cheapest = true;
    return (current_cheapest);
}

// #include <stdio.h>
// int main(void)
// {
//     printf("%ld\n", ft_atol(" -346k446"));
//     return (0);
// }

/*
void print_stack(t_stack_node* head) {
    t_stack_node* current = head;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

// Function to free the linked list
void free_list(t_stack_node* head) {
    t_stack_node* current = head;
    while (current != NULL) {
        t_stack_node* next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    // Create a linked list
    t_stack_node* head = malloc(sizeof(t_stack_node));
    head->value = 2;
    head->next = malloc(sizeof(t_stack_node));
    head->next->value = 100;
    head->next->next = malloc(sizeof(t_stack_node));
    head->next->next->value = 3;
    head->next->next->next = NULL;

    // Print the original linked list
    printf("Original Linked List: ");
    print_stack(head);

    // Find the mean and print the result
    int mean = find_mean(head);
    printf("Mean: %d\n", mean);

    // Free the allocated memory
    free_list(head);

    return 0;
}




void print_stack(t_stack_node *head) {
    t_stack_node *current = head;

    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }

    printf("\n");
}

int main() {
    // Create a sample stack
    t_stack_node *stack = malloc(sizeof(t_stack_node));
    stack->value = 5;
    stack->next = malloc(sizeof(t_stack_node));
    stack->next->value = -2;
    stack->next->next = malloc(sizeof(t_stack_node));
    stack->next->next->value = 8;
    stack->next->next->next = NULL;

    // Print the original stack
    printf("Original Stack:\n");
    print_stack(stack);

    // Get the minimum node
    t_stack_node *min_node = get_min(stack);

    // Print the minimum node's value
    printf("Minimum Node Value: %d\n", min_node->value);

    // Free the allocated memory
    free_list(stack);

    return 0;
}
*/