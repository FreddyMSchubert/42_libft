/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bzero.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 09:06:08 by fschuber          #+#    #+#             */
/*   Updated: 2023/10/08 09:25:31 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>

void	ft_bzero(void *s, size_t n)
{
	char		*char_s;

	char_s = (char *)s;

	while (n > 0)
	{
		char_s[n - 1] = '\0';
		n--;
	}
}

// void test_bzero(size_t n) {
//     char *realm1 = malloc(n);
//     char *realm2 = malloc(n);
//     if (!realm1 || !realm2) {
//         printf("Memory allocation failed!\n");
//         exit(EXIT_FAILURE);
//     }

//     ft_bzero(realm1, n);
//     bzero(realm2, n);

//     if (memcmp(realm1, realm2, n) == 0) {
//         printf("\033[1;32mSuccess:\033[0m realm of %zu 
// bytes cleansed.\n", n);
//     } else {
//         printf("\033[1;31mFailure:\033[0m realm of 
// %zu bytes remains shadowed.\n", n);
//     }

//     free(realm1);
//     free(realm2);
// }

// int main(void) {
//     test_bzero(0);               // The humble plain
//     test_bzero(1);               // The lone hill
//     test_bzero(2);               // The twin peaks
//     test_bzero(10);              // The undulating hills
//     test_bzero(100);             // The dense forest
//     test_bzero(1000);            // The sprawling fields
//     test_bzero(1024);            // The edge of the ancient boundary
//     test_bzero(5000);            // The great chasm
//     test_bzero(10000);           // The vast expanse
//     test_bzero(SIZE_MAX);        // The treacherous cliff

//     return 0;
// }