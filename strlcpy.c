/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:08:24 by fschuber          #+#    #+#             */
/*   Updated: 2023/10/06 15:51:50 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

size_t	ft_strlcpy(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t		counter;
	size_t		src_length;

	if (dstsize != 0)
	{
		counter = 0;
		src_length = 0;
		while (counter < dstsize - 1 && src[counter])
		{
			dst[counter] = src[counter];
			counter++;
		}
		dst[counter] = '\0';
	}

	while (src[src_length])
		src_length++;
	return (src_length);
}

void test_strlcpy(size_t (*strlcpy_func)(char *, const char *, size_t), const char *name)
{
    char buffer[10];
    const char *src = "Hello, world!";
    size_t result;

    // Test 1: Normal case
    result = strlcpy_func(buffer, src, sizeof(buffer));
    printf("%s - Test 1: Copied: '%s', Return Value: %zu\n", name, buffer, result);
    
    // Test 2: dstsize is zero
    result = strlcpy_func(buffer, src, 0);
    printf("%s - Test 2: Copied: '%s', Return Value: %zu\n", name, buffer, result);
    
    // Test 3: dstsize is one
    result = strlcpy_func(buffer, src, 1);
    printf("%s - Test 3: Copied: '%s', Return Value: %zu\n", name, buffer, result);
    
    // Test 4: dstsize is exactly enough to hold the copied string and null terminator
    const char *short_src = "Hi";
    result = strlcpy_func(buffer, short_src, 3);
    printf("%s - Test 4: Copied: '%s', Return Value: %zu\n", name, buffer, result);
    
    // Test 5: src is an empty string
    const char *empty_src = "";
    result = strlcpy_func(buffer, empty_src, sizeof(buffer));
    printf("%s - Test 5: Copied: '%s', Return Value: %zu\n", name, buffer, result);
    
    // Test 6: src is NULL (undefined behavior, but some strlcpy implementations handle it)
    // It's typically not safe to pass NULL, but we can include this test for completeness
    // Uncomment the next two lines if your strlcpy implementation handles NULL
    // result = strlcpy_func(buffer, NULL, sizeof(buffer));
    // printf("%s - Test 6: Copied: '%s', Return Value: %zu\n", name, buffer, result);
}

int main()
{
    test_strlcpy(strlcpy, "strlcpy");
    test_strlcpy(ft_strlcpy, "ft_strlcpy");
    
    return 0;
}