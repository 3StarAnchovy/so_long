/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihong <jihong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 20:09:01 by jihong            #+#    #+#             */
/*   Updated: 2022/07/02 16:04:05 by jihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	dest_len;

	i = 0;
	dest_len = ft_strlen(dest);
	if (size != 0 && dest_len < size)
	{
		while (*(src + i) != '\0' && i < size - dest_len - 1)
		{
			*(dest + dest_len + i) = *(src + i);
			i ++;
		}
		*(dest + dest_len + i) = '\0';
		return (dest_len + ft_strlen(src));
	}
	return (ft_strlen(src) + size);
}
