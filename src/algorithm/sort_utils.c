/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 01:28:37 by alaaouam          #+#    #+#             */
/*   Updated: 2023/03/03 09:42:49 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <push_swap.h>
#include <algorithm.h>

void	ft_aproximity_a(t_stack **a)
{
	int		min;
	size_t	index;
	size_t	distance;

	min = ft_get_max_or_min(a, 'm');
	index = ft_get_index(a, min);
	distance = ft_stacksize(*a) / 2;
	while ((*a)->number != min)
	{
		if ((*a)->next->number == min)
			ft_swap(*a, 'a');
		else if (distance > index && ft_stacklast(*a)->number != min)
		{
			while ((*a)->number != min)
				ft_rotate(a, 'a');
		}
		else
		{
			while ((*a)->number != min)
				ft_reverse_rotate(a, 'a');
		}
	}
}

void	ft_aproximity_b(t_stack **a, t_stack **b)
{
	int		max;
	size_t	index;
	size_t	distance;

	max = ft_get_max_or_min(b, 'M');
	index = ft_get_index(b, max);
	distance = ft_stacksize(*b) / 2;
	while ((*b)->number != max)
	{
		if ((*b)->next->number == max)
			ft_swap(*b, 'b');
		else if (distance > index && ft_stacklast(*b)->number != max)
		{
			while ((*b)->number != max)
				ft_rotate(b, 'b');
		}
		else
		{
			while ((*b)->number != max)
				ft_reverse_rotate(b, 'b');
		}
	}
	ft_push(a, b, 'a');
}

void	ft_aproximity_big_a(t_stack **a, t_stack **b, int key)
{
	size_t	index;
	size_t	distance;

	index = ft_get_index(a, ft_smallest_closer(a, key));
	distance = ft_stacksize(*a) / 2;
	while (ft_find_smaller(a, key) && !ft_is_sorted(a))
	{
		if (ft_stacksize(*a) > 1 && (*a)->next->number <= key)
			ft_swap(*a, 'a');
		else if (distance > index && ft_stacklast(*a)->number > key)
			ft_rotate(a, 'a');
		else
			ft_reverse_rotate(a, 'a');
		if ((*a)->number <= key)
			ft_push(a, b, 'b');
	}
}

void	ft_simple_sort(t_stack **stack)
{
	t_stack	*current;
	t_stack	*compare;
	int		temp;

	current = *stack;
	temp = 0;
	while (current != NULL)
	{
		compare = *stack;
		while (compare != NULL)
		{
			if (current->number < compare->number)
			{
				temp = current->number;
				current->number = compare->number;
				compare->number = temp;
			}
			compare = compare->next;
		}
		current = current->next;
	}
}
