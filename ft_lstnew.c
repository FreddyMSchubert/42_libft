/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:31:11 by fschuber          #+#    #+#             */
/*   Updated: 2023/10/10 17:44:01 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Allocates (with malloc(3)) and returns a new node.
	The member variable ’content’ is initialized with
	the value of the parameter ’content’. The variable
	’next’ is initialized to NULL.
*/

#include <stdio.h>
#include <stdlib.h>

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_list_item;

	new_list_item = malloc(sizeof(t_list));
	if (new_list_item != NULL)
	{
		new_list_item->content = content;
		new_list_item->next = NULL;
	}
	return (new_list_item);
}

// Our humble spell to bestow visual form upon a t_list chest
void display_chest(t_list *chest)
{
    if (chest == NULL)
    {
        printf("The chest is but an illusion, it exists not!\n");
        return;
    }
    
    int *treasure = (int *)(chest->content);
    printf("This chest holds the treasure: %d\n", *treasure);
    
    if (chest->next != NULL)
        printf("Fear not, for there lies another chest beyond!\n");
    else
        printf("This chest stands alone, its tale ends here.\n");
}

// The mighty testing spell to unveil the nature of t_list
void test_t_list(void)
{
    int gold_coin = 42;
    t_list *new_chest = ft_lstnew(&gold_coin);  // Now, we use the Holy King's spell!
    
    display_chest(new_chest);
    
    free(new_chest);  // Releasing the chest back to the wild fields of the heap!
}

// int main(void)
// {
//     printf("Behold, the testing spell is cast!\n");
//     test_t_list();
//     printf("The testing spell has ended, the veil is lifted.\n");
    
//     return 0;
// }