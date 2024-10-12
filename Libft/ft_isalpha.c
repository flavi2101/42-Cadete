int	ft_isalpha(int c)
{
	unsigned char letter;
	
	letter = (unsigned char)(c);
	if ((letter >=65 && letter <= 90) || (letter >= 97 && letter <= 122))
		return (1);
	return (0);
}	

