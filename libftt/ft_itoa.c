/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihong <jihong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 16:43:35 by jihong            #+#    #+#             */
/*   Updated: 2021/12/08 22:06:11 by jihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_len(int n)
{
	size_t	len;

	len = 0;
	if (n < 0)
		len ++;
	else if (n == 0)
		return (1);
	else if (n == -2147483648)
		return (12);
	while (n != 0)
	{
		n /= 10;
		len ++;
	}
	return (len);
}

static char	*get_str(char *str, size_t i, size_t len, int n)
{
	while (i < len--)
	{
		*(str + len) = '0' + (n % 10);
		n /= 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	size_t		len;
	size_t		i;
	char		*str;

	len = get_len((size_t)n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (n == -2147483648)
	{
		ft_strlcpy(str, "-2147483648", len + 1);
		return (str);
	}
	if (str == NULL)
		return (NULL);
	*(str + len) = '\0';
	i = 0;
	if (n < 0)
	{
		*(str + i) = '-';
		n *= -1;
		i ++;
	}
	return (get_str(str, i, len, n));
}
