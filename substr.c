/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 07:11:20 by fschuber          #+#    #+#             */
/*   Updated: 2023/10/10 07:47:11 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*p;

	p = (char *)malloc(len + 1);
	if (p == NULL)
		return (NULL);
	ft_memcpy(p, &s[start], len);
	p[len] = '\0';

	return (p);
}

/*
Regarding the ft_substr function, the arguments themselves look correct, but the ft_substr function implementation may have an issue.

In the ft_substr function, you are using ft_memcpy(p, &s[start], len); to copy the substring into the newly allocated memory. This line is correct, assuming that ft_memcpy is implemented correctly. However, if s[start] goes beyond the null terminator of s, ft_memcpy will continue copying memory until it has copied len bytes, which can cause undefined behavior
*/

// void test_ft_substr() {
//     struct {
//         char const *input;
//         unsigned int start;
//         size_t len;
//         char const *expected;
//     } tests[] = {
//         {"The Grand Saga of Code", 10, 4, "Saga"},
//         {"The Grand Saga of Code", 0, 9, "The Grand"},
//         {"The Grand Saga of Code", 14, 4, "Code"},
//         {"The Grand Saga of Code", 5, 0, ""},
//         {NULL, 0, 0, NULL}  // The sentinel to mark the end of tests.
//     };
    
//     for (int i = 0; tests[i].input != NULL; i++) {
//         char *fragment = ft_substr(tests[i].input, tests[i].start, tests[i].len);
//         if (fragment == NULL) {
//             printf("Desolation! ft_substr failed to conjure a fragment in Trial %d\n", i);
//             continue;
//         }
        
// 		if (strcmp(fragment, tests[i].expected) != 0) {
// 			printf("Discrepancy! The carved fragment does not match the expected tale in Trial %d\n", i);
// 			printf("Carved Fragment: '%s', Expected Tale: '%s'\n", fragment, tests[i].expected);  // The revelation!
// 		} else {
// 			printf("Glory! The carved fragment matches the expected tale in Trial %d\n", i);
// 		}

        
//         free(fragment);  // Release the fragment back to the memory realms.
//     }
// }

// int main() {
//     test_ft_substr();
//     return 0;
// }
