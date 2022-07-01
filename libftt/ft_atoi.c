/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihong <jihong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 18:20:01 by jihong            #+#    #+#             */
/*   Updated: 2021/12/07 16:49:02 by jihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	result;
	int	pos;
	int	i;

	result = 0;
	pos = 1;
	i = 0;
	while ((*(str + i) >= 9 && *(str + i) <= 13) || *(str + i) == ' ')
		i ++;
	if (*(str + i) == '+' || *(str + i) == '-')
	{
		if (*(str + i) == '-')
			pos = -1;
		i ++;
	}
	while (*(str + i) >= '0' && *(str + i) <= '9')
	{
		result *= 10;
		result += *(str + i) - '0';
		i ++;
	}
	return (result * pos);
}
