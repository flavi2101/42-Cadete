#include "libft.h"

char    *ft_strtrim(char const  *s1, char const *set)
{
	char	*str;
	static int	counter;
	int	size;

	if (!(*set))
		return (char *)s1;
	size = ft_strlen(s1) - 1;
	while (ft_strchr(set,s1[counter] && counter < size))
		++counter;
	if (counter == size)
		return ft_strdup(s1);
	while (ft_strchr(set,s1[size] && size > counter))
		--size;	
	str = (char *)malloc(sizeof(char) * (size - counter));
	if (!str)
		return (NULL);	
	ft_memmove(str, s1 + counter, (size - counter));
	return (str);
}
