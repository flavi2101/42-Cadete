/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flferrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:34:47 by flferrei          #+#    #+#             */
/*   Updated: 2024/10/23 12:50:42 by flferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	print_val(unsigned int val, int fd)
{
	unsigned int	aux;

	if (val <= 9)
	{
		val = val + 48;
		write (fd, &val, 1);
	}
	else
	{
		print_val(val / 10, fd);
		aux = (val % 10) + 48;
		write (fd, &aux, 1);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	value;

	if (n < 0)
	{
		value = (0xffffffff ^ n) + 1;
		write(fd, "-", 1);
	}
	else
		value = n;
	print_val(value, fd);
}
