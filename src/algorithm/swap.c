/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:01:11 by alaaouam          #+#    #+#             */
/*   Updated: 2023/02/28 08:28:38 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <push_swap.h>

int	ft_swap(t_stack *stack, char id)
{
	int	temp;

	temp = stack->number;
	stack->number = stack->next->number;
	stack->next->number = temp;
	if (id == 'a')
		ft_printf("sa\n");
	else if (id == 'b')
		ft_printf("sb\n");
	return (1);
}

int	ft_swap_a_and_b(t_stack *a, t_stack *b)
{
	ft_swap(a, 0);
	ft_swap(b, 0);
	ft_printf("ss\n");
	return (1);
}
