/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihong <jihong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 21:42:46 by jihong            #+#    #+#             */
/*   Updated: 2021/12/06 15:53:53 by jihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*strndup(char const *str, int n)
{
	int		i;
	char	*copy;

	copy = (char *)malloc(sizeof(char) * (n + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < n)
	{
		*(copy + i) = *(str + i);
		i ++;
	}
	*(copy + i) = '\0';
	return (copy);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*copy;

	start = 0;
	end = ft_strlen(s1);
	while (*(s1 + start) && ft_strchr(set, *(s1 + start)))
		start ++;
	while (*(s1 + end - 1) && ft_strchr(set, *(s1 + end - 1)) && end > start)
		end --;
	copy = strndup(s1 + start, end - start);
	return ((char *)(copy));
}
