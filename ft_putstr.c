/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajed <asajed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 23:57:47 by asajed            #+#    #+#             */
/*   Updated: 2024/12/01 14:33:20 by asajed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putstr(const char *s)
{
	int	i;
	int	result;

	if (!s)
		return (write(1, "(null)", 6));
	i = 0;
	result = 0;
	while (s[i])
	{
		result += write(1, &s[i], 1);
		i++;
	}
	return (result);
}
