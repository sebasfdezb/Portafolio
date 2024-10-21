int	string_to_hash(void *str)
{
	int				result;
	unsigned char	*aux;

	result = 5381;
	aux = (unsigned char *)str;
	while (*aux)
	{
		result = result * 33 + *aux;
		++aux;
	}
	return (result);
}