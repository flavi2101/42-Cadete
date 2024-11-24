#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int	check_term_or_break(int buffers,char *data, int *qty_buffer)
{
	int	real_size;

	real_size = 0;
	while(real_size < buffers)
	{
		if (data[real_size] == '\n')
			return (real_size++);
		else if (data[real_size] == '\0')
			return (real_size++);
		real_size++;
	}
	(*qty_buffer)++;
	return (0);
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

/*void	*join_helper(char **file_info, char **data, int size)
{
	char *temp;

	temp = strjoin(*file_info, *data, size);
	if (!temp)
		return (NULL);
	if(*file_info)
		free(*file_info);
	*file_info = temp;
	free(*data);
	return (*file_info);
}*/	

int	recursive_reading(int fd,char **file_info, int buffer_size, int *qty_buffers)
{
	char	*data;
	int	nmb_of_buffers;
	int	size;
	char	*temp;

	size = 0;
	temp = NULL;
	nmb_of_buffers = buffer_size * (*qty_buffers);
	data = (char *)malloc(sizeof(char) * nmb_of_buffers);
	if (!data)
		return (-1);
	if (read(fd, data, nmb_of_buffers) <= 0)
	{
		free(data);
		return (-1);
	}
	size =check_term_or_break(nmb_of_buffers, data, qty_buffers); 
	if (size)
	{
		temp = strjoin(*file_info, data, size);
		free(data);	
		if (*file_info)
			free(*file_info);
		*file_info = temp;
	}
	else
	{
		temp = strjoin(*file_info, data, buffer_size);
		free(data);	
		if (*file_info)
			free(*file_info);
		*file_info = temp;
		return recursive_reading(fd, file_info, buffer_size, qty_buffers);
	}
	return (1);
}

char *get_next_line(int fd)
{
	static char	*file_buffer;	
	int			qnty_buffers;
	
	qnty_buffers = 1;
	if (fd < 0 || BUFFER == 0)	
		return (NULL);
	file_buffer = strjoin("","",0);
	while (recursive_reading(fd, &file_buffer, BUFFER, &qnty_buffers) > 0);
	return (file_buffer);
}

int main(int argc, char *argv[])
{
	char *path = argv[1];
	int	count = 0;

	if (argc > 10)
		return (-1);
	int fd = open (path, O_RDONLY);
	char *test = get_next_line(fd);
	while (test[count])
		count++;
	write(1, test, count);
	free(test);
	return (0);

}
