/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihong <jihong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 18:48:52 by jihong            #+#    #+#             */
/*   Updated: 2022/07/01 18:06:49 by jihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //지워야함
#include <fcntl.h>
#include "mlx/mlx.h"
#include "libft/libft.h"
#include "libft/get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

# define X_EVENT_KEY_PRESS			2
# define X_EVENT_KEY_RELEASE		3
# define X_EVENT_KEY_EXIT		17
# define KEY_ESC		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2


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
	int		width;
	int		height;
	char	*map_str;
	t_img_attribute img;
}	t_game_attribute;

t_img_attribute image_init(void *mlx);
void read_map(char *name, t_game_attribute *game);
void map_init(t_game_attribute *game);
void render_map(t_game_attribute *g);

