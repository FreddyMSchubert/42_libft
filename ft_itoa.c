/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 09:02:10 by fschuber          #+#    #+#             */
/*   Updated: 2023/10/11 11:10:18 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
