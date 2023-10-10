/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 09:02:10 by fschuber          #+#    #+#             */
/*   Updated: 2023/10/10 10:41:16 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>
// #include <string.h>
#include <stdlib.h>

int	num_length(int num)
{
	int			i;
	int			negative;

	i = 0;
	negative = 0;
	if (num < 0)
	{
		negative = 1;
		num = -num;
	}
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num /= 10;
		i ++;
	}
	if (negative == 1)
		return (i + 1);
	return (i);
}

char	*create_string(int length)
{
	char	*char_numb;

	char_numb = (char *)malloc(length + 1);
	if (char_numb == NULL)
		return (NULL);
	char_numb[length] = '\0';
	return (char_numb);
}

char	*ft_itoa(int numb)
{
	size_t	length;
	char	*char_numb;
	int		negative;

	if (numb == -2147483648)
		return (ft_strdup("-2147483648"));
	length = num_length(numb);
	char_numb = create_string(length);
	negative = 0;
	if (numb < 0)
	{
		negative = 1;
		numb = -numb;
	}
	while (length > 0)
	{
		char_numb[length - 1] = numb % 10 + 48;
		numb /= 10;
		length--;
	}
	if (negative == 1)
		char_numb[0] = '-';
	return (char_numb);
}


void test_ft_itoa() {
    struct {
        int input;
        char const *expected;
    } tests[] = {
        {42, "42"},
        {-42, "-42"},
        {0, "0"},
        {2147483647, "2147483647"},  // The grand tale of INT_MAX.
        {-2147483648, "-2147483648"},  // The grand tale of INT_MIN.
        {1000000000, "1000000000"},
        {-1000000000, "-1000000000"},
        {999999999, "999999999"},
        {-999999999, "-999999999"},
        {1, "1"},
        {-1, "-1"},
        {10, "10"},
        {-10, "-10"},
        {123456789, "123456789"},
        {-123456789, "-123456789"},
        {-1, NULL}  // The sentinel to mark the end of tests.
    };
    
    for (int i = 0; tests[i].expected != NULL; i++) {
        char *carved_tale = ft_itoa(tests[i].input);
        
        printf("Trial %d:\n", i);
        printf("Carved Tale: '%s'\n", carved_tale ? carved_tale : "(null)");
        printf("Expected Tale: '%s'\n", tests[i].expected);
        
        free(carved_tale);  // Release the carved tale back to the memory realms.
    }
}

// int main() {
//     test_ft_itoa();
//     return 0;
// }
