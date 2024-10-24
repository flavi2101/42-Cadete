#include "libft.h"
size_t	check_n_size(const char *str1, const char *str2, size_t n)
{
	size_t	size1;
	size_t	size2;

	size1 = ft_strlen(str1);
	size2 = ft_strlen(str2);
	if( n > size1 || n > size2)
	{
		if (size1 > size2)
			n = size2;
		if (size1 < size2)
			n = size1;	
	}
	return (n);
}
int	ft_memcmp(const void *s1, const void  *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t		temp;

	//n = check_n_size(s1, s2, n);
	temp = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while ( temp < n)
	{
		if (str1[temp] != str2[temp])
			return (str1[temp] - str2[temp]);
		++temp;
	}	
	return (0);
}
