/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 10:54:49 by alaaouam          #+#    #+#             */
/*   Updated: 2023/02/28 08:28:09 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <push_swap.h>
#include <algorithm.h>

int	ft_find_smaller(t_stack **stack, int key)
{
	t_stack	*temp;

	temp = *stack;
	while (temp != NULL)
	{
		if (temp->number <= key)
			return (1);
		temp = temp->next;
	}
	return (0);
}
