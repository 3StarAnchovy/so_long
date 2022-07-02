/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihong <jihong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 18:48:52 by jihong            #+#    #+#             */
/*   Updated: 2022/07/02 16:20:39 by jihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include "mlx/mlx.h"
# include "libft/libft.h"
# include "libft/get_next_line.h"
# include <stdlib.h>
# include <unistd.h>

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
	void	*box;
	void	*grass;
	void	*player;
	void	*wall;
}	t_img_attribute;

typedef struct s_game_attribute
{
	void			*mlx;
	void			*win;
	int				walk_cnt;
	int				col_have;
	int				col;
	int				width;
	int				height;
	char			*map_str;
	t_img_attribute	img;
}				t_game_attribute;

t_img_attribute	image_init(void *mlx);
void			read_map(char *name, t_game_attribute *game);
void			map_init(t_game_attribute *game);
void			render_map(t_game_attribute *g);

void			clear_game(t_game_attribute *game);
void			move_w(t_game_attribute *g);
void			move_a(t_game_attribute *g);
void			move_d(t_game_attribute *g);
void			move_s(t_game_attribute *g);

void			error_massage(char *err);

void			check_all_exception(t_game_attribute *game);

#endif
