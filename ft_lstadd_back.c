/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 07:35:19 by fschuber          #+#    #+#             */
/*   Updated: 2024/02/20 14:11:18 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *newelem)
{
	if (lst)
	{
		if (!*lst)
			*lst = newelem;
		else
			ft_lstlast(*lst)->next = newelem;
	}
}
