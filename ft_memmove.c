/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 10:23:01 by fschuber          #+#    #+#             */
/*   Updated: 2023/10/10 10:51:32 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include <stdio.h>
#include <string.h>

// i tried making logic to determine whether the strings are overlapping but
// my brain burst into flames

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*char_src;
	char		*char_dst;
	char		char_temp[len];
	size_t		counter;

	char_src = (char *)src;
	char_dst = (char *)dst;
	counter = 0;

	while (counter < len)
	{
		char_temp[counter] = char_src[counter];
		counter++;
	}

	counter = 0;

	while (counter < len)
	{
		char_dst[counter] = char_temp[counter];
		counter++;
	}

	return (dst);
}

void test_memmove_functions(char *dst, const char *src, size_t len, const char *expected_result, const char *test_description)
{
    // Capture the state of src and dst before calling ft_memmove
    char src_before[20];
    char dst_before[20];
    strncpy(src_before, src, 20);
    strncpy(dst_before, dst, 20);
    
    char dst_ft[20];
    char dst_std[20];
    strncpy(dst_ft, dst, 20);
    strncpy(dst_std, dst, 20);

    // Testing ft_memmove
    ft_memmove(dst_ft, src, len);
    
    // Testing standard memmove
    memmove(dst_std, src, len);

    printf("%s:\n", test_description);
    printf("   \033[34mSource Before:\033[0m %s, \033[31mDestination Before:\033[0m %s\n", src_before, dst_before);
    printf("   \033[35mft_memmove Destination:\033[0m %s, \033[36mExpected Destination:\033[0m %s\n", dst_ft, expected_result);
    printf("   \033[35mstd_memmove Destination:\033[0m %s, \033[36mExpected Destination:\033[0m %s\n\n", dst_std, expected_result);
}

int main(void)
{
    char buffer1[20] = "The quick brown fox";
    char buffer2[20] = "The quick brown fox";
    char buffer3[20] = "The quick brown fox";
    
    printf("\033[1;33mTesting memmove functions:\033[0m\n");

    // Overlapping, moving forward
    test_memmove_functions(buffer1 + 4, buffer1, 10, "The The quick", "Test 1 - Overlapping Forward");

    // Overlapping, moving backward
    test_memmove_functions(buffer2, buffer2 + 4, 10, "quick quick fox", "Test 2 - Overlapping Backward");

    // Non-overlapping
    test_memmove_functions(buffer3, "Jumped over the lazy dog", 20, "Jumped over the lazy dog", "Test 3 - Non-overlapping");

    return 0;
}
