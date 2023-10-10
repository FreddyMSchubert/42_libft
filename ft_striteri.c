/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 09:02:26 by fschuber          #+#    #+#             */
/*   Updated: 2023/10/10 10:51:48 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>
#include <string.h>

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int		counter;
	int		strlen;

	counter = 0;
	strlen = 0;
	while (s[strlen])
		strlen++;
	while (counter < strlen)
	{
		f(counter, &s[counter]);
		counter++;
	}
}

void apply_magic(unsigned int index, char *c) {
    *c += index;
}

void test_ft_striteri() {
    struct {
        char input[100];
        char expected[100];
    } tests[] = {
        {"hello", "hfnos"},
        {"world", "wptmf"},
        {"", ""},  // testing an empty string
        // ... add more tests as needed
    };
    
    for (unsigned long i = 0; i < sizeof(tests) / sizeof(tests[0]); i++) {
        char test_input[100];
        strcpy(test_input, tests[i].input);  // copy input to a modifiable buffer
        ft_striteri(test_input, apply_magic);
        
        printf("\nTrial %lu:\n", i);
        printf("Output: '%s'\n", test_input);
        printf("Expected: '%s'\n", tests[i].expected);
        
        if (strcmp(test_input, tests[i].expected) == 0) {
            printf("Success\n");
        } else {
            printf("Failure\n");
        }
    }
}

int main() {
    test_ft_striteri();
    return 0;
}