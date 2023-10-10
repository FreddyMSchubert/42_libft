/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:33:49 by fschuber          #+#    #+#             */
/*   Updated: 2023/10/10 18:00:52 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*next_list_item;
	int		list_items_count;

	next_list_item = lst->next;
	list_items_count = 1;
	while (next_list_item != NULL)
	{
		next_list_item = next_list_item->next;
		list_items_count++;
	}
	return (list_items_count);
}

void	test_ft_lstsize(void)
{
    int gold_coin_1 = 42;
    int gold_coin_2 = 84;
    int gold_coin_3 = 126;
    int gold_coin_4 = 168;
    
    t_list *chest_1 = ft_lstnew(&gold_coin_1);
    t_list *chest_2 = ft_lstnew(&gold_coin_2);
    t_list *chest_3 = ft_lstnew(&gold_coin_3);
    t_list *chest_4 = ft_lstnew(&gold_coin_4);
    
    ft_lstadd_front(&chest_1, chest_2);
    ft_lstadd_front(&chest_1, chest_3);
    ft_lstadd_front(&chest_1, chest_4);
    
    int size = ft_lstsize(chest_1);
    
    printf("The size of the list is: %d\n", size);  // Should print: The size of the list is: 4
    
    // Freeing each chest, returning the memory to the fields of the heap.
    free(chest_1->next->next->next);  // Freeing the original chest_2
    free(chest_1->next->next);        // Freeing the original chest_3
    free(chest_1->next);              // Freeing the original chest_4
    free(chest_1);                    // Freeing the original chest_1
}

int main(void)
{
    printf("Testing ft_lstsize...\n");
    test_ft_lstsize();
    printf("Testing completed.\n");
    
    return 0;
}