/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:21:53 by fschuber          #+#    #+#             */
/*   Updated: 2023/10/11 11:22:38 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t		i;
	char		*cs1;
	char		*cs2;

	cs1 = (char *)s1;
	cs2 = (char *)s2;
	i = 0;
	while (i < n - 1 && cs1[i] != '\0' && cs2[i] != '\0' && cs1[i] == cs2[i])
		i++;
	return (cs1[i] - cs2[i]);
}
