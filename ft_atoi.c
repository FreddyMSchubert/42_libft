/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 08:47:50 by fschuber          #+#    #+#             */
/*   Updated: 2023/10/11 11:22:08 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
