/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 12:35:23 by alaaouam          #+#    #+#             */
/*   Updated: 2023/02/28 08:29:38 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <push_swap.h>

void	ft_stackadd_front(t_stack **stack, t_stack *new)
{
	t_stack	*new_node;

	new_node = ft_newnode(new->number);
	new_node->next = *stack;
	*stack = new_node;
}

size_t	ft_stacksize(t_stack *stack)
{
	size_t	size;

	size = 0;
	while (stack != NULL)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}

void	ft_remove_node(t_stack **stack, t_stack *remove)
{
	t_stack	*current;

	if (*stack == NULL)
		return ;
	current = *stack;
	while (current->number != remove->number && current->next)
		current = current->next;
	*stack = current->next;
	free(remove);
}

int	ft_is_sorted(t_stack **stack)
{
	t_stack	*current;

	current = *stack;
	while (current->next != NULL)
	{
		if (current->number > current->next->number)
			return (0);
		current = current->next;
	}
	return (1);
}
