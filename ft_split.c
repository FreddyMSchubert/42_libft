/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 06:17:07 by fschuber          #+#    #+#             */
/*   Updated: 2023/10/10 10:51:43 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	count_sections_without_delimiters(char const *s, char del)
{
	int		counter;
	int		sections_without_delimiters;

	counter = 0;
	sections_without_delimiters = 0;
	while (s[counter])
	{
		while (s[counter] && s[counter] == del)
			counter++;
		while (s[counter] && s[counter] != del)
			counter++;
		if (s[counter] == del || (s[counter] == '\0' && s[counter - 1] != del))
			sections_without_delimiters++;
	}
	return (sections_without_delimiters);
}

/*
INPUT
	s     = string to be cut up into substrings
	del   = delimiter as marker on where to cut up the string

VARIABLES
	l_s_i = last selected index, lower limit when splitting off substrings
	sel_i = selected index, upper limit when splitting off substrings
	a     = array, substrings get saved here to be returned
	c_a_i = current array index, keeps track off where to save the next substring to
*/

/*
	first we make a function to caluclate the amount of sections without a delimiter
	then initialize an array to contain our output with that number; \0 it.

	two variables: last_split_index; selected_index
	loop
		both skip all delimiters in the beginning; selecting the first non-delimiter
		selected_index moves until it finds a delimiter character
		split off with input of last_split_index and selected_index
		=> last_split_index gets written to array
		last_split_index goes to selected_index
*/
char	**ft_split(char const *s, char del)
{
	char		**a;
	int			l_s_i;
	int			sel_i;
	int			c_a_i;

	a = malloc(count_sections_without_delimiters(s, del) * sizeof(char *) + 1);
	if (a == NULL)
		return (NULL);
	a[count_sections_without_delimiters(s, del)] = NULL;
	l_s_i = 0;
	sel_i = 0;
	c_a_i = 0;
	while (s[sel_i])
	{
		while (s[sel_i] && s[sel_i] == del)
			sel_i++;
		l_s_i = sel_i;
		while (s[sel_i] && s[sel_i] != del)
			sel_i++;
		if (s[sel_i] == del || (s[sel_i] == '\0' && s[sel_i - 1] != del))
			a[c_a_i++] = ft_substr(s, l_s_i, sel_i - l_s_i);
		l_s_i = sel_i;
	}
	return (a);
}

void print_array(char **array) {
    if (array == NULL) {
        printf("(null)\n");
        return;
    }
    for (int i = 0; array[i] != NULL; i++) {
        printf("'%s'", array[i]);
        if (array[i + 1] != NULL)
            printf(", ");
    }
    printf("\n");
}

void free_array(char **array) {
    for (int i = 0; array[i] != NULL; i++)
        free(array[i]);
    free(array);
}

void test_ft_split() {
    struct {
        char const *input;
        char delimiter;
        char *expected[10];  // Adjust the size as needed.
    } tests[] = {
        {"The Grand Saga of Code", ' ', {"The", "Grand", "Saga", "of", "Code", NULL}},
        {"abacaba", 'a', {"b", "c", "b", NULL}},
        {"", ' ', {NULL}},
        {"NoDelimitersHere!", '!', {"NoDelimitersHere!", NULL}},
        {"!Exclaim!", '!', {"", "Exclaim", "", NULL}},
        {"Dance!!Dance!!", '!', {"Dance", "", "Dance", "", NULL}},
        {"EdgeCase", 'E', {"", "dgeCase", NULL}},
        {"EdgeCase", 'e', {"Edg", "Cas", NULL}},
        {"!!!!", '!', {"", "", "", "", NULL}},
        {"a!a!a", '!', {"a", "a", "a", NULL}},
        {NULL, ' ', {NULL}}  // The sentinel to mark the end of tests.
    };
    
    for (int i = 0; tests[i].input != NULL; i++) {
        char **split_tales = ft_split(tests[i].input, tests[i].delimiter);
        
        printf("Trial %d:\n\n\n", i);
        printf("Split Tales: ");
        print_array(split_tales);
        printf("Expected Tales: ");
        print_array(tests[i].expected);
        
        free_array(split_tales);  // Release the split tales back to the memory realms.
    }
}

int main() {
    test_ft_split();
    return 0;
}