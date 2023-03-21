/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 12:50:02 by alaaouam          #+#    #+#             */
/*   Updated: 2023/02/14 14:11:39 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	count;
	char	*ptr;
	char	ch;

	count = 0;
	ptr = (char *)s;
	ch = c;
	while (count < n)
	{
		if (ptr[count] == ch)
			return (ptr + count);
		count++;
	}
	return (0);
}
