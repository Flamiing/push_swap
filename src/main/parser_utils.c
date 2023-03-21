/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 13:41:41 by alaaouam          #+#    #+#             */
/*   Updated: 2023/03/01 20:18:34 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <push_swap.h>

size_t	ft_arrsize(char **input)
{
	size_t	size;
	size_t	count;

	if (!input)
		return (0);
	size = 0;
	count = 1;
	while (input[count])
	{
		size += ft_strlen(input[count]);
		size++;
		count++;
	}
	size--;
	return (size);
}

int	ft_arrjoin(char *dest, char **arr, size_t size)
{
	size_t	count;
	char	*copy;

	if (!arr)
		return (0);
	count = 1;
	while (arr[count])
	{
		copy = (char *)malloc(ft_strlen(arr[count]) + 1);
		if (!copy)
			return (0);
		ft_strlcpy(copy, arr[count], ft_strlen(arr[count]) + 1);
		copy[ft_strlen(copy)] = '\0';
		ft_strlcpy(dest + ft_strlen(dest), copy, ft_strlen(copy) + 1);
		dest[ft_strlen(dest)] = '\0';
		free(copy);
		if (ft_strlen(dest) < size)
		{
			dest[ft_strlen(dest)] = 32;
			dest[ft_strlen(dest) + 1] = '\0';
		}
		count++;
	}
	return (1);
}
