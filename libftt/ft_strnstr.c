/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihong <jihong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:11:02 by jihong            #+#    #+#             */
/*   Updated: 2021/12/05 17:47:43 by jihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (*(haystack + i) != '\0' && i + ft_strlen(needle) <= len)
	{
		if (*(haystack + i) == *needle)
		{
			j = 0;
			while (*(haystack + i + j) == *(needle + j) && i + j < len)
			{
				if (*(needle + j + 1) == '\0' && i + j < len)
					return ((char *)(haystack + i));
				j ++;
			}
		}
		i ++;
	}
	return (NULL);
}
