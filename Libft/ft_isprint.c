int	ft_isprint(int c)
{
	unsigned char is_printable;
	
	is_printable = (unsigned char)(c); 
	if ( is_printable >= 32 && is_printable <= 126)
		return (1);
	return (0);
}
