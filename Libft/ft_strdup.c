#include <stdlib.h>
#include "libft.h"
char *ft_strdup(const char *s)
{
	size_t	source_size;
	char	*dst;
	int	counter;

	counter = 0;
	source_size = ft_strlen(s) + 1;
	dst = (char *)malloc(sizeof(char) * (source_size));
	while (source_size-- > 0)
		dst[counter++] = *s++;		
	dst[counter] = '\0';
	return (dst);
}
