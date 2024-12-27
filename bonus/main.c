/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 15:56:00 by christophed       #+#    #+#             */
/*   Updated: 2024/12/26 15:57:05 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../includes/push_swap.h"

// Function to load the doubly circular linked list with the input values
t_stack	*dclst_load(char **args)
{
	t_stack	*head;
	t_stack	*new;
	long	data;
	int		i;

	head = NULL;
	i = 0;
	while (args[i])
	{
		data = ft_atoi_long(args[i]);
		if (is_int(data) == 0 || has_double(head, (int) data) != 0)
			return (dclst_clear(&head), NULL);
		new = dclst_insert_node_end(&head, (int) data);
		if (!new)
			return (dclst_clear(&head), NULL);
		i++;
	}
	return (head);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**args;
	int		i;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		return (0);
	else if (ac == 2)
		args = ft_split(av[1], ' ');
	else
		args = av + 1;
	if (check_input(args) == -1)
		return (write(2, "Error\n", 6), 2);
	stack_a = dclst_load(args);
	if (stack_a == NULL || push_swap(&stack_a, &stack_b) < 0)
		return (write(2, "Error\n", 6), 2);
	if (ac == 2)
	{
		i = 0;
		while (args[i])
			free(args[i++]);
		free(args);
	}
	return (0);
}
