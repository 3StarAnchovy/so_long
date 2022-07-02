/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihong <jihong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 18:48:18 by jihong            #+#    #+#             */
/*   Updated: 2022/07/02 15:56:00 by jihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_massage(char *err)
{
	write(1, err, ft_strlen(err));
	exit(0);
}

void	game_init(t_game_attribute *attribute, char *map_name)
{
	attribute->mlx = mlx_init();
	attribute->img = image_init(attribute->mlx);
	read_map(map_name, attribute);
	check_all_exception(attribute);
	map_init(attribute);
	render_map(attribute);
}

int	exit_game(t_game_attribute *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

int	press_key(int key, t_game_attribute *game)
{
	if (key == KEY_ESC)
		exit_game(game);
	if (key == KEY_W)
		move_w(game);
	if (key == KEY_A)
		move_a(game);
	if (key == KEY_D)
		move_d(game);
	if (key == KEY_S)
		move_s(game);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_game_attribute	*attribute;

	if (argc < 2)
		return (error_massage("Check input!"), 0);
	attribute = malloc(sizeof(t_game_attribute));
	if (attribute == NULL)
		return (0);
	game_init(attribute, argv[1]);
	mlx_hook(attribute->win, X_EVENT_KEY_PRESS, 0, &press_key, attribute);
	mlx_hook(attribute->win, X_EVENT_KEY_EXIT, 0, &exit_game, attribute);
	mlx_loop(attribute->mlx);
}
