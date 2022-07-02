/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihong <jihong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 19:01:48 by jihong            #+#    #+#             */
/*   Updated: 2022/07/02 16:23:17 by jihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clear_game(t_game_attribute *game)
{
	game->walk_cnt ++;
	write(1, "clear!\n", 8);
	exit(0);
}

void	move_w(t_game_attribute *g)
{
	size_t	i;

	i = 0;
	while (i ++ < ft_strlen(g->map_str))
	{
		if (g->map_str[i] == 'P')
			break ;
	}
	if (g->map_str[i - g->width] == 'C')
		g->col_have ++;
	if (g->map_str[i - g->width] == 'E' && g->col == g->col_have)
		clear_game(g);
	else if (g->map_str[i - g->width] != '1' && g->map_str[i - g->width] != 'E')
	{
		g->map_str[i] = '0';
		g->map_str[i - g->width] = 'P';
		g->walk_cnt++;
		write(1, "walk : ", 8);
		ft_putnbr_fd(g->walk_cnt, 1);
		write(1, "\n", 2);
		render_map(g);
	}
}

void	move_a(t_game_attribute *g)
{
	size_t	i;

	i = 0;
	while (i ++ < ft_strlen(g->map_str))
	{
		if (g->map_str[i] == 'P')
			break ;
	}
	if (g->map_str[i - 1] == 'C')
		g->col_have ++;
	if (g->map_str[i - 1] == 'E' && g->col == g->col_have)
		clear_game(g);
	else if (g->map_str[i - 1] != '1' && g->map_str[i - 1] != 'E')
	{
		g->map_str[i] = '0';
		g->map_str[i - 1] = 'P';
		g->walk_cnt++;
		write(1, "walk : ", 8);
		ft_putnbr_fd(g->walk_cnt, 1);
		write(1, "\n", 2);
		render_map(g);
	}
}

void	move_d(t_game_attribute *g)
{
	size_t	i;

	i = 0;
	while (i ++ < ft_strlen(g->map_str))
	{
		if (g->map_str[i] == 'P')
			break ;
	}
	if (g->map_str[i + 1] == 'C')
		g->col_have ++;
	if (g->map_str[i + 1] == 'E' && g->col == g->col_have)
		clear_game(g);
	else if (g->map_str[i + 1] != '1' && g->map_str[i + 1] != 'E')
	{
		g->map_str[i] = '0';
		g->map_str[i + 1] = 'P';
		g->walk_cnt++;
		write(1, "walk : ", 8);
		ft_putnbr_fd(g->walk_cnt, 1);
		write(1, "\n", 2);
		render_map(g);
	}
}

void	move_s(t_game_attribute *g)
{
	size_t	i;

	i = 0;
	while (i ++ < ft_strlen(g->map_str))
	{
		if (g->map_str[i] == 'P')
			break ;
	}
	if (g->map_str[i + g->width] == 'C')
		g->col_have ++;
	if (g->map_str[i + g->width] == 'E' && g->col == g->col_have)
		clear_game(g);
	else if (g->map_str[i + g->width] != '1' && g->map_str[i + g->width] != 'E')
	{
		g->map_str[i] = '0';
		g->map_str[i + g->width] = 'P';
		g->walk_cnt++;
		write(1, "walk : ", 8);
		ft_putnbr_fd(g->walk_cnt, 1);
		write(1, "\n", 2);
		render_map(g);
	}
}
