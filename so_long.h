/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihong <jihong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 18:48:52 by jihong            #+#    #+#             */
/*   Updated: 2022/06/29 19:15:30 by jihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //지워야함
#include "mlx/mlx.h"
#include <stdlib.h>
#include <unistd.h>

typedef struct s_game_attribute
{
	void	*mlx;
	void	*win;
	int		walk_cnt;
}	t_game_attribute;

typedef struct s_map_attribute
{
	/* data */
}	t_map_attribute;

