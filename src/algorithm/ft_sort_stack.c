/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 18:02:08 by alaaouam          #+#    #+#             */
/*   Updated: 2023/02/28 14:30:41 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <push_swap.h>
#include <algorithm.h>

void	ft_small_sort(t_stack **stack, char id)
{
	while (!ft_is_sorted(stack))
	{
		if ((*stack)->number > (*stack)->next->number
			&& (*stack)->number > ft_stacklast(*stack)->number)
			ft_rotate(stack, id);
		else if (((*stack)->number > (*stack)->next->number
				|| (*stack)->number < (*stack)->next->number)
			&& (*stack)->number > ft_stacklast(*stack)->number)
			ft_reverse_rotate(stack, id);
		else if (((*stack)->number > (*stack)->next->number
				|| (*stack)->number < (*stack)->next->number)
			&& (*stack)->number < ft_stacklast(*stack)->number)
			ft_swap(*stack, id);
	}
}

static void	ft_general_sort(t_stack **a, t_stack **b, t_stack **chunks)
{
	size_t	size;

	size = ft_stacksize(*a);
	if (size < 10)
	{
		while (!ft_is_sorted(a))
			ft_sort_under_10(a, b);
	}
	else if (size <= 100)
		ft_sort_under_100(a, b, chunks);
	else
		ft_sort_over_100(a, b, chunks);
}

void	ft_sort_stack(t_stack **a, t_stack **b, t_stack **chunks)
{
	size_t	size;

	size = ft_stacksize(*a);
	if (size <= 3)
		ft_small_sort(a, 'a');
	else
		ft_general_sort(a, b, chunks);
}
