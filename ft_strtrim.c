/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 08:15:30 by fschuber          #+#    #+#             */
/*   Updated: 2023/10/10 10:52:08 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	go to front, go to back with seperate variables
	select the section that is supposed to be kept
	endselector - startselector gives the length, allocate it
	then just copy over with a loop starting at startselector
*/

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

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
	int		beg;
	int		end;
	char	*p;

	if (!s1 || !set)
		return (NULL);
	beg = 0;
	end = ft_strlen(s1) - 1;
	while (char_contained_in_set(set, s1[beg]))
		beg++;
	while (char_contained_in_set(set, s1[end]) && end >= beg)
		end--;
	p = ft_substr(s1, beg, end - beg + 1);
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
        
        printf("\nTrial %d:\n", i);
        printf("Crafted Trim: '%s'\n", trimmed_crafted ? trimmed_crafted : "(null)");
        printf("Expected Tale: '%s'\n", tests[i].expected);
        
        free(trimmed_crafted);  // Release the crafted trimmed string back to the memory realms.
    }
}

int main() {
    test_ft_strtrim();
    return 0;
}
