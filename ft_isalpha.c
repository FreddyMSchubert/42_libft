/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 17:04:32 by fschuber          #+#    #+#             */
/*   Updated: 2023/10/10 10:51:19 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// isalpha accounts for values outside of ascii range => first condition

int	ft_isalpha(int c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}
