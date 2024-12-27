/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 08:59:22 by christophed       #+#    #+#             */
/*   Updated: 2024/12/26 11:14:44 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../includes/push_swap.h"

// Function to push the first element of the stack b to the stack a
int	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*new;

	write(1, "pa\n", 3);
	if (!stack_b || !(*stack_b))
		return (-1);
	new = dclst_insert_node_start(stack_a, (*stack_b)->data);
	if (!new)
		return (-1);
	dclst_remove_node(stack_b, *stack_b);
	return (0);
}

// Function to push the first element of the stack a to the stack b
int	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*new;

	write(1, "pb\n", 3);
	if (!stack_a || !(*stack_a))
		return (-1);
	new = dclst_insert_node_start(stack_b, (*stack_a)->data);
	if (!new)
		return (-1);
	dclst_remove_node(stack_a, *stack_a);
	return (0);
}
