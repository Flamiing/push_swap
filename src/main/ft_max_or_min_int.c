/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max_or_min_int.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 20:18:57 by alaaouam          #+#    #+#             */
/*   Updated: 2023/03/02 12:56:49 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <push_swap.h>

static int	ft_compare_nbr(int nbr, int last_nbr, char sign)
{
	if (nbr >= 214748364)
	{
		if (sign == '-' && nbr == 214748364 && last_nbr > 8)
			return (1);
		else if (sign != '-' && nbr == 214748364 && last_nbr > 7)
			return (1);
		else if (nbr > 214748364)
			return (1);
	}
	return (0);
}

static size_t	ft_count_numbers(char *str)
{
	size_t	index;
	size_t	count;

	if (!str)
		return (0);
	index = 0;
	count = 0;
	while (str[index])
	{
		if (ft_isnum(str[index]))
			count++;
		index++;
	}
	return (count);
}

static int	ft_digits_check(char *input, int last_nbr, char sign)
{
	size_t	index;
	char	*number;

	if (!input)
		return (0);
	index = 0;
	number = (char *)malloc(10);
	if (!number)
		return (0);
	while (index < 9)
	{
		number[index] = input[index];
		index++;
	}
	number[index] = '\0';
	if (ft_compare_nbr(ft_atoi(number), last_nbr, sign))
	{
		free(number);
		return (1);
	}
	free(number);
	return (0);
}

static int	ft_find_max_or_min_int(char *input)
{
	int	last_digit;

	if (!input)
		return (0);
	if (ft_count_numbers(input) > 10)
		return (1);
	else if (ft_count_numbers(input) == 10)
	{
		last_digit = ft_atoi(input + (ft_strlen(input) - 1));
		if (input[0] != 45)
		{
			if (ft_digits_check(input, last_digit, 0))
				return (1);
		}
		else if (input[0] == 45)
		{
			if (ft_digits_check(input + 1, last_digit, '-'))
				return (1);
		}
	}
	return (0);
}

int	ft_max_or_min_int(char *str)
{
	char	**arr;
	size_t	index;

	if (!str)
		return (0);
	arr = ft_split(str, 32);
	if (!arr)
		return (0);
	index = 0;
	while (arr[index])
	{
		if (ft_find_max_or_min_int(arr[index]))
		{
			ft_free_array(arr);
			return (1);
		}
		index++;
	}
	ft_free_array(arr);
	return (0);
}
