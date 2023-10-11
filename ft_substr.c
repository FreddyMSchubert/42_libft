/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 07:11:20 by fschuber          #+#    #+#             */
/*   Updated: 2023/10/11 11:23:37 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*p;

	p = (char *)malloc(len + 1);
	if (p == NULL)
		return (NULL);
	ft_memcpy(p, &s[start], len);
	p[len] = '\0';
	return (p);
}
