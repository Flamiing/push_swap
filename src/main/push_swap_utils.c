/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:29:21 by alaaouam          #+#    #+#             */
/*   Updated: 2023/03/01 12:23:09 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <push_swap.h>
#include <stdlib.h>

int	ft_has_repeated_numbers(t_stack **stack)
{
	t_stack	*current;
	t_stack	*check;
	size_t	count;

	current = *stack;
	while (current != NULL)
	{
		count = 0;
		check = *stack;
		while (check != NULL)
		{
			if (current->number == check->number)
				count++;
			check = check->next;
		}
		if (count > 1)
			return (1);
		current = current->next;
	}
	return (0);
}

void	ft_exit_program(int error, t_stack **stack)
{
	if (stack)
		ft_free_stack(stack);
	if (error != EXIT_SUCCESS)
		write(2, "Error\n", 6);
	exit(error);
}
