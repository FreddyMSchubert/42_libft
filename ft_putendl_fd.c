/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 09:32:41 by fschuber          #+#    #+#             */
/*   Updated: 2023/10/10 10:51:38 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

void	ft_putendl_fd(char *s, int fd)
{
	int		counter;

	counter = 0;
	while (s[counter])
	{
		write(fd, &s[counter], 1);
		counter++;
	}
	char newline = '\n';
	write(fd, &newline, 1);
}

int	main(void)
{
	int	fd;
	char	*harrys_tale = "https://github.com/xicodomingues/francinette";

	// Opening the scroll to inscribe the tale
	fd = open("magical_tale.txt", O_WRONLY | O_CREAT, 0644);
	if (fd == -1)
	{
		// Alas! The scroll refuses to unveil itself.
		return 1;
	}

	// Invoking your spell to inscribe Harry's tale onto the scroll
	ft_putendl_fd(harrys_tale, fd);

	// Closing the scroll, the tale is now inscribed
	close(fd);

	return 0;
}