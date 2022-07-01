/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihong <jihong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 18:55:16 by jihong            #+#    #+#             */
/*   Updated: 2021/11/17 19:47:54 by jihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include<stdio.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		i;
	int			j;
	char		*str;

	str = (char *)malloc(sizeof(char)
			* (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s1))
	{
		*(str + i) = *(s1 + i);
		i ++;
	}
	j = 0;
	while (i < ft_strlen(s1) + ft_strlen(s2))
	{
		*(str + i) = *(s2 + j);
		i ++;
		j ++;
	}
	*(str + i) = '\0';
	return (str);
}
