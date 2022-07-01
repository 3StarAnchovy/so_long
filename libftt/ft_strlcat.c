/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihong <jihong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 20:09:01 by jihong            #+#    #+#             */
/*   Updated: 2021/11/19 18:04:06 by jihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	destLen;

	i = 0;
	destLen = ft_strlen(dest);
	if (size != 0 && destLen < size)
	{
		while (*(src + i) != '\0' && i < size - destLen - 1)
		{
			*(dest + destLen + i) = *(src + i);
			i ++;
		}
		*(dest + destLen + i) = '\0';
		return (destLen + ft_strlen(src));
	}
	return (ft_strlen(src) + size);
}
