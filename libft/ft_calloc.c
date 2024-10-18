#include "libft.h"

void    *ft_calloc(size_t nmemb, size_t size)
{
	size_t	total_size;
	void *	ptr;	
	char *	temp;

	total_size = nmemb * size;
	if ( total_size > 4294967296)
		return (NULL);
	temp = malloc(sizeof(char) * total_size);	
	ptr = (void *)temp;
	if (!temp)
		return (NULL);
	while (total_size-- > 0)
		*temp++ = 0;	
	return (ptr);
}
