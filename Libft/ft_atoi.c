 int	atoi(const char *nptr)
{
	int	return_value;
	int	flag;
	int	expression;
	
	return_value = 0;
	flag = 1;	
	while (*nptr == ' ')
		++nptr;
	if (*nptr == '-')
	{
		flag*= -1;
		++nptr;
	}
	expression = *nptr >= '0' && *nptr <= '9';
	if (!expression)
		return (return_value);
	while (*nptr && (expression))
	{
		return_value = return_value * 10 +  (*nptr++ - 48);
		expression = *nptr >= '0' && *nptr <= '9';
	}
	return (flag * return_value);
}