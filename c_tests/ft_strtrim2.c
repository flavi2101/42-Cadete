#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
size_t	ft_strlen(const char *s)
{
	size_t	counter;

	counter = 0;
	while (*s++)
		counter++;
	return (counter);
}
char	*ft_strchr(const char *s, char c)
{
	size_t		size;
	size_t		counter;

	counter = 0;
	size = ft_strlen(s) + 1;
	while (counter < size)
	{
		if (s[counter] == c)
			return ((char *)(s + counter));
		++counter;
	}
	return (NULL);
}
char	*ft_strdup(const char *s)
{
	size_t	source_size;
	char	*dst;
	size_t	counter;

	counter = 0;
	source_size = ft_strlen(s);
	dst = (char *)malloc(sizeof(char) * (source_size + 1));
	if (!dst)
		return (NULL);
	while (counter < source_size)
		dst[counter++] = *s++;
	dst[counter] = '\0';
	return (dst);
}
void    *ft_memcpy(void *dest, const void *src, size_t n)
{
        void    *cpy_dest;

        cpy_dest = dest;
        if ((size_t)dest - (size_t)src)
        {
                while (n-- > 0)
                        *(unsigned char *)dest++ = *(unsigned char *)src++;
        }
        return (cpy_dest);
}


void	*ft_memmove(void *dest, const void	*src, size_t n)
{
	int	counter;

	counter = (int)n;
	if (dest == (NULL) || src == (NULL) || n == 0)
		return (dest);
	if (dest > src)
	{
		while (--counter >= 0)
			((unsigned char *)dest)[counter] = ((unsigned char *)src)[counter];
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
char    *ft_strtrim(char const  *s1, char const *set)
{
	char	*str;
	static int	counter;
	int	size;

	if (!(*set))
		return (char *)s1;
	size = ft_strlen(s1) - 1;
	while (ft_strchr(set,s1[counter]) && counter < size)
		++counter;
	if (counter == size)
		return ft_strdup(s1);
	while (ft_strchr(set,s1[size]) && size > counter)
		--size;	
	str = (char *)malloc(sizeof(char) * (size - counter));
	if (!str)
		return (NULL);	
	ft_memmove(str, s1 + counter, (size - counter));
	return (str);
}
int main(int argc, char *argv[])
{
	char const * val1 = argv[1];
	char const * val2 = argv[2];

	printf("%s\n",ft_strtrim(val1, val2));
	return (0);
}
