/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 13:30:43 by fschuber          #+#    #+#             */
/*   Updated: 2023/10/10 10:52:03 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <string.h>
#include <stdio.h>

/*
	CONDITIONS
	1.      to stay within limit of n
	2. & 3. to not get memory error
	4.      to stop when a difference has been found

	n gets decremented because otherwise i would increment
	one too many times before return without check
	(somebody allow do while loops, quick)
*/

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t		i;

	i = 0;
	while (i < n - 1 && s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void test_strncmp(const char *s1, const char *s2, size_t n) {
    int result1 = ft_strncmp(s1, s2, n);
    int result2 = strncmp(s1, s2, n);

    // Normalize results to -1, 0, or 1 to account for potential differences in exact values returned
    result1 = (result1 > 0) - (result1 < 0);
    result2 = (result2 > 0) - (result2 < 0);

    if (result1 == result2) {
        printf("Test passed for inputs '%s', '%s', %zu: ft_strncmp = %d, strncmp = %d\n", s1, s2, n, result1, result2);
    } else {
        printf("Test failed for inputs '%s', '%s', %zu: ft_strncmp = %d, strncmp = %d\n", s1, s2, n, result1, result2);
    }
}

int main(void) {
    test_strncmp("hello", "hello", 5);
    test_strncmp("hello", "world", 5);
    test_strncmp("hello", "hell", 5);
    test_strncmp("world", "word", 4);
    test_strncmp("abc", "abcd", 4);
    test_strncmp("abcd", "abc", 4);
	test_strncmp("abc", "abcd", 3);
    test_strncmp("abcd", "abc", 3);

    return 0;
}