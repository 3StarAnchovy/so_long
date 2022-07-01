/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihong <jihong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 19:37:18 by jihong            #+#    #+#             */
/*   Updated: 2022/06/30 19:53:00 by jihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img_attribute image_init(void *mlx)
{
	t_img_attribute img;
	int	width;
	int height;

	img.box = mlx_xpm_file_to_image(mlx,"./images/box.xpm",&width,&height);
	img.grass = mlx_xpm_file_to_image(mlx,"./images/grass.xpm",&width,&height);
	img.player = mlx_xpm_file_to_image(mlx,"./images/player.xpm",&width,&height);
	img.wall = mlx_xpm_file_to_image(mlx,"./images/wall.xpm",&width,&height);

	return (img);
}
