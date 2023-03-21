/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:14:01 by alaaouam          #+#    #+#             */
/*   Updated: 2023/02/28 08:24:24 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <push_swap.h>

int	ft_reverse_rotate(t_stack **stack, char id)
{
	t_stack	*last;
	t_stack	*temp;

	temp = *stack;
	last = ft_stacklast(temp);
	while (temp->next != NULL && temp->next != last)
		temp = temp->next;
	temp->next = NULL;
	ft_stackadd_front(stack, last);
	free(last);
	if (id == 'a')
	{
		ft_printf("rra\n");
		return (1);
	}
	else if (id == 'b')
	{
		ft_printf("rrb\n");
		return (1);
	}
	return (0);
}

int	ft_reverse_rotate_a_and_b(t_stack **a, t_stack **b)
{
	ft_reverse_rotate(a, 0);
	ft_reverse_rotate(b, 0);
	ft_printf("rrr\n");
	return (1);
}
