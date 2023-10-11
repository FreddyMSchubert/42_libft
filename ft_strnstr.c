/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:37:01 by fschuber          #+#    #+#             */
/*   Updated: 2023/10/11 11:21:03 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		match_start;
	int		counter;

	match_start = 0;
	counter = 0;
	while (counter < (int)len)
	{
		if (haystack[counter] == needle[match_start])
		{
			if (match_start == ft_strlen(needle) - 1)
			{
				return ((char *) &haystack[counter - match_start]);
			}
			match_start++;
		}
		else
		{
			match_start = 0;
		}
		counter++;
	}
	return (NULL);
}
