#include <stdlib.h>
#include <stdio.h>
static int	count_letter(char *s, char c)
{
	int	counter;

	counter = 0;
	while (*s && *s++ != c) ++counter;
	return (counter);
}

static int	find_char(char *s, char c)
{
	int	counter;
	
	counter = 0;
	while(*s)
	{
		if (*s == c)
		{
			++counter;
			while(*s == c) s++;
		}
		++s;
	}
	return (counter);
}
int	cleaner(char **ptr, int temp)
{
	while (temp >= 0)
	{
		free(ptr[temp--]);
	}
	free(ptr);
	return (1);
}
char    **ft_split(char const   *s, char c)
{
	char	**ptr;
	int	counter;
	int	quantity;
	int	temp;
	
	counter = 0;
	quantity = 0;
	temp = 0;
	while(*s == c) s++;
	quantity = find_char((char *)s, c);
	if (!quantity)
		return ((char **)s);
	ptr = (char **)malloc(sizeof(char *) * (quantity + 1));
	if (!ptr) return (NULL);
	while (*s)
	{
		quantity = 0;
		counter = count_letter((char *)s, c);
		ptr[temp] = (char *)malloc(sizeof(char) * counter + 1);
		if(!ptr[temp] && (int)cleaner(ptr, temp)) return (NULL);
		ptr[temp][counter] = '\0';
		while (--counter >= 0)
			ptr[temp][quantity++] = *s++;
		++temp;
		while(*s == c) s++;
	}
	ptr[temp] = NULL;
	return (ptr);
}
int main(int argc, char *argv[])
{
	char const *val1 = argv[1];
	char  val2 = argv[2][0];

	char **result = ft_split(val1, val2);
	if (!result) // Check for allocation failure
	{
	printf("Memory allocation failed\n");
	return 1;
	}

	    // Print the resulting split strings
    for (int i = 0; result[i] != NULL; i++)
	    {
		printf("%s\n", result[i]);
		free(result[i]); // Free each allocated string
	    }
	    free(result); // Free the array of strings	return (0);
}
