/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarrdup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 10:43:48 by fschuber          #+#    #+#             */
/*   Updated: 2024/02/19 11:56:52 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// @brief Copies a string array
char	**ft_strarrdup(char **original)
{
	int		size;
	int		i;
	char	**duplicate;

	size = 0;
	while (original[size])
		size++;
	duplicate = (char **)malloc((size + 1) * sizeof(char *));
	if (duplicate == NULL)
		return (NULL);
	duplicate[size] = NULL;
	i = -1;
	while (++i < size)
	{
		duplicate[i] = ft_strdup(original[i]);
		if (duplicate[i] == NULL)
		{
			while (i > 0)
				free(duplicate[--i]);
			return (free(duplicate), NULL);
		}
	}
	return (duplicate);
}
