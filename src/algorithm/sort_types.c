/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_types.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 01:32:02 by alaaouam          #+#    #+#             */
/*   Updated: 2023/03/01 23:57:30 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <algorithm.h>

void	ft_sort_under_10(t_stack **a, t_stack **b)
{
	while (!ft_is_sorted(a) && ft_stacksize(*a) > 3)
	{
		ft_aproximity_a(a);
		ft_push(a, b, 'b');
	}
	if (!ft_is_sorted(a) && ft_stacksize(*a) <= 3)
		ft_small_sort(a, 'a');
	while (ft_stacksize(*b) > 0)
		ft_push(a, b, 'a');
}

void	ft_sort_under_100(t_stack **a, t_stack **b, t_stack **chunks)
{
	int		key;
	size_t	count;

	count = 0;
	if (!ft_is_sorted(chunks))
		ft_simple_sort(chunks);
	while (count != 5)
	{
		key = ft_get_key(chunks, 6);
		ft_aproximity_big_a(a, b, key);
		count++;
	}
	while (!ft_is_sorted(a) && ft_stacksize(*a) > 3)
	{
		ft_aproximity_a(a);
		ft_push(a, b, 'b');
	}
	if (!ft_is_sorted(a) && ft_stacksize(*a) <= 3)
		ft_small_sort(a, 'a');
	while (ft_stacksize(*b) > 0)
		ft_aproximity_b(a, b);
}

void	ft_sort_over_100(t_stack **a, t_stack **b, t_stack **chunks)
{
	int		key;
	size_t	count;

	count = 0;
	if (!ft_is_sorted(chunks))
		ft_simple_sort(chunks);
	while (count != 11)
	{
		key = ft_get_key(chunks, 12);
		ft_aproximity_big_a(a, b, key);
		count++;
	}
	while (!ft_is_sorted(a) && ft_stacksize(*a) > 3)
	{
		ft_aproximity_a(a);
		ft_push(a, b, 'b');
	}
	if (!ft_is_sorted(a) && ft_stacksize(*a) <= 3)
		ft_small_sort(a, 'a');
	while (ft_stacksize(*b) > 0)
		ft_aproximity_b(a, b);
}
