/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:22:37 by alaaouam          #+#    #+#             */
/*   Updated: 2023/02/28 08:24:30 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <push_swap.h>

int	ft_rotate(t_stack **stack, char id)
{
	t_stack	*last;
	t_stack	*temp;

	temp = *stack;
	last = ft_stacklast(temp);
	last->next = *stack;
	*stack = temp->next;
	temp->next = NULL;
	if (id == 'a')
	{
		ft_printf("ra\n");
		return (1);
	}
	else if (id == 'b')
	{
		ft_printf("rb\n");
		return (1);
	}
	return (0);
}

int	ft_rotate_a_and_b(t_stack **a, t_stack **b)
{
	ft_rotate(a, 0);
	ft_rotate(b, 0);
	ft_printf("rr\n");
	return (1);
}
