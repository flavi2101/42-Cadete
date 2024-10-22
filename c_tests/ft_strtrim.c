#include "libft.h"
size_t	trim_counter(char const *str1, char const *str2, size_t len)
{
	size_t	counter;
	size_t	size;

	size = ft_strlen(str1);
	counter = 0;	
	while (*str1 && (size- len) >= len)
	{
		if (*str1 == *str2)
			if(!ft_strncmp(str1, str2, len))
				++counter;	
		++str1;
	}
	return (counter);
}
char	*ft_strtrim(char const	*s1, char const *set)
{
	size_t	counter;
	char	*letter;
	size_t	temp;
	size_t	size_set;

	counter = 0;
	size_set = ft_strlen(set);
	temp = ft_strlen(s1) - (size_set * trim_counter(s1,set,size_set));
	letter = (char *)malloc(sizeof(char) * temp);
	temp = 0;
	if (!letter)
		return (NULL);
	while (s1[counter])
	{
		if (!(s1[counter] == *set))
			letter[temp++] = s1[counter++];
		else
			if(!ft_strncmp(&s1[counter], set, size_set))
				counter += size_set;
			else
				++counter;	
	}
	letter[temp] = '\0';
	return (letter);
}
