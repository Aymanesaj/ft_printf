/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajed <asajed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:02:12 by asajed            #+#    #+#             */
/*   Updated: 2024/11/26 22:53:43 by asajed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_argprint(char c, va_list lst)
{
	if (c == 'c')
		return ((ft_putchar((char)va_arg(lst, int))));
	else if (c == 'd' || c == 'i')
		return ((ft_putnbr(va_arg(lst, int))));
	else if (c == 'u')
		return ((ft_unsign(va_arg(lst, size_t))));
	else if (c == 's')
		return ((ft_putstr(va_arg(lst, char *))));
	else if (c == '%')
		return ((ft_putchar('%')));
	else if (c == 'p')
		return ((ft_address(va_arg(lst, unsigned long), "0123456789abcdef")));
	else if (c == 'x')
		return ((ft_putnbr_base(va_arg(lst, unsigned int)
					, "0123456789abcdef")));
	else if (c == 'X')
		return ((ft_putnbr_base(va_arg(lst, unsigned int)
					, "0123456789ABCDEF")));
	return (-1);
}

int	ft_printf(const char *str, ...)
{
	va_list	lst;
	int		result;
	int		j;
	int		i;

	result = 0;
	i = 0;
	j = 0;
	va_start(lst, str);
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == '\0')
				return (-1);
			else if ((j = check_argprint(str[i], lst)) < 0)
				{
					if ((j = bonus_flags(str, lst, &i)) < 0)
						return (-1);
					else
						result += j;
				}
			else if (j)
				result += j;
		}
		else
			result += ft_putchar(str[i]);
		i++;
	}
	va_end(lst);
	return (result);
}

int main()
{
	// print("%1s", "")
	int i = ft_printf("%04d", -14);
	printf("\n[[%d]]\n",i);
	int j = printf("%04d", -14);
	// int j = printf("%x",NULL);
	printf("\n[[%d]]\n",j);
}
