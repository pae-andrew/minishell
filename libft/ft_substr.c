/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcredibl <gcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 18:22:38 by gcredibl          #+#    #+#             */
/*   Updated: 2021/11/13 18:22:38 by gcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;

	if (!s)
		return (0);
	result = ft_calloc(len + 1, sizeof(*result));
	if (!result)
		return (0);
	if (ft_strlen(s) <= start)
		return (result);
	ft_memcpy(result, s + start, len);
	return (result);
}
