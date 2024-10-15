#include "libft.h"
size_t  ft_strlcpy(char *dst, const char *src, size_t dst_size)
{
	size_t	src_size;
	size_t	counter;

	src_size = ft_strlen(src);
	counter = 0;
	if (dst_size > 0)
	{
		while (counter++ < (dst_size - 1) && *src) 
			*dst++ = *src++;
		dst[counter] = '\0';
	}
	return (src_size);
}
