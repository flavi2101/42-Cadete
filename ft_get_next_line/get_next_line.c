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
	len_d = 0;
	len_s = -1;
	if (dst)
	{
		while(dst[dst_len])
			dst_len++;
	}
	jointed = (char *)malloc(sizeof(char) * (dst_len + src_len + 1));	
	if (!jointed)
		return (NULL);
	if (dst)
	{
		while (dst[len_d])
		{
			jointed[len_d] = dst[len_d];
			len_d++;
		}
	}
	while (++len_s < src_len)
		jointed[len_d + len_s] = src[len_s];
	jointed[dst_len + src_len] = '\0';
	return (jointed);
	
}

char	*recursive_reading(int fd,char **file_info, int buffer_size)
{
	char	*data;
	char	*temp;
	int	size_break;
	int	set_zero;

	set_zero = 0;
	data = (char *)malloc(sizeof(char) * (buffer_size));
	if(!data )
	{
		if (*file_info)
			free(*file_info);
		*file_info = (NULL);
		return (*file_info);
	}
	while (set_zero < buffer_size)
		data[set_zero++] = '\0';
	set_zero = read(fd, data, buffer_size);
	if (set_zero <= 0)
	{
		free(data);
		return (NULL);
	}
	size_break = check_term_or_break(buffer_size, data);
	if(!(*file_info))
		temp = strjoin(NULL, data, size_break);
	else
		temp = strjoin(*file_info, data, size_break);
	if (!temp)
	{
		free(data);
		if(*file_info)
			free(*file_info);
		*file_info = NULL;
		return (*file_info);
	}
	if (*file_info)
		free(*file_info);
	*file_info= temp;
	if (size_break == buffer_size && data[size_break - 1] != '\n')
	{
		free(data);
		return recursive_reading(fd, file_info, (buffer_size << 1));
	}
	temp = strjoin(*file_info,data + size_break, buffer_size - size_break);
	free(data);
	if (!temp)
	{
		free(*file_info);
		*file_info = NULL;
		return (NULL);
	}
	free(*file_info);
	*file_info = temp;
	return *file_info;
}


char *get_next_line(int fd)
{
    static char *file_buffer = NULL;  // Explicitly initialize
    int counter;
    int total;
    char *line;
    char *temp;

    // Reset variables
    line = NULL;
    temp = NULL;
    counter = 0;
    total = 0;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);

    // If no buffer, read initial data
    if (!file_buffer) {
        file_buffer = recursive_reading(fd, &file_buffer, BUFFER_SIZE);
        if (!file_buffer)
            return (NULL);
    }

    // Find line length
    while(file_buffer[counter] && file_buffer[counter] != '\n')
        counter++;

    // Include newline if present
    if (file_buffer[counter] == '\n')
        counter++;

    // Calculate total buffer length
    while(file_buffer[total])
        total++;

    // Extract line
    line = strjoin(NULL, file_buffer, counter);
    if (!line) {
        // Free buffer if line creation fails
        free(file_buffer);
        file_buffer = NULL;
        return (NULL);
    }

    // Create new buffer with remaining content
    if (counter < total) {
        temp = strjoin(NULL, file_buffer + counter, total - counter);
        free(file_buffer);
        file_buffer = temp;
    } else {
        // Buffer is exhausted
        free(file_buffer);
        file_buffer = NULL;
    }

    return line;
}



/*
char *get_next_line(int fd)
{
	static char	*file_buffer;	
	int	counter;
	int	total;
	char		*line;
	char		*temp;

	line = NULL;
	temp = NULL;
	total = 0;
	counter = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)	
		return (NULL);
	file_buffer = recursive_reading(fd, &file_buffer, BUFFER_SIZE);
	if (!file_buffer)
		return (NULL);
	while(file_buffer[counter] != '\n')
		counter++;
	while(file_buffer[total])
		total++;
	line = strjoin("", file_buffer, counter + 1);
	if(!line)
	{
		free(file_buffer);
		return (NULL);
	}
	temp = strjoin(NULL, file_buffer + counter + 1, (total - counter -1)) ;
	if(!temp)
	{
		free(line);
		free(file_buffer);	
		return (NULL);
	}
	free(file_buffer);
	file_buffer = temp;
	return line;
}
*/
/*#include <stdio.h> 
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
	}
	return (0);
}
*/

