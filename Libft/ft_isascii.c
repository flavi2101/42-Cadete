int	ft_isascii(int c)
{
	unsigned char check_char;
	
	check_char = (unsigned char)(c);
	if (check_char <= 127)
		return (1);
	return (0);

}
