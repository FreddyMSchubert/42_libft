/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 08:47:50 by fschuber          #+#    #+#             */
/*   Updated: 2023/10/10 10:45:35 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	int		value;

	i = 0;
	sign = 1;
	value = 0;

	while (str[i] == ' ')
		i++;

	while (ft_isdigit(str[i]) || str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -sign;
		if (ft_isdigit(str[i]))
			value = (value * 10) + str[i] - 48;
		i++;
	}

	return (value * sign);
}

void test_atoi(const char *str) {
    int result_atoi = atoi(str);
    int result_ft_atoi = ft_atoi(str);

    if (result_atoi == result_ft_atoi) {
        printf("\033[1;32mSuccess:\033[0m %s -> %d\n", str, result_ft_atoi);
    } else {
        printf("\033[1;31mFailure:\033[0m %s -> Expected %d, Got %d\n", str, result_atoi, result_ft_atoi);
    }
}

int main(void) {
    test_atoi("123");
    test_atoi("   123");
    test_atoi(" -123");
    test_atoi("0");
    test_atoi("2147483647");  // INT_MAX
    test_atoi("-2147483648"); // INT_MIN
    test_atoi("  00000123");
    test_atoi("42 with words");
    test_atoi("words and 987");
    test_atoi("+42");
    test_atoi("-0");
    test_atoi("  -0012a42");
    test_atoi("3.14");
	test_atoi("alarm3.14");

    return 0;
}