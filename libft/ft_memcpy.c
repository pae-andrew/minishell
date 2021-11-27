/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstyx <sstyx@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 18:20:36 by gcredibl          #+#    #+#             */
/*   Updated: 2021/11/21 19:11:46 by sstyx            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void	*result;

	result = dst;
	if (dst == src)
		return (result);
	while (n--)
		*(char *)dst++ = *(char *)src++;
	return (result);
}
