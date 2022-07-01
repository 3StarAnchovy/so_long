/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihong <jihong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 18:04:21 by jihong            #+#    #+#             */
/*   Updated: 2021/12/11 20:44:19 by jihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	i = 0;
	if(ft_strlen(s) < len)
		len = ft_strlen(s);
	substr = (char *)malloc(sizeof(char) * (len) + 1);
	if (substr == NULL)
		return (NULL);
	if (ft_strlen(s) > start)
	{
		while (i < len)
		{
			*(substr + i) = *(s + start + i);
			i ++;
		}
	}
	*(substr + i) = '\0';
	return (substr);
}
