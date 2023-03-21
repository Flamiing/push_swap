/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 21:30:38 by alaaouam          #+#    #+#             */
/*   Updated: 2023/02/28 10:21:41 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <push_swap.h>

t_stack	*ft_stacklast(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}

void	ft_stackadd_back(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (*stack == NULL)
		*stack = new;
	else
	{
		last = ft_stacklast(*stack);
		last->next = new;
	}
}

t_stack	*ft_newnode(int number)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return (0);
	node->number = number;
	node->next = NULL;
	return (node);
}

t_stack	*ft_create_stack(t_stack **stack, char **arr)
{
	t_stack			*temp;
	unsigned int	count;

	count = 0;
	temp = *stack;
	while (arr[count])
	{
		temp = ft_newnode(ft_atoi(arr[count]));
		if (!temp)
		{
			ft_free_stack(stack);
			return (NULL);
		}
		ft_stackadd_back(stack, temp);
		count++;
	}
	return (*stack);
}
