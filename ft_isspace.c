/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freddy <freddy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 17:04:32 by fschuber          #+#    #+#             */
/*   Updated: 2024/03/04 12:42:59 by freddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// checks single char
int	ft_isspace(int c)
{
	return (c == ' ' || c == '\t' || c == '\n' || \
			c == '\v' || c == '\f' || c == '\r');
}

// checks if any char in string is a space
int	ft_isspace_str_any(char *str)
{
	while (*str)
	{
		if (ft_isspace(*str))
			return (1);
		str++;
	}
	return (0);
}

// checks if all chars in string are spaces
int	ft_isspace_str_all(char *str)
{
	while (*str)
	{
		if (!ft_isspace(*str))
			return (0);
		str++;
	}
	return (1);
}

// checks if none of the chars in string are spaces
int	ft_isspace_str_none(char *str)
{
	while (*str)
	{
		if (ft_isspace(*str))
			return (0);
		str++;
	}
	return (1);
}
