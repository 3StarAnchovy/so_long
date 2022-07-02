/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihong <jihong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 19:37:18 by jihong            #+#    #+#             */
/*   Updated: 2022/07/02 15:47:40 by jihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img_attribute	image_init(void *mlx)
{
	t_img_attribute	img;
	int				w;
	int				h;

	img.box = mlx_xpm_file_to_image(mlx, "./images/box.xpm", &w, &h);
	img.grass = mlx_xpm_file_to_image(mlx, "./images/grass.xpm", &w, &h);
	img.player = mlx_xpm_file_to_image(mlx, "./images/player.xpm", &w, &h);
	img.wall = mlx_xpm_file_to_image(mlx, "./images/wall.xpm", &w, &h);
	return (img);
}
