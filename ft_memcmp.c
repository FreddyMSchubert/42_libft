/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:21:53 by fschuber          #+#    #+#             */
/*   Updated: 2023/10/10 10:51:29 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

// int	ft_strncmp(const char *s1, const char *s2, size_t n)
// {
// 	size_t		i;

// 	i = 0;
// 	while (i < n - 1 && s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
// 		i++;
// 	return (s1[i] - s2[i]);
// }

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

#include <stdio.h>
#include <string.h>
#include "libft.h"  // Assuming ft_memcmp is defined in libft.h and libft.c

// Function to color-code and print the result
void color_print_result(int result) {
    if (result < 0) {
        printf("\033[0;31m");  // Color the output red for negative result
        printf("Result: %d (memcmp is greater)\n", result);
    } else if (result > 0) {
        printf("\033[0;31m");  // Color the output red for positive result
        printf("Result: %d (ft_memcmp is greater)\n", result);
    } else {
        printf("\033[0;32m");  // Color the output green for equal result
        printf("Result: %d (Both are equal)\n", result);
    }
    printf("\033[0m");  // Reset color
}

int main() {
    const char scroll1[] = "Hello, brave adventurer!";
    const char scroll2[] = "Hello, bold explorer!";

    // Compare scrolls using memcmp
    int memcmp_result = memcmp(scroll1, scroll2, 9);
    printf("Using memcmp:\n");
    color_print_result(memcmp_result);

    // Compare scrolls using ft_memcmp
    int ft_memcmp_result = ft_memcmp(scroll1, scroll2, 9);
    printf("Using ft_memcmp:\n");
    color_print_result(ft_memcmp_result);

    return 0;
}
