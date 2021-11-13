/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcredibl <gcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 18:22:29 by gcredibl          #+#    #+#             */
/*   Updated: 2021/11/13 18:22:29 by gcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	length;
	size_t	i;

	length = ft_strlen(s);
	i = 0;
	while (i <= length)
	{
		if (*(char *)(s + length - i) == (char)c)
			return ((char *)(s + length - i));
		i++;
	}
	return (0);
}
