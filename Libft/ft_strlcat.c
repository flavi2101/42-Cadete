
#include "libft.h"
size_t  ft_strlcat(char *restrict dst, const char *restrict src, size_t dst_size)
{
	size_t	counter;
	size_t	dst_avaliable;
	size_t	src_size;

	src_size = ft_strlen(src);
	counter = ft_strlen(dst);
	dst_avaliable = dst_size - counter;
	if (dst_size > 0)
	{
		while (counter < (dst_avaliable - 1) && *src)
			dst[counter++] = *src++;		
		dst[counter] = '\0';	
	}
	return (src_size + dst_size);	
}
