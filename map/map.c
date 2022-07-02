/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihong <jihong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 20:22:30 by jihong            #+#    #+#             */
/*   Updated: 2022/07/02 15:29:17 by jihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	read_map(char *name, t_game_attribute *game)
{
	int		fd;
	char	*line;

	fd = open(name, O_RDONLY);
	if (fd <= 0)
		error_massage("check files");
	line = get_next_line(fd);
	game->height = 0;
	game->width = (int)ft_strlen(line) - 1;
	game->walk_cnt = 0;
	game->map_str = ft_strnndup(line, game->width);
	free(line);
	while (line)
	{
		game->height ++;
		line = get_next_line(fd);
		if (line)
		{
			line = ft_strnndup(line, ft_strlen(line) - 1);
			game->map_str = ft_strjoin_free(game->map_str, line);
		}
	}
	close(fd);
}

void	map_init(t_game_attribute *game)
{
	int	wid;
	int	hei;

	wid = game->width * 16;
	hei = game->height * 16;
	game->win = mlx_new_window(game->mlx, wid, hei, "mlx_project");
}

void	put_image(t_game_attribute *g, int h, int w)
{
	if (g->map_str[h * g->width + w] == '1')
		mlx_put_image_to_window(g->mlx, g->win, g->img.wall, w * 16, h * 16);
	else if (g->map_str[h * g->width + w] == '0')
		mlx_put_image_to_window(g->mlx, g->win, g->img.grass, w * 16, h * 16);
	else if (g->map_str[h * g->width + w] == 'P')
		mlx_put_image_to_window(g->mlx, g->win, g->img.player, w * 16, h * 16);
	else if (g->map_str[h * g->width + w] == 'C')
		mlx_put_image_to_window(g->mlx, g->win, g->img.box, w * 16, h * 16);
}

void	render_map(t_game_attribute *g)
{
	int	wid;
	int	hei;

	hei = 0;
	while (hei < g->height)
	{
		wid = 0;
		while (wid < g->width)
		{
			put_image(g, hei, wid);
			wid ++;
		}
		hei ++;
	}
}
