/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive_sort_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 08:44:22 by christophed       #+#    #+#             */
/*   Updated: 2024/12/27 08:55:15 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../includes/push_swap.h"

// Function to find the median value
// in the len first nodes of the stack head
int	pivot_value(t_stack *head, int len)
{
	t_stack	*current;
	t_stack	*pivot;
	int		n_inferior_values;
	int		j;
	int		i;

	pivot = head;
	j = 0;
	while (j++ < len)
	{
		current = head;
		n_inferior_values = 0;
		i = 0;
		while (i++ < len)
		{
			if (current->data < pivot->data)
				n_inferior_values++;
			current = current->next;
		}
		if (n_inferior_values == len / 2)
			return (pivot->data);
		pivot = pivot->next;
	}
	return (-2147483647);
}

// Function to sort the remainder in stack_b
int	sort_pushed_b(t_stack **a, t_stack **b, int len)
{
	int		treshold;
	int		pushed;

	if (len <= 2 || is_reverse_sorted(*b, len))
	{
		if (len == 2)
			sort_2b(b);
		if (get_back_to_a(a, b, len) < 0)
			return (-1);
	}
	else
	{
		treshold = pivot_value(*b, len);
		pushed = divide_b_by_treshold(a, b, len, treshold);
		if (pushed < 0)
			return (-1);
		if (pushed > 0)
			if (sort_pushed_a(a, b, pushed) < 0)
				return (-1);
		len = len / 2;
		if (sort_pushed_b(a, b, len) < 0)
			return (-1);
	}
	return (0);
}

// Function to sort the remainder in stack_a
int	sort_pushed_a(t_stack **a, t_stack **b, int len)
{
	int		treshold;
	int		pushed;

	if (len == 1 || is_sorted(*a, len))
		return (0);
	if (len == 2)
		sort_2a(a);
	else
	{
		treshold = pivot_value(*a, len);
		pushed = divide_a_by_treshold(a, b, len, treshold);
		if (pushed < 0)
			return (-1);
		len = len / 2 + len % 2;
		if (len > 1)
			if (sort_pushed_a(a, b, len) < 0)
				return (-1);
		if (pushed > 0)
			if (sort_pushed_b(a, b, pushed) < 0)
				return (-1);
	}
	return (0);
}

// Function to sort stack_a using recursives functions
int	recursive_sort(t_stack **a, t_stack **b, int len)
{
	int		treshold;
	int		pushed;

	if (is_sorted(*a, len))
		return (0);
	if (len == 2)
		return (sort_2a(a), 0);
	if (len == 3)
		return (sort_3(a), 0);
	else
	{
		treshold = pivot_value(*a, len);
		pushed = first_divide_a_by_treshold(a, b, len, treshold);
		if (pushed < 0)
			return (-1);
		len = len / 2 + len % 2;
		if (len > 1)
			if (recursive_sort(a, b, len) < 0)
				return (-1);
		if (pushed > 0)
			if (sort_pushed_b(a, b, pushed) < 0)
				return (-1);
	}
	return (0);
}

// Function to sort the stack_a with the recursive method
// Returns 0 if the sort is successful
// Returns -1 if the process has failed
int	push_swap(t_stack **a, t_stack **b)
{
	int		len;

	if (!a || !*a)
		return (dclst_clear(a), 0);
	len = dclst_count_nodes(*a);
	if (is_sorted(*a, len))
		return (dclst_clear(a), dclst_clear(b), 0);
	if (recursive_sort(a, b, len) < 0)
		return (dclst_clear(a), dclst_clear(b), -1);
	if (!is_sorted(*a, len) || *b)
		write(1, "Sort has failed\n", 16);
	return (dclst_clear(a), dclst_clear(b), 0);
}
