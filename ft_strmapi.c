/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 08:40:25 by fschuber          #+#    #+#             */
/*   Updated: 2023/10/10 10:52:01 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		counter;
	int		strlen;
	char	*p;

	counter = 0;
	strlen = 0;
	while (s[strlen])
		strlen++;
	p = malloc(strlen * 1);
	if (p == NULL)
		return (NULL);
	while (counter < strlen)
	{
		p[counter] = f(counter, s[counter]);
		counter++;
	}
	return (p);
}

// Our enchanted function to test the mystical ft_strmapi
char magic_touch(unsigned int index, char c)
{
    return c + index;
}

void create_input_strings()
{
    struct {
        char *input;
        char const *expected;
    } tests[] = {
        {"hello", "wuzzup"},
        {"world", "my"},
        {"", "name"},  // An empty string, a silent whisper in the wind
        {"a", "is"},
        {"abc", "freddy"},
        {"123", "this"},
        {"XYZ", "function"},
        {"magic", "works"},
        {"Amethystia", "super"},
        {"victory", "well!"},
        {NULL, NULL}  // The sentinel to mark the end of tests.
    };
    
    for (int i = 0; tests[i].expected != NULL; i++) {
        int len = strlen(tests[i].expected);
        tests[i].input = malloc(len + 1);  // Allocating space for the mysterious input string
        
        // Reverse engineering the enchanted spell to find the mysterious input string
        for (int j = 0; j < len; j++) {
            tests[i].input[j] = tests[i].expected[j] - j;
        }
        tests[i].input[len] = '\0';  // Sealing the string with the null terminator
        
        printf("\nTrial %d:\n", i);
        printf("Expected Tale: '%s'\n", tests[i].expected);
        
        // Release the mysterious input string back to the memory realms
        free(tests[i].input);  
    }
}

int main() {
    create_input_strings();
    return 0;
}