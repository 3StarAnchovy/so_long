/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihong <jihong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 18:48:18 by jihong            #+#    #+#             */
/*   Updated: 2022/06/29 19:14:06 by jihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_massage()
{
	write(1, "check input!", 13);
}

int main(int argc, char *argv[])
{
	t_game_attribute	*attribute;
	void	*mlx;
	void	*win;

	if (argc < 2)
		return (error_massage(),0);
	attribute = (t_game_attribute *)malloc(sizeof(t_game_attribute));
	if (attribute == NULL)
		return (0);
	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "mlx_project");
	mlx_loop(mlx);

}
