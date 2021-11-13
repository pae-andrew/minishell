/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcredibl <gcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 18:21:50 by gcredibl          #+#    #+#             */
/*   Updated: 2021/11/13 18:21:51 by gcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*result;

	result = (char *)malloc(sizeof(*result) * (ft_strlen(s1) + 1));
	if (!result)
		return (0);
	ft_strlcpy(result, s1, ft_strlen(s1) + 1);
	return (result);
}
