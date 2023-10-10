/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:52:09 by fschuber          #+#    #+#             */
/*   Updated: 2023/10/10 17:40:51 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>
#include <stdlib.h>

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new != NULL)
	{
		new->next = *lst;
		*lst = new;
	}
}

void free_list(t_list *head)
{
    t_list *temp;
    
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

void display_chest_chain(t_list *chest)
{
    int chest_number = 1;
    while (chest != NULL)
    {
        int *treasure = (int *)(chest->content);
        printf("Chest %d holds the treasure: %d\n", chest_number, *treasure);
        chest = chest->next;
        chest_number++;
    }
}

void test_ft_lstadd_front(void)
{
    int gold_coin_1 = 42;
    int gold_coin_2 = 84;
    
    t_list *chest_1 = ft_lstnew(&gold_coin_1);
    t_list *chest_2 = ft_lstnew(&gold_coin_2);
    
    ft_lstadd_front(&chest_1, chest_2);
    
    display_chest_chain(chest_1);
    
    // Freeing each chest, returning the memory to the fields of the heap.
    free_list(chest_1);
}

// int main(void)
// {
//     printf("Behold, the testing spell for ft_lstadd_front is cast!\n");
//     test_ft_lstadd_front();
//     printf("The testing spell has ended, the magic of ft_lstadd_front unveiled.\n");
    
//     return 0;
// }