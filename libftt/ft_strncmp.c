/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihong <jihong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:21:18 by jihong            #+#    #+#             */
/*   Updated: 2021/12/02 17:40:04 by jihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (*(s1 + i) != '\0' || *(s2 + i) != '\0'))
	{
		if (*(s1 + i) - *(s2 + i) > 0)
			return ((unsigned char)*(s1 + i) - (unsigned char)*(s2 + i));
		else if (*(s1 + i) - *(s2 + i) < 0)
			return ((unsigned char)*(s1 + i) - (unsigned char)*(s2 + i));
		i ++;
	}
	return (0);
}
