/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajed <asajed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:02:12 by asajed            #+#    #+#             */
/*   Updated: 2024/11/25 22:20:08 by asajed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	check_argprint(char c, va_list lst)
{
	if (c == 'c')
		return ((ft_putchar((char)va_arg(lst, int))));
	if (c == 'd' || c == 'i')
		return ((ft_putnbr(va_arg(lst, int))));
	if (c == 'u')
		return ((ft_unsign(va_arg(lst, size_t))));
	if (c == 's')
		return ((ft_putstr(va_arg(lst, char *))));
	if (c == '%')
		return ((ft_putchar('%')));
	if (c == 'p')
		return ((ft_address(va_arg(lst, unsigned long))));
	if (c == 'x')
		return ((ft_putnbr_base(va_arg(lst, unsigned int)
					, "0123456789abcdef")));
	if (c == 'X')
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
			if ( (j = check_argprint(str[i], lst)) < 0)
				result += bonus_flags(str, lst, &i);
			result += j;
		}
		else
			result += ft_putchar(str[i]);
		i++;
	}
	va_end(lst);
    // printf("\n[[[[len : %d]]]]\n",result);
	return (result);
}

int main()
{
	int i = ft_printf("%-4d",500);
	ft_printf("\n[[%d]]\n",i);
	int j = printf("%-4d",500);
	printf("\n[[%d]]\n",j);
}