/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:08:22 by fschuber          #+#    #+#             */
/*   Updated: 2023/10/10 10:51:28 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

#include <stddef.h>

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

void color_test(const void *haystack, int needle, size_t len) {
    const char *result_memchr = memchr(haystack, needle, len);
    const char *result_ft_memchr = ft_memchr(haystack, needle, len);

    // The banners are raised, the crowd hushes as the knights take their positions.
    printf("Testing with needle '%c' in haystack of length %zu:\n", needle, len);

    // The trumpets blare as memchr makes its move
    if (result_memchr) {
        printf("\033[0;32m");  // Color the output green if memchr succeeds
        printf("memchr found '%c' at position %ld\n", needle, result_memchr - (const char *)haystack);
    } else {
        printf("\033[0;31m");  // Color the output red if memchr fails
        printf("memchr did not find '%c'\n", needle);
    }
    printf("\033[0m");  // Reset color

    // The drums roll as ft_memchr enters the fray
    if (result_ft_memchr) {
        printf("\033[0;32m");  // Color the output green if ft_memchr succeeds
        printf("ft_memchr found '%c' at position %ld\n", needle, result_ft_memchr - (const char *)haystack);
    } else {
        printf("\033[0;31m");  // Color the output red if ft_memchr fails
        printf("ft_memchr did not find '%c'\n", needle);
    }
    printf("\033[0m");  // Reset color

    // The crowd roars, the test is concluded.
    printf("\n");
}

int main() {
    // The tourney grounds are prepared with an array of characters.
    const char royal_array[] = "The quick brown fox jumps over a lazy dog";

    // The knights shall be tested against many a foe, known and unknown.
    color_test(royal_array, 'q', sizeof(royal_array));
    color_test(royal_array, 'a', sizeof(royal_array));
    color_test(royal_array, 'z', sizeof(royal_array));
    color_test(royal_array, '!', sizeof(royal_array));
    color_test(royal_array, ' ', sizeof(royal_array));
    color_test(NULL, 'x', 0);  // Ah, a nefarious test! But our knights are bold and well-prepared.

    return 0;
}