/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_free.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:45:36 by fschuber          #+#    #+#             */
/*   Updated: 2023/11/30 15:51:09 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

// @brief	frees a NULL-terminated twodimensional array
void	ft_free_rec(void **blob)
{
	int		counter;

	counter = 0;
	if (blob != NULL)
	{
		while (blob[counter] != NULL)
		{
			free(blob[counter]);
			counter++;
		}
		free(blob);
	}
}

// @brief	frees a NULL-terminated threedimensional array
void	ft_free_rec_rec(void ***blob)
{
	int		counter;
	int		counter2;

	counter = 0;
	if (blob != NULL)
	{
		while (blob[counter] != NULL)
		{
			counter2 = 0;
			while (blob[counter][counter2] != NULL)
			{
				free(blob[counter][counter2]);
				counter2++;
			}
			free(blob[counter]);
			counter++;
		}
		free(blob);
	}
}
