/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 12:22:27 by alaaouam          #+#    #+#             */
/*   Updated: 2023/02/28 08:24:18 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <push_swap.h>

int	ft_push(t_stack **a, t_stack **b, char id)
{
	size_t	size;

	if (id == 'a')
	{
		size = ft_stacksize(*b);
		if (size == 0)
			return (0);
		ft_stackadd_front(a, *b);
		ft_remove_node(b, *b);
		ft_printf("pa\n");
		return (1);
	}
	else if (id == 'b')
	{
		size = ft_stacksize(*a);
		if (size == 0)
			return (0);
		ft_stackadd_front(b, *a);
		ft_remove_node(a, *a);
		ft_printf("pb\n");
		return (1);
	}
	return (0);
}
