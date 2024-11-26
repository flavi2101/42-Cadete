#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int	check_term_or_break(int buffers,char *data)
{
	int real_size;
	real_size = -1;
	
	while(++real_size < buffers)
	{
		if (data[real_size] == '\n')
			return (++real_size);
		if (data[real_size] == '\0')
			return (real_size);
	}
	return (buffers);
}

char	*strjoin(char *dst, char *src, int src_len)
{
	int dst_len;
	int 	len_d;
	int	len_s;
	char	*jointed;

	dst_len = 0;
	len_d = -1;
	len_s = -1;
	while(dst[dst_len])
		dst_len++;
	jointed = (char *)malloc(sizeof(char) * (dst_len + src_len + 1));	
	if (!jointed)
		return (NULL);
	while (dst[++len_d])
		jointed[len_d] = dst[len_d];
	while (++len_s < src_len)
		jointed[len_d + len_s] = src[len_s];
	jointed[dst_len + src_len] = '\0';
	return (jointed);
	
}

char	*recursive_reading(int fd,char **file_info,char **line, int buffer_size)
{
	char	*data;
	char	*temp;
	int	size_break;
	int	set_zero;

	set_zero = -1;
	data = (char *)malloc(sizeof(char) * buffer_size);
	while (++set_zero < buffer_size)
		data[set_zero] = '\0';
	if (!data)
		*line = NULL;

	if (read(fd, data, buffer_size) == 0)
	{
		free(data);
		return (*line);
	}
	else
	{
		size_break = check_term_or_break(buffer_size, data);
		temp = strjoin(*line, data, size_break);
		if (!temp)
			free(data);
		if (!temp)
			return (NULL);
		if (*line)
			free(*line);
		*line = temp;
		if (size_break == buffer_size && data[size_break - 1] != '\n')
		{
			free(data);
			recursive_reading(fd, file_info, line, (buffer_size << 1));
		}
		else
		{
			temp = strjoin(*file_info,data + size_break, buffer_size - size_break);
			if (*file_info)
				free(*file_info);
			*file_info = temp;
			free(data);	
		}
	}
	return (*line);
}

char *get_next_line(int fd)
{
	static char	*file_buffer;	
	char		*line;
	int		size_in_file;

	if (fd < 0 || BUFFER_SIZE <= 0)	
		return (NULL);
	size_in_file = 0;
	if (!file_buffer)	
		file_buffer = strjoin("","",0);
	while(file_buffer[size_in_file])
		++size_in_file;
	line = strjoin("", file_buffer, size_in_file);
	recursive_reading(fd, &file_buffer, &line, BUFFER_SIZE);
	return line;
}
 
/*int main(int argc, char *argv[])
{
	char *path = argv[1];
	int count = 0;
	char *line;
	if (argc > 10)
		return (-1);
	int fd = open (path, O_RDONLY);
	line = 	get_next_line(fd);

	while (line[count])
		count++;
	write(1, line, count);
	free(line);
	count = 0;
	line = 	get_next_line(fd);
	while (line[count])
		count++;
	write(1, line, count);
	free(line);	
	return (0);
}*/
