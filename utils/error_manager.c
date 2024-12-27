/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 08:59:14 by christophed       #+#    #+#             */
/*   Updated: 2024/12/26 11:23:35 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../includes/push_swap.h"

// Function to check if the input is valid
int	check_input(char **args)
{
	int		i;
	char	*str;

	i = 0;
	while (args[i])
	{
		str = args[i];
		if (str == NULL)
			return (-1);
		while (*str == 32 || (*str >= 9 && *str <= 13))
			str++;
		if (*str == '-' || *str == '+')
			str++;
		if (*str == '\0')
			return (-1);
		while (*str)
		{
			if (!ft_isdigit(*str))
				return (-1);
			str++;
		}
		i++;
	}
	return (0);
}

// Function to check if the input is an int
int	is_int(long n)
{
	if (n < -2147483648 || n > 2147483647)
		return (0);
	return (1);
}

// Function to check if the input has a double
int	has_double(t_stack *head, int data)
{
	t_stack	*current;

	if (!head)
		return (0);
	current = head;
	if (current->data == data)
		return (1);
	current = current->next;
	while (current != head)
	{
		if (current->data == data)
			return (1);
		current = current->next;
	}
	return (0);
}
