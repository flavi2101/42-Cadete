/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flferrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 15:17:06 by flferrei          #+#    #+#             */
/*   Updated: 2024/11/30 16:09:43 by flferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

static char	*ft_read_data(int fd, char **file_info, int *end_file)
{
	char	*data;
	int		set_zero;

	set_zero = 0;
	data = (char *)malloc(sizeof(char) * (BUFFER_SIZE));
	if (!data)
		return (ft_clear_mem(*file_info, NULL, end_file));
	while (set_zero < BUFFER_SIZE)
		data[set_zero++] = '\0';
	set_zero = read(fd, data, BUFFER_SIZE);
	if (set_zero <= 0)
	{
		*end_file = 1;
		free(data);
		if (*file_info && set_zero == 0)
			return (*file_info);
		free(*file_info);
		return (NULL);
	}
	return (data);
}

static char	*ft_append_data(char **file_info, char **data,
		int size_break, int *end_file)
{
	char	*temp;

	if (!(*file_info))
		temp = ft_strjoin(NULL, *data, size_break);
	else
		temp = ft_strjoin(*file_info, *data, size_break);
	if (!temp)
		return (ft_clear_mem(*file_info, *data, end_file));
	if (*file_info)
		free(*file_info);
	return (temp);
}

static char	*ft_recursive_reading(int fd, char **info_file, int *end_file)
{
	char	*data;
	char	*temp;
	int		size_break;

	data = ft_read_data(fd, info_file, end_file);
	if (!data)
		return (NULL);
	if (data && *end_file == 1)
		return (data);
	size_break = ft_check_term_or_break(data);
	*info_file = ft_append_data(info_file, &data, size_break, end_file);
	if (!(*info_file))
		return (NULL);
	if (check_buffer_value(size_break, info_file))
	{
		free(data);
		return (ft_recursive_reading(fd, info_file, end_file));
	}
	temp = ft_strjoin(*info_file, data + size_break, BUFFER_SIZE - size_break);
	free(data);
	if (!temp)
		return (ft_clear_mem(*info_file, NULL, end_file));
	free(*info_file);
	*info_file = temp;
	return (*info_file);
}

static char	*ft_set_line_and_reminder(char *line, char **file_buffer,
		int counter, int total)
{
	char	*temp;

	if (!line)
	{
		free(*file_buffer);
		*file_buffer = NULL;
		return (NULL);
	}
	if (counter < total)
	{
		temp = ft_strjoin(NULL, *file_buffer + counter, total - counter);
		free(*file_buffer);
		*file_buffer = temp;
	}
	else
	{
		free(*file_buffer);
		*file_buffer = NULL;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*file_buffer;
	char		*line;
	char		*temp;
	int			counter;
	int			total;

	line = NULL;
	temp = NULL;
	counter = 0;
	total = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	file_buffer = ft_recursive_reading(fd, &file_buffer, &counter);
	if (!file_buffer && counter)
		return (NULL);
	counter = 0;
	while (file_buffer[counter] && file_buffer[counter] != '\n')
		counter++;
	if (file_buffer[counter] == '\n')
		counter++;
	while (file_buffer[total])
		total++;
	line = ft_strjoin(NULL, file_buffer, counter);
	return (ft_set_line_and_reminder(line, &file_buffer, counter, total));
}
/*
#include <stdio.h> 
int main(int argc, char *argv[])
{
	char *path = argv[1];
	char *a;
	if (argc > 10)
		return (-1);
	int fd = open (path, O_RDONLY);
	while((a = get_next_line(fd)))
	{
		printf("%s", a);
		free(a);
		printf("---------------\n");
	}
	return (0);
}
*/
