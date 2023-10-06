/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrchr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 09:46:35 by fschuber          #+#    #+#             */
/*   Updated: 2023/10/06 10:04:05 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>

char	*ft_strrchr(const char *s, int c)
{
	int		counter;

	counter = ft_strlen(s) - 1;
	while (counter >= 0)
	{
		if (s[counter] == c)
		{
			return ((char *) &s[counter]);
		}
		counter--;
	}
	return (NULL);
}

void test_strrchr(const char *s, int c) {
    char *result1 = ft_strrchr(s, c);
    char *result2 = strrchr(s, c);
    
    printf("Testing string: \"%s\", character: '%c' (%d)\n", s, c, c);
    printf("ft_strrchr result: %s\n", result1 ? result1 : "NULL");
    printf("strrchr result: %s\n", result2 ? result2 : "NULL");
    printf("\n");  // Print a blank line between tests
}

int main(void) {
    test_strrchr("hello world", 'l');
    test_strrchr("hello world", 'o');
    test_strrchr("hello world", 'h');
    test_strrchr("hello world", 'd');
    test_strrchr("hello world", 'z');
    
    return 0;
}