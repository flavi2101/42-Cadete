#include "libft.h"
void    *ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	store_size;
	size_t	counter;
	if (dest == NULL && src == NULL)
		return (dest);
	store_size = sizeof((size_t)src);
	if(store_size < n)
	{
		counter = 0;
		n = store_size;	
		while (counter < n)
			*(unsigned char *)(dest + counter++) = *(unsigned char *)src++;
	}
	return dest;
}
