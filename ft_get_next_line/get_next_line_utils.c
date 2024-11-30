/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flferrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 15:30:29 by flferrei          #+#    #+#             */
/*   Updated: 2024/11/30 16:13:56 by flferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

int	ft_check_term_or_break(char *data)
{
	int	real_size;

	real_size = -1;
	while (++real_size < BUFFER_SIZE)
	{
		if (data[real_size] == '\n')
			return (++real_size);
		if (data[real_size] == '\0')
			return (real_size++);
	}
	return (BUFFER_SIZE);
}

int	check_buffer_value(int size_break, char **info_file)
{
	if (size_break == BUFFER_SIZE && (*info_file)[size_break -1] != '\n' &&
		*((*info_file) + size_break -1) != '\0')
		return (1);
	return (0);
}

char	*ft_strjoin(char *dst, char *src, int src_len)
{
	char	*jointed;
	int		dst_len;
	int		len_d;
	int		len_s;

	dst_len = 0;
	len_d = 0;
	len_s = 0;
	while (dst && dst[dst_len])
		dst_len++;
	jointed = (char *)malloc(sizeof(char) * (dst_len + src_len + 1));
	if (!jointed)
		return (NULL);
	while (dst && dst[len_d])
	{
		jointed[len_d] = dst[len_d];
		len_d++;
	}
	while (len_s < src_len)
	{
		jointed[len_d + len_s] = src[len_s];
		len_s++;
	}
	jointed[dst_len + src_len] = '\0';
	return (jointed);
}

char	*ft_clear_mem(char *mem1, char *data, int *end_file)
{
	if (data)
		free(data);
	if (mem1)
		free(mem1);
	mem1 = NULL;
	*end_file = 1;
	return (NULL);
}
