/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:15:32 by alaaouam          #+#    #+#             */
/*   Updated: 2023/03/02 13:18:50 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <push_swap.h>

int	ft_isnum(int c)
{
	if (c >= 48 && c <= 57)
		return (c);
	return (0);
}

static int	ft_is_minus_or_plus(int c)
{
	if (c == 45 || c == 43)
		return (c);
	return (0);
}

static int	ft_only_numbers_and_spaces(char *str)
{
	size_t	count;

	if (!str)
		return (0);
	count = 0;
	while (str[count])
	{
		if (!ft_isnum(str[count]))
		{
			if (ft_is_minus_or_plus(str[count]))
			{
				if ((count == 0 || (count != 0 && str[count - 1] == 32))
					&& ft_isnum(str[count + 1]))
					count++;
				else
					return (0);
			}
			else if (str[count] != 32)
				return (0);
		}
		count++;
	}
	return (1);
}

static int	ft_valid_input(char **input, int is_parsed)
{
	char	*str;
	size_t	size;

	if (is_parsed == 1)
		return (1);
	size = ft_arrsize(input);
	str = (char *)malloc(size + 1);
	if (!str)
		return (0);
	str[0] = '\0';
	if (ft_arrjoin(str, input, size) == 0)
	{
		free(str);
		return (0);
	}
	if (ft_only_numbers_and_spaces(str))
	{
		if (!ft_max_or_min_int(str))
		{
			free(str);
			return (1);
		}
	}
	free(str);
	return (0);
}

t_stack	*parser(int size, char **args, t_stack **stack)
{
	static int	is_parsed;
	char		**arr;
	int			count;

	if (!is_parsed)
		is_parsed = 0;
	count = 1;
	if (ft_valid_input(args, is_parsed))
	{
		while (count < size)
		{
			arr = ft_split(args[count], 32);
			if (!arr)
				return (NULL);
			*stack = ft_create_stack(stack, arr);
			if (!(*stack))
				return (ft_free_array_and_return(arr));
			ft_free_array(arr);
			count++;
		}
	}
	else
		ft_exit_program(EXIT_FAILURE, stack);
	is_parsed++;
	return (*stack);
}
