/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:08:22 by fschuber          #+#    #+#             */
/*   Updated: 2023/10/11 11:22:39 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *haystack, int needle, size_t arrayend)
{
	size_t	counter;
	char	*char_haystack;

	char_haystack = (char *)haystack;
	counter = 0;
	while (counter < arrayend)
	{
		if (char_haystack[counter] == needle)
			return ((void *)&haystack[counter]);
		counter++;
	}
	return (NULL);
}
