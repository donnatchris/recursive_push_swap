/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dclst2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 08:59:05 by christophed       #+#    #+#             */
/*   Updated: 2024/12/26 11:53:45 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../includes/push_swap.h"

// Function to print the doubly circular linked list 
void	dclst_print(t_stack *head)
{
	t_stack	*current;

	if (head)
	{
		current = head;
		while (current->next != head)
		{
			ft_printf("%d ", current->data);
			current = current->next;
		}
		ft_printf("%d", current->data);
	}
	ft_printf("\n");
}

// Function to find the highest value in the doubly circular linked list
t_stack	*dclst_find_max(t_stack *head)
{
	t_stack	*current;
	t_stack	*max;

	if (!head)
		return (NULL);
	current = head;
	max = head;
	while (current->next != head)
	{
		if (current->data > max->data)
			max = current;
		current = current->next;
	}
	if (current->data > max->data)
		max = current;
	return (max);
}

// Function to find the lowest value in the doubly circular linked list
t_stack	*dclst_find_min(t_stack *head)
{
	t_stack	*current;
	t_stack	*min;

	if (!head)
		return (NULL);
	current = head;
	min = head;
	while (current->next != head)
	{
		if (current->data < min->data)
			min = current;
		current = current->next;
	}
	if (current->data < min->data)
		min = current;
	return (min);
}

// Function to find the position of a node in the doubly circular linked list
// Returns the position of the node in the list
// or -1 if the node is not in the list
int	dclst_find_node_pos(t_stack *head, t_stack *node)
{
	t_stack	*current;
	int		position;

	if (!head || !node)
		return (-1);
	current = head;
	position = 0;
	while (current != node)
	{
		position++;
		current = current->next;
		if (current == head)
			return (-1);
	}
	return (position);
}

// Function to find a node by its position in the doubly circular linked list
t_stack	*dclst_find_node_with_pos(t_stack *head, int position)
{
	t_stack	*current;
	int		i;

	if (!head)
		return (NULL);
	current = head;
	i = 0;
	while (i < position)
	{
		current = current->next;
		i++;
	}
	return (current);
}
