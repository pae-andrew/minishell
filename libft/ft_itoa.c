/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcredibl <gcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 18:19:27 by gcredibl          #+#    #+#             */
/*   Updated: 2021/11/13 18:19:27 by gcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_length(int n)
{
	int	result;

	result = 1;
	if (n < 0)
		result++;
	n = n / 10;
	while (n)
	{
		result++;
		n = n / 10;
	}
	return (result);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		length;
	int		i;
	int		j;

	length = get_length(n);
	result = malloc(sizeof(*result) * (length + 1));
	if (!result)
		return (0);
	j = 0;
	if (n < 0)
		j = 1;
	i = length - 1;
	while (i >= j)
	{
		result[i] = '0' + (n % 10);
		if (n < 0)
			result[i] = '0' + -(n % 10);
		n = n / 10;
		i--;
	}
	if (j != 0)
		result[0] = '-';
	result[length] = 0;
	return (result);
}
