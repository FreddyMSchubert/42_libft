/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 07:48:45 by fschuber          #+#    #+#             */
/*   Updated: 2023/10/13 08:12:45 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list		*copied_list;

	if (lst->next != NULL)
	{
		copied_list = ft_lstnew(f(lst->content));
		if (!copied_list)
			return (NULL);
		copied_list->next = ft_lstmap(lst->next, f, del);
		return (copied_list);
	}
	return (NULL);
}
