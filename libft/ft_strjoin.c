/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcredibl <gcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 18:21:57 by gcredibl          #+#    #+#             */
/*   Updated: 2021/11/13 18:21:57 by gcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	char	*ptr;
	size_t	size;

	if (!s1 && !s2)
		return (0);
	size = 0;
	if (s1)
		size = size + ft_strlen(s1);
	if (s2)
		size = size + ft_strlen(s2);
	result = malloc(sizeof(*result) * (size + 1));
	if (!result)
		return (0);
	ptr = result;
	while (s1 && *s1)
		*ptr++ = *s1++;
	while (s2 && *s2)
		*ptr++ = *s2++;
	*ptr = '\0';
	return (result);
}
