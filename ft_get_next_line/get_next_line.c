#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

typedef struct s_store_index_of_break
{
	int	line_break;
	struct	 s_store_index_of_break	*next;	
}	t_index_break;

int	check_term_or_break(int buffers,char *data)
{
	int real_size;
	real_size = -1;
	
	while(++real_size < buffers)
	{
		if (data[real_size] == '\0')
			return (real_size);
	}
	return (buffers);
}

char	*strjoin(char *dst, char *src, int src_len)
{
	int dst_len;
	int cp_dst_len;
	char	*jointed;

	dst_len = 0;
	cp_dst_len = 0;

	while(dst[dst_len])
		dst_len++;
	jointed = (char *)malloc(sizeof(char) * (dst_len + src_len + 1));	
	if (!jointed)
		return (NULL);
	while (cp_dst_len < dst_len)
		jointed[cp_dst_len++] = *dst++;
	while (cp_dst_len < dst_len + src_len)
		jointed[cp_dst_len++] = *src++;
	jointed[dst_len + src_len] = '\0';
	return (jointed);
	
}

int	recursive_reading(int fd,char **file_info, int buffer_size, unsigned *len)
{
	char	*data;
	char	*temp;
	int	zero_set;

	zero_set = 0;
	data = (char *)malloc(sizeof(char) * buffer_size);
	if (!data)
		return (-1);
	while (zero_set < buffer_size)
		data[zero_set++] = '\0';
	if (read(fd, data, buffer_size) == 0)
	{
		free(data);
		return (0);
	}
	else
	{
		temp = strjoin(*file_info, data, buffer_size);
		if (*file_info)
			free(*file_info);
		*file_info = temp;
		*len = check_term_or_break(buffer_size, data);
		free(data);
		return recursive_reading(fd, file_info, buffer_size, len) + *len;
	}
}

char *get_next_line(int fd)
{
	static char	*file_buffer;	
	static unsigned		len;
	int		break_index;
	char		*line;
	int		cp_break_index;

	if (fd < 0 || BUFFER_SIZE == 0)	
		return (NULL);
	cp_break_index = 0;
	break_index = 0;
	if (!file_buffer)
	{
		file_buffer = strjoin("","",0);
		while (recursive_reading(fd, &file_buffer, BUFFER_SIZE, &len) > 0);
		if (!file_buffer)
			return (NULL);
	}
	if (len == 0)
		return (NULL);
	while(file_buffer[break_index] != '\n' && file_buffer[break_index] != '\0')
		break_index++;
	len -= ++break_index;
	line = (char *)malloc(sizeof(char) * (break_index + 1));
	if (!line)
		return (NULL);
	line[break_index--] = '\0';
	while (break_index-- >= 0)
		line[cp_break_index++] = *file_buffer++;	
	return (line);
}
 
int main(int argc, char *argv[])
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
}
