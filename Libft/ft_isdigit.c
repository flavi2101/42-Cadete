int	ft_isdigit(int c)
{
	unsigned char digit;
	digit = (unsigned char)(c);

	if (digit >= 48 && digit  <= 57)
		return (1);
	return (0);	
}
