/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lenu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajed <asajed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 20:58:49 by asajed            #+#    #+#             */
/*   Updated: 2024/12/01 14:32:37 by asajed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_lenu(unsigned int n)
{
	unsigned int	j;

	j = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		j++;
	}
	return (j);
}
