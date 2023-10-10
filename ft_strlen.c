/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 13:25:56 by fschuber          #+#    #+#             */
/*   Updated: 2023/10/10 10:52:00 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// wrong return type should be unsigned long i believe
// strnstr.c:29:20: error: comparison of integers of different signs: 'int' and 'unsigned long' [-Werror,-Wsign-compare]
//                        if (match_start == strlen(needle) - 1)
// match start is an int so i thought it would work but it didnt because i accidentally called the default strlne
// dont forget to fix new error in strnstr once this is fixed

int	ft_strlen(const char *s)
{
	int		counter;

	counter = 0;
	while (s[counter])
	{
		counter++;
	}
	return (counter);
}
