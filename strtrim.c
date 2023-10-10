/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtrim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 07:48:48 by fschuber          #+#    #+#             */
/*   Updated: 2023/10/09 09:01:01 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	char_contained_in_set(char const *set, char c)
{
	int		i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		s1len;
	int		beg_counter;
	int		end_counter;
	char	*p;

	s1len = ft_strlen(s1);
	beg_counter = 0;
	end_counter = s1len - 1;
	if (s1 == NULL)
		return (NULL);
	while (beg_counter < s1len && char_contained_in_set(set, s1[beg_counter]))
		beg_counter++;
	while (end_counter >= 0 && char_contained_in_set(set, s1[end_counter]))
		end_counter--;
	if (beg_counter > end_counter)
	{
		p = malloc(1);
		if (p == NULL)
			return (NULL);
		p[0] = '\0';
		return (p);
	}
	p = ft_substr(s1, beg_counter, end_counter - beg_counter + 1);
	return (p);
}

void test_ft_strtrim() {
    struct {
        char const *input;
        char const *set;
        char const *expected;
    } tests[] = {
        {"    The Grand Saga of Code    ", " ", "The Grand Saga of Code"},
        {"abacaba The Grand Saga of Code bacabaca", "abc ", "The Grand Saga of Code"},
        {"NoTrimmingHere!", "!", "NoTrimmingHere"},
        {"", " ", ""},  // An empty string.
        {"   ", " ", ""},  // A string of only spaces.
        {"!!!!!", "!", ""},  // A string of only trimmable characters.
        {NULL, " ", ""},  // An empty tale, yet a realm of trimmable characters.
        {NULL, NULL, NULL}  // The sentinel to mark the end of tests.
    };
    
    for (int i = 0; tests[i].input != NULL || tests[i].expected != NULL; i++) {
        char *trimmed_crafted = ft_strtrim(tests[i].input, tests[i].set);
        
        printf("Trial %d:\n", i);
        printf("Crafted Trim: '%s'\n", trimmed_crafted ? trimmed_crafted : "(null)");
        printf("Expected Tale: '%s'\n", tests[i].expected);
        
        free(trimmed_crafted);  // Release the crafted trimmed string back to the memory realms.
    }
}

int main() {
    test_ft_strtrim();
    return 0;
}
