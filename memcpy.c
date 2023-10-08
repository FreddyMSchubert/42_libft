/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 09:35:26 by fschuber          #+#    #+#             */
/*   Updated: 2023/10/08 10:22:46 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

// #include <stdio.h>
// #include <string.h>

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	char		*char_src;
	char		*char_dst;
	size_t		counter;

	char_src = (char *)src;
	char_dst = (char *)dst;
	counter = 0;

	while (counter < n)
	{
		char_dst[counter] = char_src[counter];
		counter++;
	}

	return (dst);
}

// int main(void)
// {
//     char small_village[1] = {42};
//     char grand_kingdom[1000];
//     char overlapping_src_dst[50];
//     size_t i;

//     // Fill the grand kingdom with knights (values)
//     for (i = 0; i < sizeof(grand_kingdom); ++i)
//     {
//         grand_kingdom[i] = i % 256;  // Values from 0 to 255
//     }

//     // The barren land and cursed realm remain empty (zeroes)

//     // Overlapping memory scenario setup
//     for (i = 0; i < sizeof(overlapping_src_dst); ++i)
//     {
//         overlapping_src_dst[i] = i + 1;  // Values from 1 to 50
//     }

//     // Now, let the testing begin!

//     // Test 1: Smallest possible values
//     char small_destination[1];
//     ft_memcpy(small_destination, small_village, sizeof(small_village));
//     printf("Small Destination: %d\n", small_destination[0]);

//     // Test 2: Largest possible values
//     char grand_destination[1000];
//     ft_memcpy(grand_destination, grand_kingdom, sizeof(grand_kingdom));
//     printf("Grand Destination (first 10 values): ");
//     for (i = 0; i < 10; ++i)
//     {
//         printf("%d ", grand_destination[i]);
//     }
//     printf("... and so on\n");

//     // Test 3: Null values
//     // NOTE: This may cause undefined behavior, uncomment at your own risk!
//     // ft_memcpy(barren_land, NULL, sizeof(barren_land));
//     // printf("Barren Land: %s\n", barren_land);

//     // Test 4: Overlapping memory regions
//     ft_memcpy(overlapping_src_dst + 10, overlapping_src_dst, 20);
//     printf("Cursed Realm (first 10 values): ");
//     for (i = 0; i < 10; ++i)
//     {
//         printf("%d ", overlapping_src_dst[i + 10]);
//     }
//     printf("\n");

//     return 0;
// }
