#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

char    *ft_strjoin(char const *s1, char const *s2)
{
        char            *dst;
        size_t          total_len;
        size_t          len1;
        size_t          len2;

        len1 = ft_strlen(s1);
        len2 = ft_strlen(s2);
        total_len = len1 + len2 + 1;
        dst = (void *)malloc(sizeof(char) * total_len);
        if (!dst)
                return (NULL);
        ft_memmove(dst, s1, len1);
        ft_memmove((dst + len1), s2, len2);
        dst[total_len -1] = '\0';
        return ((char *)dst);
}
void	*recursive_reading(int fd, int buffer_size,  void *file_info, int *qty_buffers)
{
	int	size_readed;
	char	*data;
	int	real_size;

	real_size = -1;
	data = (char *)malloc(sizeof(char) * buffer_size * (*qty_buffers));
	if (!data)
		return (NULL);
	size_readed = read(fd, data, buffer_size);
	if (data[size_readed - 1] == '\0' || data[size_readed -1] == '\n') 
		ft_strjoin(file_info, data);
	else if (*qty_buffers > 0)
	{
		while(++real_size < size_readed)
		{
			if (data[real_size + (*qty_buffers * buffer_size)] == '\n')
				break;
			else if (data[real_size++] == '\0')
				break;
		}
	}
	else if (*qty_buffers == 1)
	{
		while(++real_size < size_readed)
		{
			if (data[real_size] == '\n')
				break;	
			else if (data[real_size++] == '\0')
				break;
		}
	}
}

char *get_next_line(int fd)
{
	static char	*file_buffer;	
	int			initial_position;
	int			qnty_buffers;
	
	qnty_buffers = 0;
	initial_position = 0;
	if (fd < 0 || BUFFER == 0)	
		return (NULL);
	file_buffer = "";
	recursive_reading(fd, BUFFER, file_buffer, &qnty_buffers);
	return ((char *)file_buffer);
}

int main(int argc, char *argv[])
{
	char *path = argv[1];

	int fd = open (path, O_RDONLY);
	while (get_next_line(fd) != NULL)
	{
		write (1, get_next_line(fd), BUFFER);	
	}
	return (0);

}
