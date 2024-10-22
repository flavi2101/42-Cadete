/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flferrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:26:33 by flferrei          #+#    #+#             */
/*   Updated: 2024/10/22 16:32:59 by flferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putendl_fd(char *c, int fd)
{
	size_t	counter;

	counter = ft_strlen(c);
	write (fd, c, counter);
	write (fd, "\n", 1);
}
