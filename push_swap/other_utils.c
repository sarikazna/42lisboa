/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 18:20:26 by srudman           #+#    #+#             */
/*   Updated: 2023/11/26 18:38:23 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	find_mean(t_stack_node *head)
{
	t_stack_node	*current;
	int				stack_len;
	long long		sum;

	current = head;
	stack_len = ft_stacksize(current);
	sum = 0;
	while (current)
	{
		sum += current->value;
		current = current->next;
	}
	return (sum/stack_len);
}

t_stack_node	*get_min(t_stack_node *head)
{
	t_stack_node	*min_node;
}

t_stack_node	*get_max(t_stack_node *head)
{

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
*/