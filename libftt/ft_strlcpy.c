/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihong <jihong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 18:58:10 by jihong            #+#    #+#             */
/*   Updated: 2021/11/19 16:26:49 by jihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(const void *dest, const void *src, size_t size)
{
	size_t	i;
	size_t	srcLen;

	srcLen = ft_strlen(src);
	i = 0;
	if (size == 0)
		return (srcLen);
	while (i < srcLen && i < size - 1)
	{
		*(char *)(dest + i) = *(const char *)(src + i);
		i ++;
	}
	*(char *)(dest + i) = '\0';
	return (srcLen);
}
