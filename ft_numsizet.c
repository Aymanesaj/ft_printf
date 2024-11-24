#include "libftprintf.h"

size_t	ft_numsizet(size_t n)
{
	char	c;
	int		result;

	result = 0;
	if ((n / 10) > 0)
		result += ft_putnbr((n / 10));
	c = (n % 10) + '0';
	result += write(1, &c, 1);
	return (result);
}