/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstr_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 09:28:25 by fschuber          #+#    #+#             */
/*   Updated: 2023/10/10 09:54:15 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

void	ft_putstr_fd(char *s, int fd)
{
	int		counter;

	counter = 0;
	while (s[counter])
	{
		write ( fd, &s[counter], 1 );
		counter++;
	}
}

// int	main(void)
// {
// 	int	fd;
// 	char	*harrys_tale = "Mr. and Mrs. Dursley, of number four, Privet Drive, were proud to say that they were perfectly normal, thank you very much.";

// 	// Opening the scroll to inscribe the tale
// 	fd = open("magical_tale.txt", O_WRONLY | O_CREAT, 0644);
// 	if (fd == -1)
// 	{
// 		// Alas! The scroll refuses to unveil itself.
// 		return 1;
// 	}

// 	// Invoking your spell to inscribe Harry's tale onto the scroll
// 	ft_putstr_fd(harrys_tale, fd);

// 	// Closing the scroll, the tale is now inscribed
// 	close(fd);

// 	return 0;
// }