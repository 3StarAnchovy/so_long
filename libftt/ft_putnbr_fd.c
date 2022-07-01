/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihong <jihong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 00:12:22 by jihong            #+#    #+#             */
/*   Updated: 2021/12/03 19:25:57 by jihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	rec_nb(int div, int mod, char str, int fd)
{
	mod = div % 10;
	div /= 10;
	if (div != 0)
		rec_nb(div, mod, str, fd);
	str = '0' + mod;
	write(fd, &str, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	str;

	if (fd < 0)
		return ;
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
		str = '\0';
		rec_nb(n, 0, str, fd);
	}
	else
		rec_nb(n, 0, '\0', fd);
}
