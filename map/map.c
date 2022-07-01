/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihong <jihong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 20:22:30 by jihong            #+#    #+#             */
/*   Updated: 2022/07/01 17:52:28 by jihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void read_map(char *name, t_game_attribute *game)
{
	int		fd;
	char	*line;

	fd = open(name,O_RDONLY);
	if(fd <= 0)
		printf("fuck");
	line = get_next_line(fd);
	game->height = 0;
	game->width = (int)ft_strlen(line) - 1; //줄바꿈 제외
	game->map_str=ft_strnndup(line,game->width); //줄바꿈 제외 한줄 갖다박아
	free(line);
	while(line)
	{
		game->height ++;
		line = get_next_line(fd);
		if(line)
		{
			line = ft_strnndup(line,ft_strlen(line) - 1);
			game->map_str=ft_strjoin_free(game->map_str,line);
		}
	}
	close(fd);
}

void map_init(t_game_attribute *game)
{
	int wid;
	int hei;

	wid = game->width * 16;
	hei = game->height * 16;
	game->win = mlx_new_window(game->mlx, wid, hei, "mlx_project");
}

void render_map(t_game_attribute *g)
{
	int wid;
	int hei;

	hei = 0;
	while (hei < g->height)
	{
		wid = 0;
		while(wid < g->width)
		{
			if (g->map_str[hei * g->width + wid] == '1')
				mlx_put_image_to_window(g->mlx, g->win, g->img.wall, wid * 16, hei * 16);
			else if (g->map_str[hei * g->width + wid] == '0')
				mlx_put_image_to_window(g->mlx, g->win, g->img.grass, wid * 16, hei * 16);
			else if (g->map_str[hei * g->width + wid] == 'P')
				mlx_put_image_to_window(g->mlx, g->win, g->img.player, wid * 16, hei * 16);
			else if (g->map_str[hei * g->width + wid] == 'C')
				mlx_put_image_to_window(g->mlx, g->win, g->img.box, wid * 16, hei * 16);
			wid ++;
		}
		hei ++;
	}
}
