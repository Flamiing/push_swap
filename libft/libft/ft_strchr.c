/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 10:46:50 by alaaouam          #+#    #+#             */
/*   Updated: 2023/02/14 14:12:06 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	count;
	char	ch;

	count = 0;
	ch = c;
	while (s[count])
	{
		if (s[count] == ch)
			return ((char *)s + count);
		count++;
	}
	if (s[count] == ch)
		return ((char *)s + count);
	return (0);
}
