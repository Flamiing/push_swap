/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:59:16 by alaaouam          #+#    #+#             */
/*   Updated: 2023/03/01 11:27:47 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <push_swap.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack	*chunks;

	if (argc > 1)
	{
		stack_a = NULL;
		stack_b = NULL;
		chunks = NULL;
		stack_a = parser(argc, argv, &stack_a);
		if (!stack_a)
			ft_exit_program(EXIT_FAILURE, 0);
		chunks = parser(argc, argv, &chunks);
		if (!chunks)
			ft_exit_program(EXIT_FAILURE, &stack_a);
		if (ft_has_repeated_numbers(&stack_a))
			ft_exit_program(EXIT_FAILURE, &stack_a);
		if (ft_stacksize(stack_a) > 1 && !ft_is_sorted(&stack_a))
			ft_sort_stack(&stack_a, &stack_b, &chunks);
		ft_free_stack(&stack_a);
		ft_free_stack(&chunks);
		ft_exit_program(EXIT_SUCCESS, 0);
	}
	else
		ft_exit_program(0, 0);
}
