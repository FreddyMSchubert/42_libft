/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:51:03 by fschuber          #+#    #+#             */
/*   Updated: 2023/10/10 11:07:45 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// using char is ideal because it is one byte
// https://www.youtube.com/watch?v=xDVC3wKjS64

void	*ft_calloc(size_t count, size_t size)
{
	char		*p;

	p = (char *)malloc(count * size);
	if (p == NULL)
		return (NULL);
	ft_memset(p, 0, count * size);
	return ((void *)p);
}
// void test_callocs() {
//     for (int trial = 1; trial <= 10; trial++) {
//         size_t count = trial * 10;
//         size_t size = trial;

//         unsigned char *realm_calloc = (unsigned char *)calloc(count, size);
//         unsigned char *realm_ft_calloc = (unsigned char *)ft_calloc(count, size);

//         int honor_intact = 1;  // A flag of honor, to herald the valor of the tested spells.

//         for (size_t plot = 0; plot < count * size; plot++) {
//             if (realm_calloc[plot] != 0 || realm_ft_calloc[plot] != 0) {
//                 printf("Trial %d: Desolation! A plot not zeroed at %zu\n", trial, plot);
//                 honor_intact = 0;  // Honor besmirched, the flag is lowered.
//             }
//             if (realm_calloc[plot] != realm_ft_calloc[plot]) {
//                 printf("Trial %d: Discrepancy! calloc and ft_calloc lands differ at %zu\n", trial, plot);
//                 honor_intact = 0;  // Honor besmirched, the flag is lowered.
//             }
//         }

//         if (honor_intact) {
//             printf("Trial %d: Glory! calloc and ft_calloc stand united in valor!\n", trial);  // The herald sings praises.
//         }

//         free(realm_calloc);
//         free(realm_ft_calloc);
//     }
// }

// int main() {
//     test_callocs();
//     return 0;
// }