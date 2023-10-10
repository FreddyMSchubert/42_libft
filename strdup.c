/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 06:43:57 by fschuber          #+#    #+#             */
/*   Updated: 2023/10/09 10:22:44 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

// #include <stdio.h>
#include <stdlib.h>
// #include <string.h>

char	*ft_strdup(const char *s1)
{
	char		*p;
	size_t		i;
	size_t		strlen;

	i = 0;
	strlen = (size_t)ft_strlen(s1);
	p = (char *)malloc(strlen + 1);
	if (p == NULL)
		return (NULL);

	while (i < strlen)
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

// void test_strdup() {
//     char *test_strings[] = {
//         "The first string of testing lore",
//         "A shorter one",
//         "",
//         "A tale of many characters: abcdefghijklmnopqrstuvwxyz",
//         NULL
//     };
    
//     for (int i = 0; test_strings[i] != NULL; i++) {
//         char *mirror_standard = strdup(test_strings[i]);
//         char *mirror_crafted = ft_strdup(test_strings[i]);

//         if (mirror_standard == NULL || mirror_crafted == NULL) {
//             printf("Desolation! strdup or ft_strdup failed to conjure a mirror in Trial %d\n", i);
//         } else if (strcmp(mirror_standard, mirror_crafted) != 0) {
//             printf("Discrepancy! The mirrors do not reflect the same tale in Trial %d\n", i);
//         } else {
//             printf("Glory! The mirrors reflect the same tale in Trial %d\n", i);
//         }

//         free(mirror_standard);
//         free(mirror_crafted);
//     }
// }

// int main() {
//     test_strdup();
//     return 0;
// }