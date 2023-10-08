/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 09:26:40 by fschuber          #+#    #+#             */
/*   Updated: 2023/10/08 09:33:27 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>

void	*ft_memset(void *b, int c, size_t len)
{
	char		*char_b;

	char_b = (char *)b;

	while (len > 0)
	{
		char_b[len - 1] = c;
		len--;
	}

	return (b);
}

// void test_memset(int c, size_t n) {
//     char *realm1 = malloc(n);
//     char *realm2 = malloc(n);
//     if (!realm1 || !realm2) {
//         printf("Memory allocation failed!\n");
//         exit(EXIT_FAILURE);
//     }

//     ft_memset(realm1, c, n);
//     memset(realm2, c, n);

//     if (memcmp(realm1, realm2, n) == 0) {
//         printf("\033[1;32mSuccess:\033[0m realm of %zu bytes 
// imbued with essence %d 🦄\n", n, c);
//     } else {
//         printf("\033[1;31mFailure:\033[0m realm of %zu bytes 
// misaligned with essence %d 🚫🦄\n", n, c);
//     }

//     free(realm1);
//     free(realm2);
// }

// int main(void) {
//     test_memset(0, 10);        // The tranquil meadow
//     test_memset(42, 10);       // The mystical forest
//     test_memset(255, 10);      // The fiery volcano
//     test_memset(1, 1);         // The solitary peak
//     test_memset(100, 100);     // The echoing valley
//     test_memset(127, 1000);    // The expansive horizon
//     test_memset(-1, 1024);     // The twilight zone

//     return 0;
// }
