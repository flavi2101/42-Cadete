#include "libft.h"
#include <stdio.h>

// size_t	ft_strlen(const char *s)
// {
// 	size_t	counter;

// 	counter = 0;
// 	while (*s++)
// 		counter++;
// 	return (counter);
// }


// char	*ft_strdup(const char *s)
// {
// 	size_t	source_size;
// 	char	*dst;
// 	size_t	counter;

// 	counter = 0;
// 	source_size = ft_strlen(s);
// 	dst = (char *)malloc(sizeof(char) * (source_size + 1));
// 	if (!dst)
// 		return (NULL);
// 	while (counter < source_size)
// 		dst[counter++] = *s++;
// 	dst[counter] = '\0';
// 	return (dst);
// }
// char	*ft_strchr(const char *s, int c)
// {
// 	size_t		size;
// 	size_t		counter;

// 	counter = 0;
// 	size = ft_strlen(s) ;
// 	while (counter < size)
// 	{
// 		if (s[counter] == (char)c)
// 			return ((char *)(s + counter));
// 		++counter;
// 	}
// 	return (NULL);
// }
// void	*ft_memcpy(void *dest, const void *src, size_t n)
// {
// 	void	*cpy_dest;

// 	cpy_dest = dest;
// 	if ((size_t)dest - (size_t)src)
// 	{
// 		while (n-- > 0)
// 			*(unsigned char *)dest++ = *(unsigned char *)src++;
// 	}
// 	return (cpy_dest);
// }

char    *ft_strtrim(char const  *s1, char const *set)
{
	char	*str;
	static int	counter;
	int	size;

	if (!(*set))
		return ft_strdup(s1);
	size = ft_strlen(s1);
	while (ft_strchr(set,s1[counter]))
		++counter;
	if (counter == size)
		return ft_strdup("");
	while (ft_strchr(set,s1[size]) && size > counter)
		--size;	
	str = (char *)malloc(sizeof(char) * (size - counter +2));
	if (!str)
		return (NULL);	
	ft_memcpy(str, s1 + counter, (size - counter + 1 ));
	str[size - counter  + 1]= '\0';
	return (str);
}
// int main(void)
// {

// 	printf("%s", ft_strtrim("lorem ipsum dolor sit amet", "te"));
// 	return (0);
// }