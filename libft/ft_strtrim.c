#include "libft.h"
#include <stdio.h>

char    *ft_strtrim(char const  *s1, char const *set)
{
	char	*str;
	int	counter;
	int	size;

	counter = 0;
	if (!(*set))
		return ft_strdup(s1);
	size = ft_strlen(s1) - 1;
	while (ft_strchr(set,s1[counter]))
		++counter;
	if (counter == size)
		return ft_strdup("");
	while (ft_strchr(set,s1[size]) && size > counter)
		--size;	
	str = (char *)malloc(sizeof(char) * (size - counter + 1));
	if (!str)
		return (NULL);	
	ft_strlcpy(str, s1 + counter, (size - counter));
	str[size - counter - 1]= '\0';
	return (str);
}
