/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 06:10:49 by fschuber          #+#    #+#             */
/*   Updated: 2023/10/10 10:51:54 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
// #include <stdio.h>
// #include <string.h>

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t dstbuff)
{
	size_t		counter;
	size_t		srclen;
	size_t		dstlen;

	counter = 0;
	srclen = ft_strlen(src);
	dstlen = ft_strlen(dst);
	if (dstbuff <= dstlen)
	{
		return (srclen + dstbuff);
	}
	while (src[counter] && counter + dstlen < dstbuff)
	{
		dst[counter + dstlen] = src[counter];
		counter++;
	}
	if (counter + dstlen + 1 < dstbuff)
		dst[counter + dstlen] = '\0';
	else if (dstbuff > 0 && dstlen <= dstbuff - 1)
		dst[dstbuff - 1] = '\0';

	return (srclen + dstlen);
}

// void test_strlcat(const char *src, size_t dstsize) {
//     char dst1[100] = "Hello, ";
//     char dst2[100] = "Hello, ";

//     size_t ret1 = strlcat(dst1, src, dstsize);
//     size_t ret2 = ft_strlcat(dst2, src, dstsize);

//     printf("strlcat - Destination: '%s', Return Value: %zu\n", dst1, ret1);
//     printf("ft_strlcat - Destination: '%s', Return Value: %zu\n", dst2, ret2);

//     if (ret1 == ret2 && strcmp(dst1, dst2) == 0) {
//         printf("\033[0;32mTest passed!\033[0m\n");  // Green like the lush forests of Amethystia
//     }
// 	else
// 	{
//         printf("\033[0;31mTest failed!\033[0m\n");  // Red like the fiery heart of a dragon
//     }
// }

// int main(void) {
//     test_strlcat("world!", sizeof("Hello, world!"));
//     test_strlcat("world!", 8);
//     test_strlcat("world!", 7);
//     test_strlcat("", 20);  // Testing with empty source string
//     test_strlcat("world!", 0);  // Testing with zero buffer size
//     test_strlcat("world!", 100);  // Testing with large buffer size
//     test_strlcat("world!", 6);  // Testing with buffer size equal to destination string length
//     test_strlcat("A really long string to test edge cases.", 50);  // Testing with long source string
//     return 0;
// }
