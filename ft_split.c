/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 06:17:07 by fschuber          #+#    #+#             */
/*   Updated: 2023/10/12 07:11:38 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

static int	count_sections_without_delimiters(char const *s, char del)
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
char	**ft_split(char const *s, char c)
{
	char		**a;
	int			l_s_i;
	int			sel_i;
	int			c_a_i;

	a = malloc((count_sections_without_delimiters(s, c) + 1) * sizeof(char *));
	if (a == NULL)
		return (NULL);
	a[count_sections_without_delimiters(s, c)] = NULL;
	l_s_i = 0;
	sel_i = 0;
	c_a_i = 0;
	while (s[sel_i])
	{
		while (s[sel_i] && s[sel_i] == c)
			sel_i++;
		l_s_i = sel_i;
		while (s[sel_i] && s[sel_i] != c)
			sel_i++;
		if (s[sel_i] == c || (s[sel_i] == '\0' && s[sel_i - 1] != c))
			a[c_a_i++] = ft_substr(s, l_s_i, sel_i - l_s_i);
		l_s_i = sel_i;
	}
	return (a);
}
