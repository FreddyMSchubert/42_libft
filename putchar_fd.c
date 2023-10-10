/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putchar_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 09:19:47 by fschuber          #+#    #+#             */
/*   Updated: 2023/10/10 09:25:03 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}

int main(void)
{
	int fd;

	// Creating and opening a file named "test_file.txt" with write-only permissions
	fd = open("test_file.txt", O_WRONLY | O_CREAT, 0644);  // 0644 are the file permissions (rw-r--r--)
	if (fd == -1)
	{
		perror("Error opening file");
		return 1;
	}

	ft_putchar_fd('4', fd);  // Writing '4' into the file
	ft_putchar_fd('2', fd);  // Writing '2' into the file

	close(fd);  // Don't forget to close the file once you're done!

	return 0;
}