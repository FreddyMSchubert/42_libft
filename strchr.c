/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 08:46:00 by fschuber          #+#    #+#             */
/*   Updated: 2023/10/06 09:06:40 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c)
	{
		if (*s == '\0')
			return (NULL);
		s++;
	}
	return (char *)s;
}

// Test function
void test_strchr_functions(const char *s, int c)
{
    char *standard_strchr_result = strchr(s, c);
    char *ft_strchr_result = ft_strchr(s, c);

    printf("Testing string: \"%s\", character: '%c' (%d)\n", s, c, c);
    printf("Standard strchr result: %s\n", standard_strchr_result ? standard_strchr_result : "NULL");
    printf("ft_strchr result: %s\n", ft_strchr_result ? ft_strchr_result : "NULL");
    printf("Results %s\n\n", (standard_strchr_result == ft_strchr_result) ? "MATCH" : "DO NOT MATCH");
}

int main(void)
{
    // Array of test cases
    struct TestCase {
        const char *s;
        int c;
    } test_cases[] = {
        {"", 'a'},
        {"a", 'a'},
        {"hello", 'e'},
        {"hello, world!", 'w'},
        {NULL, 0}  // Sentinel value to mark the end of the array
    };

    // Loop through the test cases and call the test function on each one
    for (int i = 0; test_cases[i].s != NULL; i++)
    {
        test_strchr_functions(test_cases[i].s, test_cases[i].c);
    }

    return 0;
}