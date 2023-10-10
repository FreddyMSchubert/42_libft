/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 09:41:41 by fschuber          #+#    #+#             */
/*   Updated: 2023/10/10 10:51:40 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	printf("new input %d\n", n);
	printf("Itoa returns %s\n", ft_itoa(n));
	ft_putstr_fd(ft_itoa(n), fd);
}

void test_ft_putnbr_fd()
{
	int fd = open("numeral_scroll.txt", O_WRONLY | O_CREAT, 0644);
	if (fd == -1)
	{
		// The scroll refuses to be summoned, alas!
		return;
	}

	// Test 1: The number 42, a number most mysterious
	ft_putnbr_fd(42, fd);
	write(fd, "\n", 1);  // A new line to separate the numbers

	// Test 2: The zero, a circle of void
	ft_putnbr_fd(0, fd);
	write(fd, "\n", 1);  // A new line to separate the numbers

	// Test 3: Negative numbers, -42, the inverse of mystery
	ft_putnbr_fd(-42, fd);
	write(fd, "\n", 1);  // A new line to separate the numbers

	// Test 4: The largest positive mortal
	ft_putnbr_fd(2147483647, fd);
	write(fd, "\n", 1);  // A new line to separate the numbers

	// Test 5: The smallest negative mortal
	ft_putnbr_fd(-2147483648, fd);
	write(fd, "\n", 1);  // A new line to separate the numbers

	// Test 6: The singular ones, positive
	for (int i = 1; i <= 9; i++) {
		ft_putnbr_fd(i, fd);
		write(fd, "\n", 1);  // A new line to separate the numbers
	}

	// Test 7: The singular ones, negative
	for (int i = -1; i >= -9; i--) {
		ft_putnbr_fd(i, fd);
		write(fd, "\n", 1);  // A new line to separate the numbers
	}

		// Test 8: The twin digits, positive
	for (int i = 10; i <= 99; i++) {
		ft_putnbr_fd(i, fd);
		write(fd, "\n", 1);  // A new line to separate the numbers
	}

	// Test 9: The twin digits, negative
	for (int i = -10; i >= -99; i--) {
		ft_putnbr_fd(i, fd);
		write(fd, "\n", 1);  // A new line to separate the numbers
	}


	// Close the scroll, sealing the numbers within
	close(fd);
}

int main()
{
	test_ft_putnbr_fd();
	return 0;
}