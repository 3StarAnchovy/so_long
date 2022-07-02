/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_exception.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihong <jihong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 23:24:27 by jihong            #+#    #+#             */
/*   Updated: 2022/07/02 18:30:18 by jihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	file_exception(int fd)
{
	if (fd <= 0)
		error_massage("check files");
}

void	check_wall_exception(t_game_attribute *g)
{
	int	i;

	i = 0;
	while (i < (int)ft_strlen(g->map_str))
	{
		if (i < g->width)
		{
			if (g->map_str[i] != '1')
				error_massage("check wall\n");
		}
		else if (i % g->width == 0 || i % g->width == g->width - 1)
		{
			if (g->map_str[i] != '1')
				error_massage("check wall\n");
		}
		else if (i > (int)ft_strlen(g->map_str) - g->width)
		{
			if (g->map_str[i] != '1')
				error_massage("check wall\n");
		}
		i++;
	}
}

void	check_map_rectangle(t_game_attribute *g)
{
	if (g->width * g->height != (int)ft_strlen(g->map_str))
		error_massage("check map!!!!");
}

void	check_attribute_exception(t_game_attribute *g)
{
	int	palyer_num;
	int	door_num;
	int	i;

	i = 0;
	palyer_num = 0;
	door_num = 0;
	g->col = 0;
	g->col_have = 0;
	while (i ++ < (int)ft_strlen(g->map_str))
	{
		if (g->map_str[i] == 'E')
			door_num ++;
		else if (g->map_str[i] == 'P')
			palyer_num ++;
		else if (g->map_str[i] == 'C')
			g->col ++;
	}
	if (door_num == 0)
		error_massage("check door");
	if (palyer_num != 1)
		error_massage("check player");
	if (g->col == 0)
		error_massage("check collection");
}

void	check_all_exception(t_game_attribute *game)
{
	check_wall_exception(game);
	check_map_rectangle(game);
	check_attribute_exception(game);
}
