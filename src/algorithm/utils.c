/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 01:25:02 by alaaouam          #+#    #+#             */
/*   Updated: 2023/02/28 08:28:44 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <push_swap.h>
#include <algorithm.h>

int	ft_get_max_or_min(t_stack **stack, char id)
{
	t_stack	*current;
	int		number;

	current = *stack;
	number = current->number;
	while (current != NULL)
	{
		if (current->number > number && id == 'M')
			number = current->number;
		else if (current->number < number && id == 'm')
			number = current->number;
		current = current->next;
	}
	return (number);
}

int	ft_get_key(t_stack **stack, size_t div)
{
	static size_t	iteration;
	size_t			chunk;
	t_stack			*current;
	size_t			index;
	size_t			key;

	current = *stack;
	if (!iteration || iteration == div)
		iteration = 0;
	chunk = iteration * (ft_stacksize(*stack) / div);
	index = (ft_stacksize(*stack) / div) + chunk;
	key = 0;
	while (index && current != NULL)
	{
		key = current->number;
		current = current->next;
		index--;
	}
	if (iteration != 0)
		chunk = 0;
	iteration++;
	return (key);
}

ssize_t	ft_get_index(t_stack **stack, int nbr)
{
	ssize_t	index;
	int		found;
	t_stack	*current;

	index = 0;
	found = -1;
	current = *stack;
	while (current != NULL)
	{
		if (nbr == current->number)
		{
			found = current->number;
			index++;
			break ;
		}
		index++;
		current = current->next;
	}
	if (nbr == found)
		return (index);
	return (-1);
}
