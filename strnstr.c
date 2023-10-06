/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:37:01 by fschuber          #+#    #+#             */
/*   Updated: 2023/10/06 15:04:15 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdio.h>
#include <string.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		match_start;
	int		counter;

	match_start = 0;
	counter = 0;
	while (counter < (int)len)
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

void test_strnstr(char *(*strnstr_func)(const char *, const char *, size_t), const char *name) {
    // Test case 1: General case
    const char *haystack1 = "Hello, world!";
    const char *needle1 = "world";
    size_t len1 = 13;
    printf("%s Test 1: %s\n", name, strnstr_func(haystack1, needle1, len1) == haystack1 + 7 ? "Passed" : "Failed");

    // Test case 2: Needle at the beginning
    const char *haystack2 = "Hello, world!";
    const char *needle2 = "Hello";
    size_t len2 = 13;
    printf("%s Test 2: %s\n", name, strnstr_func(haystack2, needle2, len2) == haystack2 ? "Passed" : "Failed");

    // Test case 3: Needle is empty
    const char *haystack3 = "Hello, world!";
    const char *needle3 = "";
    size_t len3 = 13;
    printf("%s Test 3: %s\n", name, strnstr_func(haystack3, needle3, len3) == haystack3 ? "Passed" : "Failed");

    // Test case 4: Haystack is empty
    const char *haystack4 = "";
    const char *needle4 = "world";
    size_t len4 = 0;
    printf("%s Test 4: %s\n", name, strnstr_func(haystack4, needle4, len4) == NULL ? "Passed" : "Failed");

    // Test case 5: Needle not found
    const char *haystack5 = "Hello, world!";
    const char *needle5 = "universe";
    size_t len5 = 13;
    printf("%s Test 5: %s\n", name, strnstr_func(haystack5, needle5, len5) == NULL ? "Passed" : "Failed");
}

int main() {
    test_strnstr(strnstr, "strnstr");
    test_strnstr(ft_strnstr, "ft_strnstr");
    return 0;
}