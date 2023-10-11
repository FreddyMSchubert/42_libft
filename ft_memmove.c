/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 10:23:01 by fschuber          #+#    #+#             */
/*   Updated: 2023/10/11 15:36:48 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	SCENARIO 1: Beginning of DST is free (default case when not overlapping)
		-> Copy from beginning
	SCENARIO 2: Beginnign of DST is filled
		-> Copy from end
	SCENARIO 3: Full Overlap
		-> just return DST
	checked in reverse order
*/

void	*scenario1(char *dst, const char *src, size_t len)
{
	size_t		counter;

	counter = 0;
	while (counter < len)
	{
		dst[counter] = src[counter];
		counter++;
	}
	return (dst);
}

void	*scenario2(char *dst, const char *src, size_t len)
{
	size_t		counter;

	counter = len - 1;
	while (counter > 0)
	{
		dst[counter] = src[counter];
		counter--;
	}
	return (dst);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*char_dst;
	char	*char_src;

	char_dst = (char *)dst;
	char_src = (char *)src;
	if (char_dst == char_src)
		return (dst);
	if (char_dst < char_src && char_src < char_dst + len)
		return (scenario2(char_dst, char_src, len));
	else if (char_src < char_dst && char_dst < char_src + len)
		return (scenario1(char_dst, char_src, len));
	return (dst);
}
