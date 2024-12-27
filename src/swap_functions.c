/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 08:59:45 by christophed       #+#    #+#             */
/*   Updated: 2024/12/26 11:15:05 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../includes/push_swap.h"

// Function to swap the first two elements of stack_a
void	sa(t_stack **a)
{
	if (!a || !*a || (*a)->next == *a)
		return ;
	write(1, "sa\n", 3);
	dclst_swap_nodes(a, *a, (*a)->next);
}

// Function to swap the first two elements of stack b
void	sb(t_stack **b)
{
	if (!b || !*b || (*b)->next == *b)
		return ;
	write(1, "sb\n", 3);
	dclst_swap_nodes(b, *b, (*b)->next);
}

// Function to swap the first two elements of stack_a
// and swap the first two elements of swap_b
void	ss(t_stack **a, t_stack **b)
{
	if (!a || !*a || (*a)->next == *a)
		return ;
	if (!b || !*b || (*b)->next == *b)
		return ;
	write(1, "ss\n", 3);
	dclst_swap_nodes(a, *a, (*a)->next);
	dclst_swap_nodes(b, *b, (*b)->next);
}
