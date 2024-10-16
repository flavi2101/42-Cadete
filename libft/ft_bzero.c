#include "libft.h"
void    ft_bzero(void *str, size_t n)
{
	unsigned char	*str_byte;

	str_byte = (unsigned char *)str;
	while (n-- > 0)
		*str_byte++ = '\0';
}
