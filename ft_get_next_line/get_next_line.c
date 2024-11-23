#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

int	recursive_reading(int fd, int buffer_size, int *real_size)
{
	int	size_readed;
	char	*data;

	data = (char *)malloc(sizeof(char) * buffer_size);
	if (!data)
		return (0);
	size_readed = read(fd, data, buffer_size);
	while(*real_size <= size_readed)
	{
		if (data[*real_size++] == '\n' ||  data[size_readed] == '\0')	
			return (*real_size - 1);
	}
	free(data);
	recursive_reading(fd, )
	
}

char *get_next_line(int fd)
{
	static void	*file_buffer;	
	char		*get_buffer;
	int			initial_position;

	initial_position = 0;
	if (fd < 0 || BUFFER == 0)	
		return (NULL);
	get_buffer = (char *)malloc(sizeof(char) * BUFFER);
	if (!get_buffer)
		return (NULL);
	recursive_reading(fd, BUFFER, &initial_position);
	return ((char *)file_buffer);
}
