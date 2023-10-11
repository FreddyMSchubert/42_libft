/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 10:23:01 by fschuber          #+#    #+#             */
/*   Updated: 2023/10/11 12:42:47 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	SCENARIO 1: Beginning of DST is free (default case when not overlapping)
		-> Copy from beginning
	SCENARIO 2: Beginnign of DST is filled
		-> Copy from end
	SCENARIO 3: Full Overlap
		-> just return DST
	checked in reverse order
*/

void	*scenario1(char *dst, const char *src, size_t len)
{
	size_t		counter;

	counter = 0;
	while (counter < len)
	{
		dst[counter] = src[counter];
		counter++;
	}
	return (dst);
}

void	*scenario2(char *dst, const char *src, size_t len)
{
	size_t		counter;

	counter = len;
	while (counter > 0)
	{
		dst[counter] = src[counter];
		counter--;
	}
	return (dst);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*char_dst;
	char	*char_src;

	char_dst = (char *)dst;
	char_src = (char *)src;
	if (char_dst == char_src && char_dst + len == char_src + len)
		return (dst);
	if (char_dst <= char_src + len && char_src < char_dst)
		return (scenario2(char_dst, char_src, len));
	if (char_src <= char_dst + len && char_dst < char_src)
		return (scenario1(char_dst, char_src, len));
	return (dst);
}

#include <stdio.h>
#include <string.h>

// ... Your ft_memmove definition ...

void test_ft_memmove(void) {
    // Test 1 - Dawn of Empty Lands
    char test1_src[] = "SourceString";
    char test1_dst[20] = {0};  // Clearing the potion vial
    char *ret1 = ft_memmove(test1_dst, test1_src, strlen(test1_src) + 1);  // +1 for the null-terminator
    printf("Test 1 - Dawn of Empty Lands: %s, Expected: SourceString\n", ret1);

    // Test 2 - Eve of Occupied Territories
    char test2_src[] = "AnotherSource";
    char test2_dst[20] = "DestinationString";  // The potion vial is full
    char *ret2 = ft_memmove(test2_dst, test2_src, strlen(test2_src) + 1);  // +1 for the null-terminator
    printf("Test 2 - Eve of Occupied Territories: %s, Expected: AnotherSource\n", ret2);

    // Test 3 - Epoch of Conjoined Kingdoms
    char test3_src[] = "OverlapString";
    char *test3_dst = test3_src + 5;  // The realms overlap!
    char *ret3 = ft_memmove(test3_dst, test3_src, strlen(test3_src) + 1);  // +1 for the null-terminator
    printf("Test 3 - Epoch of Conjoined Kingdoms: %s, Expected: OverlapString\n", ret3);

    // ... And many more tests, under different moon phases and star alignments
}

int main(void) {
    test_ft_memmove();  // Invoke the testing cauldron
    return 0;  // The sorcerer's farewell
}
