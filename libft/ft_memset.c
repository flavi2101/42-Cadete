#include "libft.h"
void    *ft_memset(void *str, int c, size_t n)
{
	int	counter;
	unsigned char	*byte_str = (unsigned char *)str;

	counter =0;
	while (n-- > 0)
		byte_str[counter++] = (unsigned char)c;
	return (str);
}
