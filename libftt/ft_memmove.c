/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihong <jihong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 20:52:38 by jihong            #+#    #+#             */
/*   Updated: 2021/11/28 17:33:28 by jihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	size_t	i;
	size_t	back_index;

	if (dest == src || size == 0)
		return (dest);
	i = 0;
	if (dest < src)
	{
		while (i < size)
		{
			*(char *)(dest + i) = *(const char *)(src + i);
			i ++;
		}
	}
	else
	{
		while (i < size)
		{
			back_index = size - i - 1;
			*(char *)(dest + back_index) = *(const char *)(src + back_index);
			i ++;
		}
	}
	return (dest);
}
