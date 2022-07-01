/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihong <jihong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 18:48:52 by jihong            #+#    #+#             */
/*   Updated: 2022/06/30 23:18:11 by jihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //지워야함
#include <fcntl.h>
#include "mlx/mlx.h"
#include "libft/libft.h"
#include <stdlib.h>
#include <unistd.h>

typedef struct s_img_attribute
{
	void *box;
	void *grass;
	void *player;
	void *wall;
}	t_img_attribute;
typedef struct s_game_attribute
{
	void	*mlx;
	void	*win;
	int		walk_cnt;
	t_img_attribute img;
}	t_game_attribute;

t_img_attribute image_init(void *mlx);

