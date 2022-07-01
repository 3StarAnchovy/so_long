/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihong <jihong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 18:48:18 by jihong            #+#    #+#             */
/*   Updated: 2022/06/30 20:08:19 by jihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_massage(char *err)
{
	write(1, err, ft_strlen(err));
}

void game_init(t_game_attribute *attribute)
{
	attribute -> mlx = mlx_init();
	attribute -> img = image_init(attribute -> mlx);
}

int main(int argc, char *argv[])
{
	t_game_attribute	*attribute;

	if (argc < 2)
		return (error_massage("Check input!"),0);
	attribute = malloc(sizeof(t_game_attribute));
	if (attribute == NULL)
		return (0);
	game_init(attribute);
	attribute -> win = mlx_new_window(attribute -> mlx, 500, 500, "mlx_project");
	mlx_put_image_to_window(attribute->mlx,attribute->win,attribute->img.box,0,0);
	mlx_loop(attribute->mlx);

}
