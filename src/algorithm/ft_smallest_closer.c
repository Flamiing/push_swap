/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_smallest_closer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 18:48:12 by alaaouam          #+#    #+#             */
/*   Updated: 2023/02/28 08:28:02 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <push_swap.h>
#include <algorithm.h>

static int	ft_equal_or_less(t_stack **stack, int key)
{
	t_stack	*curr;
	int		found;

	curr = *stack;
	found = 0;
	while (curr != NULL)
	{
		if (curr->number <= key)
			found = 1;
		curr = curr->next;
	}
	return (found);
}

static t_stack	*ft_close_to_end(t_stack **stack, int key)
{
	t_stack	*curr;
	t_stack	*closest;

	curr = *stack;
	closest = *stack;
	while (curr != NULL)
	{
		if (curr->number <= key)
			closest = curr;
		curr = curr->next;
	}
	return (closest);
}

static t_stack	*ft_close_to_start(t_stack **stack, int key)
{
	t_stack	*curr;

	curr = *stack;
	while (curr != NULL)
	{
		if (curr->number <= key)
			return (curr);
		curr = curr->next;
	}
	return (NULL);
}

int	ft_smallest_closer(t_stack **stack, int key)
{
	t_stack	*close_start;
	t_stack	*close_end;
	size_t	distance_start;
	size_t	distance_end;
	size_t	size;

	size = ft_stacksize(*stack);
	if (!ft_equal_or_less(stack, key))
		return (0);
	close_end = ft_close_to_end(stack, key);
	close_start = ft_close_to_start(stack, key);
	distance_start = ft_get_index(stack, close_start->number) - 1;
	distance_end = (size - ft_get_index(stack, close_end->number)) + 1;
	if (distance_start <= distance_end)
		return (close_start->number);
	else
		return (close_end->number);
}
