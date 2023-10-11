/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:37:01 by fschuber          #+#    #+#             */
/*   Updated: 2023/10/11 16:44:27 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		match_start;
	size_t		counter;

	if (!*needle)
		return ((char *)haystack);
	match_start = 0;
	counter = 0;
	while (counter < len)
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

// int	main()
// {
// 	printf("%s", ft_strnstr("lorem ipsum dolor sit amet", "", 10));
// 	return 1;
// }